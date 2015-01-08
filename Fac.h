#ifndef FAC_H
#define FAC_H

#include"Tokenizer.h"
#include"Op.h"

class Op;

class Fac{
 private:
  Op *op;
  Fac *fac;
 public:
  Fac();
  void PrintFac();
  int EvalFac();
  void ParseFac();
};

#endif
