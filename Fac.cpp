#include"Fac.h"

using namespace std;

Fac::Fac(){
  op = NULL;
  fac = NULL;
}

void Fac::PrintFac(){
  op->PrintOp();
  if (fac != NULL){
    cout << " * ";
    fac->PrintFac();
  }
}

int Fac::EvalFac(){
  if (fac == NULL){
    return op->EvalOp();
  }  
  else{
    return op->EvalOp() * fac->EvalFac();
  }
}

void Fac::ParseFac(){
  Tokenizer *tokensFac;
  tokensFac = Tokenizer::getInstance();
  op = new Op();
  op->ParseOp();
  string tokenTemp = tokensFac->getToken();
  if (tokenTemp.compare("*") != 0){
    return;
  }
  else{
    tokensFac->skipToken();
    fac = new Fac();
    fac->ParseFac();
  }
}
