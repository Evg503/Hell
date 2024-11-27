#pragma once

class Lexer
{
public:
    using Iterator=char*;
    Lexer();
    ~Lexer();

    Iterator begin();
    Iterator end();

private:
    /* data */
};
