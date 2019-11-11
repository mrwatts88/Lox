template <typename R>
class Visitor
{
public:
  R visitAssignExpr(Assign expr) = 0;
  R visitBinaryExpr(Binary expr) = 0;
  R visitCallExpr(Call expr) = 0;
  R visitGetExpr(Get expr) = 0;
  R visitGroupingExpr(Grouping expr) = 0;
  R visitLiteralExpr(Literal expr) = 0;
  R visitLogicalExpr(Logical expr) = 0;
  R visitSetExpr(Set expr) = 0;
  R visitSuperExpr(Super expr) = 0;
  R visitThisExpr(This expr) = 0;
  R visitUnaryExpr(Unary expr) = 0;
  R visitVariableExpr(Variable expr) = 0;
};
