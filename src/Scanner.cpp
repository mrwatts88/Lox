#include "Scanner.h"
#include <string>
#include <iostream>
#include <vector>
#include "TokenType.h"
#include "ErrorHandler.h"
#include <unordered_map>

Scanner::Scanner(std::string source) : source{source} {}

std::vector<Token> Scanner::scanTokens()
{
  while (!isAtEnd())
  {
    start = current;
    scanToken();
  }

  tokens.emplace_back(Token{TokenType::EOFF, "EOF", line});
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
  case '/':
    if (match('/'))
    {
      // we found a comment
      consumeUntil('\n');
    }
    else
    {
      addToken(TokenType::SLASH);
    }
  case ' ':
  case '\r':
  case '\t':
    // Ignore whitespace.
    break;
  case '\n':
    line++;
    break;
  case '"':
    string();
    break;
  default:
    if (isdigit(c))
    {
      number();
    }
    else if (isalpha(c))
    {
      identifier();
    }
    else
    {
      ErrorHandler::error(line, "Unexpected character");
    }
    break;
  }
}

void Scanner::addToken(TokenType type)
{
  std::string lexeme = source.substr(start, current - start);
  tokens.emplace_back(Token{type, lexeme, line});
}

void Scanner::addToken(TokenType type, std::string literal)
{
  std::string lexeme = source.substr(start, current - start);
  tokens.emplace_back(Token{type, lexeme, literal, line});
}

void Scanner::addToken(TokenType type, double literal)
{
  std::string lexeme = source.substr(start, current - start);
  tokens.emplace_back(Token{type, lexeme, literal, line});
}

char Scanner::advance()
{
  return source.at(current++);
}

char Scanner::peek()
{
  if (isAtEnd())
    return '\0';
  return source.at(current);
}

char Scanner::peekNext()
{
  if (current + 1 >= source.length())
    return '\0';
  return source.at(current + 1);
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

void Scanner::consumeUntil(char end)
{
  while (peek() != end && !isAtEnd())
    advance();
}

void Scanner::string()
{
  while (peek() != '"' && !isAtEnd())
  {
    if (peek() == '\n')
      line++;
    advance();
  }

  if (isAtEnd())
  {
    ErrorHandler::error(line, "Unterminated string.");
    return;
  }

  advance(); // Move past the closing ";

  std::string value = source.substr(start + 1, current - start - 2);
  addToken(TokenType::STRING, value);
}

void Scanner::number()
{
  while (isdigit(peek()))
    advance();

  if (peek() == '.' && isdigit(peekNext()))
  {
    advance();

    while (isdigit(peek()))
      advance();
  }

  addToken(TokenType::NUMBER, std::stod(source.substr(start, current - start)));
}

void Scanner::identifier()
{
  while (isalpha(peek()) || isdigit(peek()))
    advance();

  std::string lexeme = source.substr(start, current - start);

  std::unordered_map<std::string, TokenType>::const_iterator typeIter = Scanner::keywords.find(lexeme);

  if (typeIter == keywords.end())
    addToken(TokenType::IDENTIFIER);
  else
    addToken(typeIter->second);
}

std::unordered_map<std::string, TokenType> Scanner::keywords = {
    {"and", TokenType::AND},
    {"class", TokenType::CLASS},
    {"else", TokenType::ELSE},
    {"false", TokenType::FALSE},
    {"for", TokenType::FOR},
    {"fun", TokenType::FUN},
    {"if", TokenType::IF},
    {"nil", TokenType::NIL},
    {"or", TokenType::OR},
    {"print", TokenType::PRINT},
    {"return", TokenType::RETURN},
    {"super", TokenType::SUPER},
    {"this", TokenType::THIS},
    {"true", TokenType::TRUE},
    {"var", TokenType::VAR},
    {"while", TokenType::WHILE},
};