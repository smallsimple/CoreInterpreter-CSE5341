#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Tokenizer.h"
#include"Prog.h"

using namespace std;

int main(int argc, char* argv[]){    
  //cout << "argc = " << argc << endl;
  ifstream *inputfile;
  inputfile = NULL;
  if (argc >= 3){
    inputfile = new ifstream(argv[2]);
  }
  else {
    cout << "Warning: input file not assigned! Might be a problem." << endl;
  }
  Tokenizer *firstTokens;
  firstTokens = Tokenizer::initialize(argv[1]);
  //firstTokens->printTokensNum();
  //firstTokens->printTokensName();
  
  Prog prog(inputfile);
  prog.ParseProg();  
  cout << "==========Pretty Printed Core Program==========" << endl;
  prog.PrintProg();
  cout << "====================OUTPUT=====================" << endl;
  //cout << "finish PrintProg()." << endl;
  prog.ExecProg();
  if (inputfile != NULL && inputfile->is_open()){
    inputfile->close();
    free(inputfile);
  }
}
