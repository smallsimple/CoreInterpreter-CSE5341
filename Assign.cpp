#include"Assign.h"

using namespace std;

Assign::Assign(){
  id = NULL;
  expr = NULL;
}

void Assign::PrintAssign(int level){
  for (int i = 0; i < level; i++){
    cout << "\t";
  }
  id->PrintId();
  cout << " = ";
  expr->PrintExpr();
  cout << ";" << endl;
}

void Assign::ExecAssign(){
  id->SetIdVal(expr->EvalExpr());
}

void Assign::ParseAssign(){
  Tokenizer *tokensAssign;
  tokensAssign = Tokenizer::getInstance();
  int tokenType;
  tokenType = tokensAssign->getTokenType();
  if (tokenType != tokensAssign->idNum){
    cout << "Error: Assign: not legal identifier" << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
  id = Id::ParseId();
  string tokenTemp;
  tokenTemp = tokensAssign->getToken();
  if (tokenTemp.compare("=") != 0){
    cout << "Error: Assign: \"=\" not found after identifier." << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
  else {
    tokensAssign->skipToken();
  }
  
  expr = new Expr();
  expr->ParseExpr();
  tokenTemp = tokensAssign->getToken();
  if (tokenTemp.compare(";") != 0){
    cout << "Error; Assign: \";\" not found or not in the right place!" << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
  tokensAssign->skipToken();
}
