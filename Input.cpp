#include"Input.h"

using namespace std;

Input::Input(ifstream *inputfile){
  idList = NULL;
  infile = inputfile;
}

void Input::PrintInput(int level){
  for (int i = 0; i < level; i++){
    cout << "\t";
  }
  cout << "read ";
  idList->PrintIdList();
  cout << ";" << endl;
}

void Input::ExecInput(){
  //if(infile->is_open()){
    idList->ReadIdList(infile);
    //}
}

void Input::ParseInput(){
  Tokenizer *tokensInput;
  tokensInput = Tokenizer::getInstance();
  string tokenTemp = tokensInput->getToken();
  if (tokenTemp.compare("read") == 0){
    //cout << "read is parsed." << endl;
    tokensInput->skipToken();
    idList = new IdList();
    idList->ParseIdList();
    tokenTemp = tokensInput->getToken();
    if (tokenTemp.compare(";") == 0){
      tokensInput->skipToken();
      return;
    }
    else{
      cout << "Syntax Error: ParseInput: ';' not found or not in the right place!" << endl;
      cout << "program stopped." << endl;
      exit(0);
    }
  }
  else{
    cout << "Syntax Error: ParseInput: 'read' not found or not in the right place!" << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
}
