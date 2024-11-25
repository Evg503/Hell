#include <Lexer.h>

void test0()
{
	Lexer lexer("");
	for(auto lex:lexer){
		ASSERTFAIL("unxepected out");
	}
	ASSERTSUCCESS();
}
