#ifndef INPUT_H
#define INPUT_H

#include"Tokenizer.h"
#include"IdList.h"

class Input{
 private:
  IdList *idList;
  ifstream *infile;
 public:
  Input(ifstream *);
  void PrintInput(int);
  void ExecInput();
  void ParseInput();
};

#endif
