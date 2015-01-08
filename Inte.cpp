#include"Inte.h"

using namespace std;

Inte::Inte(){
  
}

void Inte::PrintInte(){
  cout << name;
}

int Inte::EvalInte(){
  return value;
}

void Inte::ParseInte(){
  Tokenizer *tokensInte;
  tokensInte = Tokenizer::getInstance();
  int tokenType = tokensInte->getTokenType();
  if (tokenType != tokensInte->intNum){
    cout << "Error: ParseInte: not an integer!" << endl;
    cout << "program stopped." << endl;
    exit(0);
  }
  else {
    name = tokensInte->getToken();
    value = atoi(name.c_str());
    tokensInte->skipToken();
  }
}
