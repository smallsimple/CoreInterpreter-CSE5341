#ifndef OP_H
#define OP_H

#include"Tokenizer.h"
#include"Inte.h"
#include"Id.h"
#include"Expr.h"

class Expr;

class Op{
 private:
  Inte *inte;
  Id *id;
  Expr *expr;
  int alterId;
 public:
  Op();
  void PrintOp();
  int EvalOp();
  void ParseOp();
};

#endif
