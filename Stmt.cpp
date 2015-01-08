#include"Stmt.h"

using namespace std;

Stmt::Stmt(ifstream *inputfile){
  assign = NULL;
  ifc = NULL;
  loop = NULL;
  input = NULL;
  output = NULL;
  infile = inputfile;
}

void Stmt::PrintStmt(int level){
  if (assign != NULL){
    assign->PrintAssign(level);
  }
  else if (ifc != NULL){
    ifc->PrintIfc(level);
  }
  else if (loop != NULL){
    loop->PrintLoop(level);
  }
  else if (input != NULL){
    input->PrintInput(level);
  }
  else if (output != NULL){
    output->PrintOutput(level);
  }
  else{
    cout << "Error: PrintStmt: None of alternative is found!" << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
}

void Stmt::ExecStmt(){
  if (assign != NULL){
    assign->ExecAssign();
  }
  else if (ifc != NULL){
    ifc->ExecIfc();
  }
  else if (loop != NULL){
    loop->ExecLoop();
  }
  else if (input != NULL){
    input->ExecInput();
  }
  else if (output != NULL){
    output->ExecOutput();
  }
  else {
    cout << "Error: ExecStmt: No alternative is found!" << endl;
    cout << "program stopped.";
    exit(0);
  }
}

void Stmt::ParseStmt(){
  Tokenizer *tokensStmt;
  tokensStmt = Tokenizer::getInstance();
  int tokenType = tokensStmt->getTokenType();
  if (tokenType == tokensStmt->idNum){
    assign = new Assign();
    assign->ParseAssign();
  }
  else if (tokenType == 5){//5 for 'ifc'
    ifc = new Ifc(infile);
    ifc->ParseIfc();
  }
  else if (tokenType == 8){// 8 for 'while'
    loop = new Loop(infile);
    loop->ParseLoop();
  }
  else if (tokenType == 10){//10 for 'read'
    input = new Input(infile);
    input->ParseInput();
  }
  else if (tokenType == 11){//11 for 'write'
    output = new Output();
    output->ParseOutput();
  }
  else{
    cout << "Error: Stmt" << endl;
    cout << "program stopped" << endl;
    exit(0);
  }
}
