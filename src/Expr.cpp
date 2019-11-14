#include "Expr.h"
#include "Token.h"

std::string Binary::accept(Visitor *visitor) { return visitor->visitBinaryExpr(*this); }
std::string Assign::accept(Visitor *visitor) { return visitor->visitAssignExpr(*this); }
std::string Call::accept(Visitor *visitor) { return visitor->visitCallExpr(*this); }
std::string Get::accept(Visitor *visitor) { return visitor->visitGetExpr(*this); }
std::string Grouping::accept(Visitor *visitor) { return visitor->visitGroupingExpr(*this); }
std::string Literal::accept(Visitor *visitor) { return visitor->visitLiteralExpr(*this); }
std::string Logical::accept(Visitor *visitor) { return visitor->visitLogicalExpr(*this); }
std::string Set::accept(Visitor *visitor) { return visitor->visitSetExpr(*this); }
std::string Super::accept(Visitor *visitor) { return visitor->visitSuperExpr(*this); }
std::string This::accept(Visitor *visitor) { return visitor->visitThisExpr(*this); }
std::string Unary::accept(Visitor *visitor) { return visitor->visitUnaryExpr(*this); }
std::string Variable::accept(Visitor *visitor) { return visitor->visitVariableExpr(*this); }

Expr::~Expr() {}

Binary::Binary(Expr left, Token op, Expr right)
    : left{left}, op{op}, right{right} {}

Assign::Assign(Token name, Expr value)
    : name{name}, value{value} {}

Call::Call(Expr callee, Token paren, std::vector<Expr> arguments)
    : callee{callee}, paren{paren}, arguments{arguments} {}

Get::Get(Expr object, Token name)
    : object{object}, name{name} {}

Grouping::Grouping(Expr expression)
    : expression{expression} {}

Literal::Literal() {}

Logical::Logical(Expr left, Token op, Expr right)
    : left{left}, op{op}, right{right} {}

Set::Set(Expr object, Token name, Expr value)
    : object{object}, name{name}, value{value} {}

Super::Super(Token keyword, Token method)
    : keyword{keyword}, method{method} {}

This::This(Token keyword)
    : keyword{keyword} {}

Unary::Unary(Token op, Expr right)
    : op{op}, right{right} {}

Variable::Variable(Token name)
    : name{name} {}
