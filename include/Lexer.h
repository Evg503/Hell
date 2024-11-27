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

inline Lexer::Lexer(/* args */)
{
}

inline Lexer::~Lexer()
{
}

inline Lexer::Iterator Lexer::begin()
{
    return Lexer::Iterator();
}

inline Lexer::Iterator Lexer::end()
{
    return Iterator();
}
