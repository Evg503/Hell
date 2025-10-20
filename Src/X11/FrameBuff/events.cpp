#include <X11/Xlib.h>
#include <stdio.h>

int main() {
    Display *display;
    Window window;
    XEvent event;

    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Cannot open display\n");
        return 1;
    }

    window = XCreateSimpleWindow(display, DefaultRootWindow(display), 0, 0, 200, 200, 0,
                                 BlackPixel(display, DefaultScreen(display)),
                                 WhitePixel(display, DefaultScreen(display)));

    // Select desired events
    XSelectInput(display, window, KeyPressMask | ButtonPressMask | PointerMotionMask);

    XMapWindow(display, window);

    while (1) {
        XNextEvent(display, &event);

        switch (event.type) {
            case KeyPress:
                printf("Key pressed: %d\n", event.xkey.keycode);
                break;
            case ButtonPress:
                printf("Mouse button pressed: %d\n", event.xbutton.button);
                break;
            case MotionNotify:
                printf("Mouse moved to: (%d, %d)\n", event.xmotion.x, event.xmotion.y);
                break;
        }
    }

    XCloseDisplay(display);
    return 0;
}