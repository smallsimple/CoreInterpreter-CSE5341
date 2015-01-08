#ifndef STMTSEQ_H
#define STMTSEQ_H

#include<stdlib.h>
#include"Stmt.h"

class Stmt;

class StmtSeq{
 private:
  Stmt *stmt;
  StmtSeq *stmtSeq;
  ifstream *infile;
 public:
  StmtSeq(ifstream*);
  void PrintStmtSeq(int);
  void ExecStmtSeq();
  void ParseStmtSeq();
};

#endif
