#include "Token.h"
#include <string>

Token::Token(TokenType type, std::string lexeme, std::string literal, int line)
    : type{type}, lexeme{lexeme}, literal{literal}, line{line} {}

std::string Token::toString()
{
  std::string s = type._to_string();
  return s + " " + lexeme + " " + literal;
}