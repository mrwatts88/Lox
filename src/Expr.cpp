#include "Expr.h"
#include "Token.h"

// void Expr::accept(Visitor<R> visitor)
// {
// }

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
