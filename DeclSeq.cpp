#include"DeclSeq.h"

DeclSeq::DeclSeq(){
  decl = NULL;
  declSeq = NULL;
}

void DeclSeq::PrintDeclSeq(int level){
  decl->PrintDecl(level);
  if (declSeq != NULL ){
    declSeq->PrintDeclSeq(level);
  }
}

void DeclSeq::ExecDeclSeq(){
  decl->ExecDecl();
  if (declSeq != NULL){
    declSeq->ExecDeclSeq();
  }
}

void DeclSeq::ParseDeclSeq(){
  Tokenizer *tokensDeclSeq;
  tokensDeclSeq = Tokenizer::getInstance();
  
  decl = new Decl();
  decl->ParseDecl();
  string tokenTemp;
  tokenTemp = tokensDeclSeq->getToken();
  if (tokenTemp.compare("int") == 0){
    declSeq = new DeclSeq();
    declSeq->ParseDeclSeq();
  }
  else if (tokenTemp.compare("begin") == 0){
    return;
  }
  else{
    cout << "Syntax Error: decl seq wrong!" << endl;
    cout << "program stopped!" << endl;
    exit(0);
  }
}
