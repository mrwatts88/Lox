#pragma once

#include <vector>
#include "Token.h"
#include "Visitor.h"

class Visitor;

class Expr
{
public:
  virtual std::string accept(Visitor *visitor);
  virtual ~Expr();
};

class Binary : public Expr
{
  const Expr left;
  const Token op;
  const Expr right;

public:
  Binary(Expr left, Token op, Expr right);
  std::string accept(Visitor *visitor) override;
};

class Assign : public Expr
{
  const Token name;
  const Expr value;

public:
  Assign(Token name, Expr value);
  std::string accept(Visitor *visitor) override;
};

class Call : public Expr
{
  const Expr callee;
  const Token paren;
  const std::vector<Expr> arguments;

public:
  Call(Expr callee, Token paren, std::vector<Expr> arguments);
  std::string accept(Visitor *visitor) override;
};

class Get : public Expr
{
  const Expr object;
  const Token name;

public:
  Get(Expr object, Token name);
  std::string accept(Visitor *visitor) override;
};

class Grouping : public Expr
{
  const Expr expression;

public:
  Grouping(Expr expression);
  std::string accept(Visitor *visitor) override;
};

class Literal : public Expr
{
  // todo extend to handle all literal types
public:
  Literal();
  std::string accept(Visitor *visitor) override;
};

class Logical : public Expr
{
  const Expr left;
  const Token op;
  const Expr right;

public:
  Logical(Expr left, Token op, Expr right);
  std::string accept(Visitor *visitor) override;
};

class Set : public Expr
{
  const Expr object;
  const Token name;
  const Expr value;

public:
  Set(Expr object, Token name, Expr value);
  std::string accept(Visitor *visitor) override;
};

class Super : public Expr
{
  const Token keyword;
  const Token method;

public:
  Super(Token keyword, Token method);
  std::string accept(Visitor *visitor) override;
};

class This : public Expr
{
  const Token keyword;

public:
  This(Token keyword);
  std::string accept(Visitor *visitor) override;
};

class Unary : public Expr
{
  const Token op;
  const Expr right;

public:
  Unary(Token op, Expr right);
  std::string accept(Visitor *visitor) override;
};

class Variable : public Expr
{
  const Token name;

public:
  Variable(Token name);
  std::string accept(Visitor *visitor) override;
};
