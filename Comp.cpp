#include"Comp.h"

using namespace std;

Comp::Comp(){
  op1 = NULL;
  op2 = NULL;
  alterId = 0;
}

void Comp::PrintComp(){
  cout << "( ";
  op1->PrintOp();
  if (alterId == 1)
    cout << " != ";
  else if (alterId == 2)
    cout << " == ";
  else if (alterId == 3)
    cout << " < ";
  else if (alterId == 4)
    cout << " > ";
  else if (alterId == 5)
    cout << " <= ";
  else if (alterId == 6)
    cout << " >= ";
  else {
    cout << "Error: PrintComp: alterId is not right!" << endl;
    cout << "program stopped!" << endl;
    exit(0);
  }
  op2->PrintOp();
  cout << " )";
}

bool Comp::EvalComp(){
  switch(alterId) {
  case 1:
    if (op1->EvalOp() != op2->EvalOp())
      return true;
    else 
      return false;
  case 2:
    if (op1->EvalOp() == op2->EvalOp())
      return true;
    else 
      return false;
  case 3:
    if (op1->EvalOp() < op2->EvalOp())
      return true;
    else 
      return false;
  case 4:
    if (op1->EvalOp() > op2->EvalOp())
      return true;
    else
      return false;
  case 5:
    if (op1->EvalOp() <= op2->EvalOp())
      return true;
    else 
      return false;
  case 6:
    if (op1->EvalOp() >= op2->EvalOp())
      return true;
    else
      return false;
  default:
    cout << "Error: EvalComp: wrong alterId." << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
}

void Comp::ParseComp(){
  Tokenizer *tokensComp;
  tokensComp = Tokenizer::getInstance();
  string tokenTemp = tokensComp->getToken();
  if (tokenTemp.compare("(") == 0){
    tokensComp->skipToken();
    op1 = new Op();
    op1->ParseOp();
    tokenTemp = tokensComp->getToken();
    if (tokenTemp.compare("!=") == 0)
      alterId = 1;
    else if (tokenTemp.compare("==") == 0)
      alterId = 2;
    else if (tokenTemp.compare("<") == 0)
      alterId = 3;
    else if (tokenTemp.compare(">") == 0)
      alterId = 4;
    else if (tokenTemp.compare("<=") == 0)
      alterId = 5;
    else if (tokenTemp.compare(">=") == 0)
      alterId = 6;
    else {
      cout << "Error: Comp Op not found!" << endl;
      cout << "program stopped." << endl;
      exit(0);
    }
    tokensComp->skipToken();
    op2 = new Op();
    op2->ParseOp();
    tokenTemp = tokensComp->getToken();
    if (tokenTemp.compare(")") == 0){
      tokensComp->skipToken();
      return;
    }
    else {
      cout << "Error: ParseComp: \"(\" not found!" << endl;
      cout << "program stopped." << endl;
      exit(0);
    }
  }

}
