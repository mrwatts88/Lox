#include <string>
#include <vector>
#include "Token.h"

class Scanner
{
  const std::string source;
  const std::vector<Token> tokens;

  Scanner(std::string);
};
