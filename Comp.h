#ifndef COMP_H
#define COMP_H

#include"Tokenizer.h"
#include"Op.h"

class Comp{
 private:
  Op *op1, *op2;
  int alterId;
 public:
  Comp();
  void PrintComp();
  bool EvalComp();
  void ParseComp();
};

#endif
