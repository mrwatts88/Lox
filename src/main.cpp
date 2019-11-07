#include <string>
#include <vector>
#include <iostream>
#include "Scanner.h"
#include "Token.h"

void runFile(std::string);
void runPrompt();
void run(std::string);

int main(int argc, char **argv)
{
  if (argc > 2)
  {
    std::cout << "Usage: jlox [script]" << std::endl;
    return 64;
  }
  else if (argc == 2)
  {
    runFile(std::string{argv[1]});
  }
  else
  {
    runPrompt();
  }
}

void runFile(std::string path)
{
  std::cout << path << std::endl;
}

void runPrompt()
{
  std::string line;

  for (;;)
  {
    std::cout << "> ";
    getline(std::cin, line);
    run(line);
  }
}

void run(std::string source)
{
  Scanner *scanner = new Scanner(source);
  std::vector<Token> tokens = scanner->scanTokens();

  for (auto token : tokens)
  {
    std::cout << "token: " << token << std::endl;
  }

  delete scanner;
}