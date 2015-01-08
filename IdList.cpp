#include"IdList.h"

using namespace std;

IdList::IdList(){
  id = NULL;
  idList = NULL;
}

void IdList::PrintIdList(){
  id->PrintId();
  if (idList != NULL){
    cout << ", ";
    idList->PrintIdList();
  }
  
}

void IdList::DeclIdList(){
  id->DeclId();
  if (idList != NULL){
    idList->DeclIdList();
  }
}

void IdList::ParseIdList(){
  Tokenizer *tokensIdList;
  tokensIdList = Tokenizer::getInstance();
  id = Id::ParseId();
  string tokenTemp = tokensIdList->getToken();
  if (tokenTemp.compare(",") == 0){
    tokensIdList->skipToken();
    idList = new IdList();
    idList->ParseIdList();
    return;
  }
  else if (tokenTemp.compare(";") == 0){
    return;
  }
  else{
    cout << "token is : " << tokenTemp << endl;
    cout << "Syntax error: IdList error" << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
}

void IdList::ReadIdList(ifstream *inputfile){
  id->ReadId(inputfile);
  if (idList != NULL){
    idList->ReadIdList(inputfile);
  }
}

void IdList::WriteIdList(){
  id->WriteId();
  if (idList != NULL){
    idList->WriteIdList();
  }
}
