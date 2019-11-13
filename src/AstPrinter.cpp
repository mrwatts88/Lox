#include "AstPrinter.h"

std::string AstPrinter::visitBinaryExpr(Binary expr) { return "in visit binary"; }
std::string AstPrinter::visitAssignExpr(Assign expr) { return "in visit assign"; };
std::string AstPrinter::visitCallExpr(Call expr) { return "in visit call"; };
std::string AstPrinter::visitGetExpr(Get expr) { return "in visit get"; };
std::string AstPrinter::visitGroupingExpr(Grouping expr) { return "in visit grouping"; };
std::string AstPrinter::visitLiteralExpr(Literal expr) { return "in visit literal"; };
std::string AstPrinter::visitLogicalExpr(Logical expr) { return "in visit logical"; };
std::string AstPrinter::visitSetExpr(Set expr) { return "in visit set"; };
std::string AstPrinter::visitSuperExpr(Super expr) { return "in visit super"; };
std::string AstPrinter::visitThisExpr(This expr) { return "in visit this"; };
std::string AstPrinter::visitUnaryExpr(Unary expr) { return "in visit unary"; };
std::string AstPrinter::visitVariableExpr(Variable expr) { return "in visit variable"; };
