#ifndef ASSIGN_H
#define ASSIGN_H

#include"Tokenizer.h"
#include"Id.h"
#include"Expr.h"

class Assign{
 private:
  Id *id;
  Expr *expr;
 public:
  Assign();
  void PrintAssign(int);
  void ExecAssign();
  void ParseAssign();
};

#endif
