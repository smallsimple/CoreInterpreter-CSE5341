#include"Loop.h"

using namespace std;

Loop::Loop(ifstream *inputfile){
  cond = NULL;
  stmtSeq = NULL;
  infile = inputfile;
}

void Loop::PrintLoop(int level){
  for (int i = 0; i < level; i++){
    cout << "\t";
  }
  cout << "while ";
  cond->PrintCond();
  cout << " loop" << endl;
  stmtSeq->PrintStmtSeq(level+1);
  for (int i = 0; i < level; i++){
    cout << "\t";
  }
  
  cout << "end;" << endl;
}

void Loop::ExecLoop(){
  while (cond->EvalCond()){
    stmtSeq->ExecStmtSeq();
  }
}

void Loop::ParseLoop(){
  Tokenizer *tokensLoop;
  tokensLoop = Tokenizer::getInstance();
  string tokenTemp = tokensLoop->getToken();
  if (tokenTemp.compare("while") == 0){
    tokensLoop->skipToken();
    cond = new Cond();
    cond->ParseCond();
    tokenTemp = tokensLoop->getToken();
    if (tokenTemp.compare("loop") == 0){
      tokensLoop->skipToken();
      stmtSeq = new StmtSeq(infile);
      stmtSeq->ParseStmtSeq();
      tokenTemp = tokensLoop->getToken();
      if (tokenTemp.compare("end") == 0){
	tokensLoop->skipToken();
	tokenTemp = tokensLoop->getToken();
	if (tokenTemp.compare(";") == 0){
	  tokensLoop->skipToken();
	  return;
	}
	else{
	  cout << "Syntax Error: ParseLoop: \";\" not found!" << endl;
	  cout << "program stopped." << endl;
	  exit(0);
	}
      }
      else {
	cout << "Syntax Error: ParseLoop: \"end\" not found!" << endl;
	cout << "program stopped." << endl;
	exit(0);
      }
    }
    else {
      cout << "Syntax Error: ParseLoop: \"loop\" not found!" << endl;
      cout << "program stopped." << endl;
      exit(0);
    }
    
  }
  
  else {
    cout << "Syntax Error: while not found!" << endl;
    cout << "program stopped.";
    exit(0);
  }
}
