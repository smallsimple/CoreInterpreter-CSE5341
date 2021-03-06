#include"Id.h"

using namespace std;

Id* Id::eIds[] = {NULL};

int Id::idCount = 0;

Id::Id(string n){  
  //cout << "Id::Id(string n) before initialize:" << endl;
  name = n;
  //cout << "name = " << name << endl;
  declared = false;
  //cout << "declared = " << declared << endl;
  initialized = false;
  //cout << "Id::Id(string n) after initialize" << endl;
}

Id* Id::ParseId(){
  Tokenizer *tokensId;
  tokensId = Tokenizer::getInstance();
  string tokenTemp = tokensId->getToken();
  int tokenType = tokensId->getTokenType();
  if (tokenType != tokensId->idNum) {
    cout << "Error: " << tokenTemp << " is not a legal identifier!" << endl;
    cout << "program stopped." << endl;
    exit(0);
  }

  for (int k = 0; k < idCount; k++){
    if (tokenTemp.compare(eIds[k]->name) == 0){
      tokensId->skipToken();
      return eIds[k];
    }
  }
  // if not found
  Id *nId = new Id(tokenTemp);
  eIds[idCount] = nId;
  idCount++;
  tokensId->skipToken();
  return nId;
}

void Id::DeclId(){
  //cout << "Id::DeclId()" << endl;
  declared = true;
  //  cout << "Id: " << name << " is declared" << endl;
}

void Id::PrintId(){
  cout << name;
}

int Id::GetIdVal(){
  if (initialized){
    return val;
  }
  else {
    cout << "Error: GetIdVal: id \"" << name << "\" is not initialzied yet!" << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
}

void Id::SetIdVal(int value){
  val = value;
  if (!initialized){
    initialized = true;
  }
}

void Id::ReadId(ifstream* inputfile){
  if(inputfile != NULL){
    if(inputfile->is_open() && !inputfile->eof()){
      int integer;
      string num;
      *inputfile >> num;
      if (!isdigit(num.at(0))) {
	if (strcmp("-", num.substr(0,1).c_str()) != 0){
	  cout << "Error: input is not a number" << endl;
	  cout << "program stopped." << endl;
	  exit(0);
	}
      }
      for (int i=1; i< num.size(); i++){
	if (!isdigit (num.at(i))){
	  cout << "Error: input is not a number" << endl;
	  cout << "program stopped!" << endl;
	  exit(0);
	}
      }
      integer = atoi(num.c_str());
      this->SetIdVal(integer);
    }
    else {
      cout << "input file is not open or has reached the end of the file." << endl;
      cout << "program stopped." << endl;
      exit(0);
    }
  }
  else{
    cout << "Error: no input file is assigned." << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
}
void Id::WriteId(){
  cout << name << " = " << val << endl;
}
