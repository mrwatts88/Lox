#pragma once

#include <string>
#include "TokenType.h"

class Token
{
  const TokenType type;
  const std::string lexeme;
  const std::string literal;
  const unsigned line;

public:
  Token(TokenType type, std::string lexeme, std::string literal, unsigned line);
  std::string toString();
  friend std::ostream &operator<<(std::ostream &out, Token &token);
};
