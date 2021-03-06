#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "Token.h"
#include "TokenType.h"

class Scanner
{
  static std::unordered_map<std::string, TokenType> keywords;
  const std::string source;
  std::vector<Token> tokens{};
  unsigned start{0};
  unsigned current{0};
  unsigned line{1};

  bool isAtEnd();
  void scanToken();
  char advance();
  void addToken(TokenType type);
  void addToken(TokenType type, std::string literal);
  void addToken(TokenType type, double literal);
  bool match(char expected);
  char peek();
  char peekNext();
  void consumeUntil(char end);
  void string();
  void number();
  void identifier();

public:
  Scanner(std::string source);
  std::vector<Token> scanTokens();
};
