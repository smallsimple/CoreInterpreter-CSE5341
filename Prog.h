#ifndef PROG_H
#define PROG_H

#include<string.h>
#include"Tokenizer.h"
#include"DeclSeq.h"
#include"StmtSeq.h"

class Prog{
 private:
  DeclSeq* ds; 
  StmtSeq* ss;
  ifstream* infile;
 public:
  Prog(ifstream*);
  void PrintProg();
  void ExecProg();
  void ParseProg();
};

#endif
