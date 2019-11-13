#pragma once

#include "Visitor.h"
#include <string>
#include "Expr.h"

class AstPrinter : Visitor<std::string>
{
public:
  std::string visitAssignExpr(Assign expr) override;
  std::string visitBinaryExpr(Binary expr) override;
  std::string visitCallExpr(Call expr) override;
  std::string visitGetExpr(Get expr) override;
  std::string visitGroupingExpr(Grouping expr) override;
  std::string visitLiteralExpr(Literal expr) override;
  std::string visitLogicalExpr(Logical expr) override;
  std::string visitSetExpr(Set expr) override;
  std::string visitSuperExpr(Super expr) override;
  std::string visitThisExpr(This expr) override;
  std::string visitUnaryExpr(Unary expr) override;
  std::string visitVariableExpr(Variable expr) override;
};
