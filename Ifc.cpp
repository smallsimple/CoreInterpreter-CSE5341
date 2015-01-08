#include"Ifc.h"

using namespace std;

Ifc::Ifc(ifstream *inputfile){
  cond = NULL;
  stmtSeq1 = NULL;
  stmtSeq2 = NULL;
  infile = inputfile;
}

void Ifc::PrintIfc(int level){
  for (int i = 0; i < level; i++){
    cout << "\t";
  }
  cout << "if ";
  cond->PrintCond();
  cout << " then" << endl;
  stmtSeq1->PrintStmtSeq(level + 1);
  for (int i = 0; i < level; i++){
    cout << "\t";
  }

  if (stmtSeq2 == NULL){
    cout << "end;" << endl;
  }
  else {
    cout << "else" << endl;
    stmtSeq2->PrintStmtSeq(level + 1);
    for (int i = 0; i < level; i++){
      cout << "\t";
    }
    
    cout << "end;" << endl;
  }
}

void Ifc::ExecIfc(){
  if (cond->EvalCond()){
    stmtSeq1->ExecStmtSeq();
  }
  else{
    if(stmtSeq2 != NULL){
      stmtSeq2->ExecStmtSeq();
    }
  }
}

void Ifc::ParseIfc(){
  Tokenizer *tokensIfc;
  tokensIfc = Tokenizer::getInstance();
  string tokenTemp = tokensIfc->getToken();
  if (tokenTemp.compare("if") == 0){
    tokensIfc->skipToken();
    cond = new Cond();
    cond->ParseCond();
    tokenTemp = tokensIfc->getToken();
    if (tokenTemp.compare("then") == 0){
      tokensIfc->skipToken();
      stmtSeq1 = new StmtSeq(infile);
      stmtSeq1->ParseStmtSeq();
      tokenTemp = tokensIfc->getToken();
      if (tokenTemp.compare("end") == 0){
	tokensIfc->skipToken();
	tokenTemp = tokensIfc->getToken();
	if (tokenTemp.compare(";") == 0){
	  tokensIfc->skipToken();
	  return;
	}
	else{
	  cout << "Syntax Error: ParseIfc: \";\" not found or not in the right place." << endl;
	  cout << "program stopped." << endl;
	  exit(0);
	}
      }
      else if (tokenTemp.compare("else") == 0){
	tokensIfc->skipToken();
	stmtSeq2 = new StmtSeq(infile);
	stmtSeq2->ParseStmtSeq();
	tokenTemp = tokensIfc->getToken();
	if (tokenTemp.compare("end") == 0){
	  tokensIfc->skipToken();
	  tokenTemp = tokensIfc->getToken();
	  if (tokenTemp.compare(";") == 0){
	    tokensIfc->skipToken();
	    return;
	  }
	  else {
	    cout << "Syntax Error: ParseIfc: \";\" not found or not in the right place." << endl;
	    cout << "program stopped." << endl;
	    exit(0);
	  }
	}
	else{
	    cout << "Syntax Error: ParseIfc: \";\" not found or not in the right place." << endl;
	    cout << "program stopped." << endl;
	    exit(0);
	}
      }
      else {
	cout << "Syntax Error: ParseIfc: no \"end\" or \"else\" is found" << endl;
	cout << "program stopped." << endl;
	exit(0);
      }
    }
  }

}
