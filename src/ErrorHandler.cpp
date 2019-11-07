#include <string>
#include <iostream>
#include "ErrorHandler.h"

bool ErrorHandler::hadError = false;

void ErrorHandler::report(unsigned line, std::string where, std::string message)
{
  std::cout << "[line " << line << "] Error" << where << ": " << message << std::endl;
  hadError = true;
}

void ErrorHandler::error(unsigned line, std::string message)
{
  report(line, "", message);
}
