#include <string>
#include "TokenType.h"

class Token
{
  const TokenType type;
  const std::string lexeme;
  const std::string literal;
  const int line;

  Token(TokenType type, std::string lexeme, std::string literal, int line);

public:
  std::string toString();
};
