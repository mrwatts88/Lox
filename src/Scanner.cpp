#include "Scanner.h"
#include <string>
#include <iostream>
#include <vector>
#include "TokenType.h"

Scanner::Scanner(std::string source) : source{source} {}

std::vector<Token> Scanner::scanTokens()
{
  while (!isAtEnd())
  {
    start = current;
    scanToken();
  }

  Token token{TokenType::EOFF, "", "", line};
  tokens.push_back(token);
  return tokens;
}

bool Scanner::isAtEnd()
{
  return current >= source.size();
}

void Scanner::scanToken()
{
  char c = advance();
  switch (c)
  {
  case '(':
    addToken(TokenType::LEFT_PAREN);
    break;
  case ')':
    addToken(TokenType::RIGHT_PAREN);
    break;
  case '{':
    addToken(TokenType::LEFT_BRACE);
    break;
  case '}':
    addToken(TokenType::RIGHT_BRACE);
    break;
  case ',':
    addToken(TokenType::COMMA);
    break;
  case '.':
    addToken(TokenType::DOT);
    break;
  case '-':
    addToken(TokenType::MINUS);
    break;
  case '+':
    addToken(TokenType::PLUS);
    break;
  case ';':
    addToken(TokenType::SEMICOLON);
    break;
  case '*':
    addToken(TokenType::STAR);
    break;
  case '!':
    addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
    break;
  case '=':
    addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
    break;
  case '<':
    addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
    break;
  case '>':
    addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
    break;
  default:
    break;
  }
}

char Scanner::advance()
{
  return source.at(current++);
}

void Scanner::addToken(TokenType type)
{
  addToken(type, "");
}

void Scanner::addToken(TokenType type, std::string literal)
{
  std::string text = source.substr(start, current - start);
  tokens.emplace_back(Token{type, text, literal, line});
}

bool Scanner::match(char expected)
{
  if (isAtEnd())
    return false;
  if (source.at(current) != expected)
    return false;

  current++;
  return true;
}
