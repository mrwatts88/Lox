#pragma once

#include <string>
#include <vector>
#include "Token.h"

class Scanner
{
  const std::string source;
  std::vector<Token> tokens;
  unsigned start{0};
  unsigned current{0};
  unsigned line{1};

  bool isAtEnd();
  void scanToken();
  char advance();
  void addToken(TokenType type);
  void addToken(TokenType type, std::string literal);
  bool match(char expected);

public:
  Scanner(std::string source);
  std::vector<Token> scanTokens();
};