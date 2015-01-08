#include"StmtSeq.h"
#include"Tokenizer.h"

StmtSeq::StmtSeq(ifstream *inputfile){
  stmt = NULL;
  stmtSeq = NULL;
  infile = inputfile;
}

void StmtSeq::PrintStmtSeq(int level){
  stmt->PrintStmt(level);
  if (stmtSeq != NULL){
    stmtSeq->PrintStmtSeq(level);
  }
}

void StmtSeq::ExecStmtSeq(){
  stmt->ExecStmt();
  if (stmtSeq != NULL){
    stmtSeq->ExecStmtSeq();
  }
}

void StmtSeq::ParseStmtSeq(){
  stmt = new Stmt(infile);
  stmt->ParseStmt();
  Tokenizer *tokensStmtSeq;
  tokensStmtSeq = Tokenizer::getInstance();
  string tokenTemp = tokensStmtSeq->getToken();
  if ((tokenTemp.compare("end") != 0) && (tokenTemp.compare("else") != 0)){
    stmtSeq = new StmtSeq(infile);
    stmtSeq->ParseStmtSeq();
  }
  
  else {
    //tokensStmtSeq->skipToken();
    //cout << "parsing finished" << endl;
    return;
  }
  
}

