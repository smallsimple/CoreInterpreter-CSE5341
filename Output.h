#ifndef OUTPUT_H
#define OUTPUT_H

#include"Tokenizer.h"
#include"IdList.h"

class Output{
 private:
  IdList *idList;
 public:
  Output();
  void PrintOutput(int);
  void ExecOutput();
  void ParseOutput();
  
};

#endif
