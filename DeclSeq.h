#ifndef DECLSEQ_H
#define DECLSEQ_H

#include"Tokenizer.h"
#include"Decl.h"

class DeclSeq{
 private:
  Decl *decl;
  DeclSeq *declSeq;
 public:
  DeclSeq();
  void PrintDeclSeq(int);
  void ExecDeclSeq();
  void ParseDeclSeq();
};

#endif
