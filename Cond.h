#ifndef COND_H
#define COND_H

#include"Tokenizer.h"
#include"Comp.h"

class Cond{
 private:
  Comp *comp;
  Cond *cond1, *cond2;
  int alterId;
 public:
  Cond();
  void PrintCond();
  bool EvalCond();
  void ParseCond();
};

#endif
