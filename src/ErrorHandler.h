#pragma once

#include <string>

class ErrorHandler
{
public:
  static bool hadError;

  static void error(unsigned line, std::string message);
  static void report(unsigned line, std::string where, std::string message);
};
