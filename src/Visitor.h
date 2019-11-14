#pragma once

#include "Expr.h"

class Assign;
class Binary;
class Call;
class Get;
class Grouping;
class Literal;
class Logical;
class Set;
class Super;
class This;
class Unary;
class Variable;

class Visitor
{
public:
  virtual std::string visitAssignExpr(Assign expr) = 0;
  virtual std::string visitBinaryExpr(Binary expr) = 0;
  virtual std::string visitCallExpr(Call expr) = 0;
  virtual std::string visitGetExpr(Get expr) = 0;
  virtual std::string visitGroupingExpr(Grouping expr) = 0;
  virtual std::string visitLiteralExpr(Literal expr) = 0;
  virtual std::string visitLogicalExpr(Logical expr) = 0;
  virtual std::string visitSetExpr(Set expr) = 0;
  virtual std::string visitSuperExpr(Super expr) = 0;
  virtual std::string visitThisExpr(This expr) = 0;
  virtual std::string visitUnaryExpr(Unary expr) = 0;
  virtual std::string visitVariableExpr(Variable expr) = 0;
};
