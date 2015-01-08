#include"Expr.h"

using namespace std;

Expr::Expr(){
  fac = NULL;
  expr = NULL;
  alterId = 0;
}

void Expr::PrintExpr(){
  fac->PrintFac();
  if (alterId == 2){
    cout << " + ";
    expr->PrintExpr();
    return;
  }
  else if (alterId == 3){
    cout << " - ";
    expr->PrintExpr();
    return;
  }
  else if (alterId == 1){
    return;
  }
  else {
    cout << "Error: PrintExpr: Wrong alterId" << endl;
    cout << "program stopped" << endl;
    exit(0);
  }
}

int Expr::EvalExpr(){
  if (alterId == 1){
    return fac->EvalFac();
  }
  else if (alterId == 2){
    return fac->EvalFac() + expr->EvalExpr();
  }
  else if (alterId == 3){
    return fac->EvalFac() - expr->EvalExpr();
  }
  else {
    cout << "Error: EvalExpr: Wrong alterId"  << endl;
    cout << "program stopped" << endl;
    exit(0);
  }
}

void Expr::ParseExpr(){
  Tokenizer *tokensExpr;
  tokensExpr = Tokenizer::getInstance();
  fac = new Fac();
  fac->ParseFac();
  string tokenTemp = tokensExpr->getToken();
  if (tokenTemp.compare("+") == 0){
    tokensExpr->skipToken();
    expr = new Expr();
    expr->ParseExpr();
    alterId = 2;
    return;
  }
  else if (tokenTemp.compare("-") == 0){
    tokensExpr->skipToken();
    expr = new Expr();
    expr->ParseExpr();
    alterId = 3;
    return;
  }
  else{
    alterId = 1;
    return;
  }
  
}
