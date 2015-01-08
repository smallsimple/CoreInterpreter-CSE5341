#ifndef IFC_H
#define IFC_H

#include"Tokenizer.h"
#include"Cond.h"
#include"StmtSeq.h"

class StmtSeq;

class Ifc{
 private:
  Cond *cond;
  StmtSeq *stmtSeq1, *stmtSeq2;
  ifstream *infile;
 public:
  Ifc(ifstream*);
  void PrintIfc(int);
  void ExecIfc();
  void ParseIfc();
};

#endif
