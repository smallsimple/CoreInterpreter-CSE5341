#include"Decl.h"
#include<stdio.h>
#include<iostream>

using namespace std;

Decl::Decl(){
  idList = NULL;
}

void Decl::PrintDecl(int level){
  for (int i = 0; i < level; i++){
    cout << "\t";
  }
  cout << "int ";
  idList->PrintIdList();
  cout << ";" << endl;
}

void Decl::ExecDecl(){
  idList->DeclIdList();
}

void Decl::ParseDecl(){
  Tokenizer *tokensDecl;
  tokensDecl = Tokenizer::getInstance();
  if (tokensDecl->getToken().compare("int") != 0){
    cout << "Syntax error: Decl error!" << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
  tokensDecl->skipToken();
  idList = new IdList();
  idList->ParseIdList();
  if (tokensDecl->getToken().compare(";") != 0){
    cout << "Sytax error: missing \";\" in Decl" << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
  tokensDecl->skipToken();
}
