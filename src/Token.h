#pragma once

#pragma once

#include <string>
#include "TokenType.h"

class Token
{
  TokenType type;
  std::string lexeme;
  std::string *strLiteral{nullptr};
  double *numLiteral{nullptr};
  LiteralType literalType;
  unsigned line;

public:
  Token(TokenType type, std::string lexeme, std::string strLiteral, unsigned line);
  Token(TokenType type, std::string lexeme, double numLiteral, unsigned line);
  Token(TokenType type, std::string lexeme, unsigned line);
  Token(const Token &token);

  Token &operator=(const Token &rhs);
  friend std::ostream &operator<<(std::ostream &out, Token &token);

  std::string toString();

  ~Token();
};
