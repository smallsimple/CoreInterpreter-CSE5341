#include"Cond.h"

using namespace std;

Cond::Cond(){
  comp = NULL;
  cond1 = NULL;
  cond2 = NULL;
  alterId = 0;
}

void Cond::PrintCond(){
  if (alterId == 1){
    comp->PrintComp();
  }
  else if (alterId == 2){
    cout << "!";
    cond1->PrintCond();
  }
  else if (alterId == 3){
    cout << "[ ";
    cond1->PrintCond();
    cout << " && ";
    cond2->PrintCond();
    cout << " ]";
  }
  else if (alterId == 4){
    cout << "[ ";
    cond1->PrintCond();
    cout << " || ";
    cond2->PrintCond();
    cout << " ]";
  }
  else {
    cout << "PrintError: alterId is not right." << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
}

bool Cond::EvalCond(){
  if (alterId == 1){
    if (comp->EvalComp())  
      return true;
    else
      return false;
  }
  else if (alterId == 2){
    if (cond1->EvalCond()) return false;
    else return true;
  }
  else if (alterId == 3){
    if (cond1->EvalCond() && cond2->EvalCond()) 
      return true;
    else 
      return false;
  }
  else if (alterId == 4){
    if (cond1->EvalCond() || cond2->EvalCond())
      return true;
    else
      return false;
  } 
  else {
    cout << "EvalCond Error: alterId is not right!" << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
}

void Cond::ParseCond(){
  Tokenizer *tokensCond;
  tokensCond = Tokenizer::getInstance();
  string tokenTemp = tokensCond->getToken();
  if (tokenTemp.compare("(") == 0){
    alterId = 1;
    comp = new Comp();
    comp->ParseComp();
  }
  else if (tokenTemp.compare("!") == 0){
    alterId = 2;
    tokensCond->skipToken();
    cond1 = new Cond();
    cond1->ParseCond();
  }
  else if (tokenTemp.compare("[") == 0){
    tokensCond->skipToken();
    cond1 = new Cond();
    cond2 = new Cond();
    cond1->ParseCond();
    tokenTemp = tokensCond->getToken();
    if (tokenTemp.compare("&&") == 0){
      alterId = 3;
      tokensCond->skipToken();
      cond2->ParseCond();
      tokenTemp = tokensCond->getToken();
      if (tokenTemp.compare("]") == 0){
	tokensCond->skipToken();
	return;
      }
      else {
	cout << "Error: ParseCond: \"]\" not found!" << endl;
	cout << "program stopped." << endl;
	exit(0);
      }
    }
    else if (tokenTemp.compare("||") == 0){
      alterId = 4;
      tokensCond->skipToken();
      cond2->ParseCond();
      tokenTemp = tokensCond->getToken();
      if (tokenTemp.compare("]") == 0){
	tokensCond->skipToken();
	return;
      }
      else {
	cout << "Error: ParseCond: \"]\" not found!" << endl;
	cout << "program stopped." << endl;
	exit(0);
      }
    }
    else {
      cout << "Syntax Error: <cond> is not right!" << endl;
      cout << "program stopped." << endl;
      exit(0);
    }
    
  } 
}
