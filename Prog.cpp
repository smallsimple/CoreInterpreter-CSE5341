#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"Prog.h"
#include"Tokenizer.h"

using namespace std;

Prog::Prog(ifstream *inputfile){
  ds = NULL;
  ss = NULL;
  infile = inputfile;
}

void Prog::PrintProg(){
  int level = 0;
  cout << "program" << endl;
  ds->PrintDeclSeq(level+1);
  cout << "begin" << endl;
  ss->PrintStmtSeq(level+1);
  cout << "end" << endl;
}

void Prog::ExecProg(){
  ds->ExecDeclSeq();
  ss->ExecStmtSeq();
}

void Prog::ParseProg(){
  Tokenizer *tokensProg; // declare a singleton Tokenizer class
  tokensProg = Tokenizer::getInstance();// get instance of the Tokenizer class  
  if (tokensProg->getToken().compare("program") != 0){
    cout << "Syntax error: the first token is not \"program\"!"<< endl;
    cout << "program stoppted." << endl;
    exit(0);
  }
  tokensProg->skipToken();
  ds = new DeclSeq();
  ds->ParseDeclSeq();
  if (tokensProg->getToken().compare("begin") != 0){
    cout << "Syntax error: \"begin\" is not in the right place!" << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
  tokensProg->skipToken();
  ss = new StmtSeq(infile);
  ss->ParseStmtSeq();
  //tokensProg->skipToken();
  if (tokensProg->getToken().compare("end") != 0){
    cout << "Syntax error: \"end\" is not in the right place!" << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
  else{
    tokensProg->skipToken();
    return;
  }
}
