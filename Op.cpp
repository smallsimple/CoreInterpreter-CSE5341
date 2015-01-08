#include"Op.h"

using namespace std;

Op::Op(){
  inte = NULL;
  id = NULL;
  expr = NULL;
  alterId = 0;
}

void Op::PrintOp(){
  if (alterId == 1){
    inte->PrintInte();
    return;
  }
  else if (alterId == 2){
    id->PrintId();
    return;
  }
  else if (alterId == 3){
    cout << "( ";
    expr->PrintExpr();
    cout << " )";
    return;
  }
  else {
    cout << "Error: PrintOp: Wrong alterId" << endl;
    cout << "program stopped" << endl;
    exit(0);
  }
}

int Op::EvalOp(){
  
  if (alterId == 1){
    return inte->EvalInte();
  }
  else if (alterId ==2){
    return id->GetIdVal();
  }
  else if (alterId ==3){
    return expr->EvalExpr();
  }
  else {
    cout << "Error: EvalOp: Wrong alterId" << endl;
    cout << "program stopped" << endl;
    exit(0);
  }
}

void Op::ParseOp(){
  Tokenizer *tokensOp;
  tokensOp = Tokenizer::getInstance();
  int tokenType = tokensOp->getTokenType();
  if (tokenType == tokensOp->intNum){
    alterId = 1;
    inte = new Inte();
    inte->ParseInte();
  }
  else if (tokenType == tokensOp->idNum){
    //cout << "token.name: "<< tokensOp->getToken() << endl;
    alterId = 2;
    id = Id::ParseId();    
  }
  else if (tokenType == 20){//20 for "("
    alterId = 3;
    tokensOp->skipToken();
    expr = new Expr();
    expr->ParseExpr();
    tokenType = tokensOp->getTokenType();
    if (tokenType == 21){//21 for ")"
      tokensOp->skipToken();
    }
    else {
      cout << "Error: ParseOp: \")\" not found or not in right place!" << endl;
      cout << "program stopped." << endl;
      exit(0);
    }
  }
  else {
    cout << "Error: ParseOp: no Op is found!" << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
}
