#ifndef LOOP_H
#define LOOP_H

#include"Tokenizer.h"
#include"Cond.h"
#include"StmtSeq.h"

class StmtSeq;

class Loop{
 private:
  Cond *cond;
  StmtSeq *stmtSeq;
  ifstream *infile;
 public:
  Loop(ifstream*);
  void PrintLoop(int);
  void ExecLoop();
  void ParseLoop();
};

#endif
