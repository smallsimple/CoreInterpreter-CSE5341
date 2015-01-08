#ifndef ID_H
#define ID_H

#include"Tokenizer.h"
#include"string.h"

class Id{
 private:
  string name;
  int val;
  bool declared, initialized;
  static Id *eIds[20];
  static int idCount;
  Id(string );
 public:
  static Id *ParseId();
  void PrintId();
  void DeclId();
  int GetIdVal();
  void SetIdVal(int);
  void ReadId(ifstream*);
  void WriteId();
};

#endif
