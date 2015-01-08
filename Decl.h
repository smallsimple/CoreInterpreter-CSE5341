#ifndef DECL_H
#define DECL_H

#include"Tokenizer.h"
#include"IdList.h"

class Decl{
 private:
  IdList *idList;
 public:
  Decl();
  void PrintDecl(int);
  void ExecDecl();
  void ParseDecl();
};


#endif
