#include"Output.h"

using namespace std;

Output::Output(){
  idList = NULL;
}

void Output::PrintOutput(int level){
  for (int i = 0; i < level; i++){
    cout << "\t";
  }
  cout << "write ";
  idList->PrintIdList();
  cout << ";" << endl;
}

void Output::ExecOutput(){
  idList->WriteIdList();
}

void Output::ParseOutput(){
  Tokenizer *tokensOutput;
  tokensOutput = Tokenizer::getInstance();
  string tokenTemp = tokensOutput->getToken();
  if (tokenTemp.compare("write") == 0){
    tokensOutput->skipToken();
    idList = new IdList();
    idList->ParseIdList();
    tokenTemp = tokensOutput->getToken();
    if (tokenTemp.compare(";") == 0){
      tokensOutput->skipToken();
    }
    else{
      cout << "Syntax Error: no \";\" is found or not in the right place" << endl;
      cout << "program stopped!" << endl;
      exit(0);
    }
  }
  else{
    cout << "Error: ParseOutput: no \"wrte\" is found." << endl;
    cout << "program stopped!" << endl;
    exit(0);
  }
}



