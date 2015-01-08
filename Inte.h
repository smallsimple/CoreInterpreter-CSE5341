#ifndef INTE_H
#define INTE_H

#include"Tokenizer.h"

class Inte{
 private:
  string name;
  int value;
 public:
  Inte();
  void PrintInte();
  int EvalInte();
  void ParseInte();
};

#endif
