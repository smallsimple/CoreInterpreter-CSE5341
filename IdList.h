#ifndef IDLIST_H
#define IDLIST_H

#include"Id.h"
#include"Tokenizer.h"

class IdList{
 private:
  Id *id;
  IdList *idList;
 public:
  IdList();
  void PrintIdList();
  void DeclIdList();
  void ParseIdList();
  void ReadIdList(ifstream*);
  void WriteIdList();
};

#endif
