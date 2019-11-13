#pragma once

#include "Expr.h"

template <typename R>
class Visitor
{
public:
  virtual R visitAssignExpr(Assign expr) = 0;
  virtual R visitBinaryExpr(Binary expr) = 0;
  virtual R visitCallExpr(Call expr) = 0;
  virtual R visitGetExpr(Get expr) = 0;
  virtual R visitGroupingExpr(Grouping expr) = 0;
  virtual R visitLiteralExpr(Literal expr) = 0;
  virtual R visitLogicalExpr(Logical expr) = 0;
  virtual R visitSetExpr(Set expr) = 0;
  virtual R visitSuperExpr(Super expr) = 0;
  virtual R visitThisExpr(This expr) = 0;
  virtual R visitUnaryExpr(Unary expr) = 0;
  virtual R visitVariableExpr(Variable expr) = 0;
};
