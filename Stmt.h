#ifndef STMT_H
#define STMT_H

#include"Tokenizer.h"
#include"Assign.h"
#include"Ifc.h"
#include"Loop.h"
#include"Input.h"
#include"Output.h"
class Assign;
class Ifc;
class Loop;

class Stmt{
 private:
  ifstream *infile;
  Assign *assign;
  Ifc *ifc;
  Loop *loop;
  Input *input;
  Output *output;
 public:
  Stmt(ifstream*);
  void PrintStmt(int);
  void ExecStmt();
  void ParseStmt();
};

#endif
