#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fb_fd;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize;
    char *fbp = 0;

    // Open the framebuffer device
    fb_fd = open("/dev/fb0", O_RDWR);
    if (fb_fd == -1) {
        perror("Error opening framebuffer device");
        return 1;
    }

    // Get fixed screen information
    if (ioctl(fb_fd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        return 1;
    }

    // Get variable screen information
    if (ioctl(fb_fd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        return 1;
    }

    printf("Screen resolution: %dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Calculate screen size in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // Map the device to memory
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fb_fd, 0);
    if ((long int)fbp == -1) {
        perror("Error mmapping the framebuffer device");
        return 1;
    }

    // Example: Fill a rectangle with a color (replace with actual image data)
    int x, y;
    for (y = 100; y < 200; y++) {
        for (x = 100; x < 300; x++) {
            long int location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) +
                                (y + vinfo.yoffset) * finfo.line_length;
            if (vinfo.bits_per_pixel == 32) {
                *(unsigned int *)(fbp + location) = 0xFF0000FF; // ARGB (Blue)
            } else if (vinfo.bits_per_pixel == 16) { // Handle other pixel formats as needed
                *(unsigned short *)(fbp + location) = 0x00FF; // A?RGB (Yellow)            }
	    }
        }
    }

    // Unmap and close
    munmap(fbp, screensize);
    close(fb_fd);
    return 0;
}