#include <gtest/gtest.h>

#include <Lexer.h>

TEST(baseSuite, test0)
{
	Lexer lexer;
	for(auto lex:lexer){
		EXPECT_FALSE("unxepected out");
	}
	EXPECT_TRUE(true);
}
