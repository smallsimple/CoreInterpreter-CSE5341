#ifndef EXPR_H
#define EXPR_H

#include"Tokenizer.h"
#include"Fac.h"

class Fac;

class Expr{
 private:
  Fac *fac;
  Expr *expr;
  int alterId;
 public:
  Expr();
  void PrintExpr();
  int EvalExpr();
  void ParseExpr();
};

#endif
