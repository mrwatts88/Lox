#pragma once

#include <string>
#include "TokenType.h"

class Token
{
  const TokenType type;
  const std::string lexeme;
  std::string *strLiteral{nullptr};
  double *numLiteral{nullptr};
  const LiteralType literalType;
  const unsigned line;

public:
  Token(TokenType type, std::string lexeme, std::string strLiteral, unsigned line);
  Token(TokenType type, std::string lexeme, double numLiteral, unsigned line);
  Token(TokenType type, std::string lexeme, unsigned line);
  ~Token();
  std::string toString();
  friend std::ostream &operator<<(std::ostream &out, Token &token);
};
