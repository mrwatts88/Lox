#include "Token.h"
#include <string>
#include <iostream>

Token::Token(TokenType type, std::string lexeme, std::string strLiteral, unsigned line)
    : type{type}, lexeme{lexeme}, literalType{LiteralType::STRING}, line{line}
{
  this->strLiteral = new std::string{strLiteral};
}

Token::Token(TokenType type, std::string lexeme, double numLiteral, unsigned line)
    : type{type}, lexeme{lexeme}, literalType{LiteralType::NUMBER}, line{line}
{
  this->numLiteral = new double{numLiteral};
}

Token::Token(TokenType type, std::string lexeme, unsigned line)
    : type{type}, lexeme{lexeme}, literalType{LiteralType::NONE}, line{line} {}

Token::Token(const Token &token)
    : type{token.type}, lexeme{token.lexeme}, literalType{token.literalType}, line{token.line}
{
  if (token.strLiteral != nullptr)
  {
    std::string *copy = new std::string{*(token.strLiteral)};
    strLiteral = copy;
  }

  if (token.numLiteral != nullptr)
  {
    double *copy = new double{*(token.numLiteral)};
    numLiteral = copy;
  }
}

Token::Token(Token &&token)
    : type{token.type}, lexeme{token.lexeme}, literalType{token.literalType}, line{token.line}
{
  strLiteral = token.strLiteral;
  numLiteral = token.numLiteral;
  token.strLiteral = nullptr;
  token.numLiteral = nullptr;
}

Token &Token::operator=(const Token &token)
{
  type = token.type;
  lexeme = token.lexeme;
  literalType = token.literalType;
  line = token.line;

  if (token.strLiteral != nullptr)
  {
    std::string *copy = new std::string{*(token.strLiteral)};
    strLiteral = copy;
  }

  if (token.numLiteral != nullptr)
  {
    double *copy = new double{*(token.numLiteral)};
    numLiteral = copy;
  }

  return *this;
}

Token::~Token()
{
  delete strLiteral;
  delete numLiteral;
}

std::string Token::toString()
{
  std::string s = type._to_string();

  std::string literal{};
  switch (literalType)
  {
  case LiteralType::NONE:
    literal = "";
    break;
  case LiteralType::NUMBER:
    literal = std::to_string(*numLiteral);
    break;
  case LiteralType::STRING:
    literal = *strLiteral;
    break;
  default:
    literal = "";
    break;
  }

  return s + " " + lexeme + " " + literal;
}

std::ostream &operator<<(std::ostream &out, Token &token)
{
  out << token.toString();
  return out;
}