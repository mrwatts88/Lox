#include <string>
#include <vector>
#include <iostream>
#include <sysexits.h>
#include <fstream>
#include <sstream>
#include "Scanner.h"
#include "Token.h"
#include "ErrorHandler.h"

void runFile(std::string);
void runPrompt();
void run(std::string);

int main(int argc, char **argv)
{
  if (argc > 2)
  {
    std::cout << "Usage: jlox [script]" << std::endl;
    return EX_USAGE;
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
  std::ifstream ifs(path, std::ifstream::in);
  std::stringstream buffer;
  buffer << ifs.rdbuf();
  run(buffer.str());

  if (ErrorHandler::hadError)
    exit(EX_DATAERR);
}

void runPrompt()
{
  std::string line;

  for (;;)
  {
    std::cout << "> ";
    getline(std::cin, line);
    run(line);
    ErrorHandler::hadError = false;
  }
}

void run(std::string source)
{
  Scanner *scanner = new Scanner(source);
  std::vector<Token *> tokens = scanner->scanTokens();

  for (auto token : tokens)
  {
    std::cout << "token: " << *token << std::endl;
    delete token;
  }

  delete scanner;
}
