#pragma once

#include <vector>
#include "Token.h"
#include "Visitor.h"

class Expr
{
public:
  // virtual R accept(Visitor<R> visitor) = 0;
};

class Binary : public Expr
{
  const Expr left;
  const Token op;
  const Expr right;

public:
  Binary(Expr left, Token op, Expr right);
};

class Assign : public Expr
{
  const Token name;
  const Expr value;

public:
  Assign(Token name, Expr value);
};

class Call : public Expr
{
  const Expr callee;
  const Token paren;
  const std::vector<Expr> arguments;

public:
  Call(Expr callee, Token paren, std::vector<Expr> arguments);
};

class Get : public Expr
{
  const Expr object;
  const Token name;

public:
  Get(Expr object, Token name);
};

class Grouping : public Expr
{
  const Expr expression;

  Grouping(Expr expression);
};

class Literal : public Expr
{
  // todo extend to handle all literal types
  Literal();
};

class Logical : public Expr
{
  const Expr left;
  const Token op;
  const Expr right;

public:
  Logical(Expr left, Token op, Expr right);
};

class Set : public Expr
{
  const Expr object;
  const Token name;
  const Expr value;

  Set(Expr object, Token name, Expr value);
};

class Super : public Expr
{
  const Token keyword;
  const Token method;

  Super(Token keyword, Token method);
};

class This : public Expr
{
  const Token keyword;

  This(Token keyword);
};

class Unary : public Expr
{
  const Token op;
  const Expr right;

  Unary(Token op, Expr right);
};

class Variable : public Expr
{
  const Token name;

  Variable(Token name);
};
