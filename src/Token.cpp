#include "Token.h"
#include <string>

Token::Token(TokenType type, std::string lexeme, std::string literal, unsigned line)
    : type{type}, lexeme{lexeme}, literal{literal}, line{line} {}

std::string Token::toString()
{
  std::string s = type._to_string();
  return s + " " + lexeme + " " + literal;
}

std::ostream &operator<<(std::ostream &out, Token &token)
{
  out << token.toString();
  return out;
}