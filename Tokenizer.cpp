#include"Tokenizer.h"

string Tokenizer::resWords[] = {"program", "begin", "end", "int", "if", "then",
				"else", "while", "loop", "read", "write"};
string Tokenizer::specSymbols[] = {";", ",", "=", "!", "[", "]", "&&", "||", 
				   "(", ")", "+", "-", "*", "!=", "==", "<", 
				   ">", "<=", ">="};
const int Tokenizer::intNum = 31;
const int Tokenizer::idNum = 32;
const int Tokenizer::eofNum = 33;
int Tokenizer::curTokenNum = 0;

void Tokenizer::printTokensName(){ 
  int i; 
  for (i = 0; i < this->tokens.size(); i++){
    cout << this->tokens[i].name << " ";
  }
  cout << endl;
}
 
void Tokenizer::printTokensNum(){
  int i;
  for (i = 0; i < this->tokens.size(); i++){
    cout << this->tokens[i].num << endl;
  }
}

vector<SpecMarker> Tokenizer::searchSpec(string str){
  vector<SpecMarker> sMarker;
  int i = 0;
  do{
    for (int j = 18; j >= 0; j--){
      if(this->specSymbols[j].compare(str.substr(i,this->specSymbols[j].size()))==0){
	SpecMarker temp;
	temp.start = i;
	temp.id = j;
	sMarker.push_back(temp);
	i += specSymbols[j].size() - 1;
	break;
      }
    }
    i++;    
  }while (i < str.size());

  return sMarker;
}

int Tokenizer::isRes(string str){
  for (int i = 0; i < 11; i++){
    if (str.compare(resWords[i]) == 0){
      return i + 1;
    }
  }
  return 0;
}

bool Tokenizer::isIntegers(string str){
  for (int i = 0; i < str.size(); i++){
    if (!isdigit(str.at(i)))
      return false;
  }
  return true;
}

bool Tokenizer::isIdenti(string str){
  int i;
  int judge;

  // if first character is not upper letter
  if (!isupper(str.at(0))){
    return false;
  }
    
  //check each character is uppercase letter or digit
  for (i = 1; i < str.size(); i++){
    if(!(isupper(str.at(i)) || isdigit(str.at(i)))){
      return false;
    }
  }

  //check if the order of the characters is not right
  judge = 0;
  for (i = 0; i < str.size() - 1 ; i++){
    if ((isupper(str.at(i)) && isdigit(str.at(i+1)))
	|| (isdigit(str.at(i)) && isupper(str.at(i+1)))){
      judge++;
    }
  }

  if (judge > 1) return false;

  return true;
}

bool Tokenizer::isLegalToken(string temp){
  int flag = 0;
  Token tok;
  // is temp a reserved word
  if (int ID = isRes(temp)){
    flag = 1;
    tok.name = temp;
    tok.num = ID;
    tokens.push_back(tok);
  }
  // is temp a integer
  if (flag ==0 && isIntegers(temp)){
    flag = 1;
    tok.name = temp;
    tok.num = 31;
    tokens.push_back(tok);
  }
  // is temp a legal identifier
  if (flag ==0 && isIdenti(temp)){
    flag = 1;
    tok.name = temp;
    tok.num = 32;
    tokens.push_back(tok);
  }
  // temps is not one of reserved word, special symbols, integer and Id
  // print error
  if (flag == 0){
    cout << "Error!!!" << endl;
    cout << "the current recognized tokens are:" << endl;
    this->printTokensName();
    cout << "cooresponding numbers are:" << endl;
    this->printTokensNum();
    cout << "\"" << temp << "\"" << " is not a legal token." << endl;
    return false;
  }
  else{
    return true;
  }
}

void Tokenizer::dealToken(string str){
  int start = 0;
  int flag = 0; 
  Token tok;
  vector<SpecMarker> sMarker1;
  sMarker1 = this->searchSpec(str);
  for (int i = 0; i < sMarker1.size(); i++){
    // deal with string before special symbol if any
    if (start < sMarker1[i].start){
      int len = sMarker1[i].start - start;
      int ID;
      string temp = str.substr(start, len);
      if(!isLegalToken(temp)) {
	cout << "program stopped." << endl;
	exit(0);
      }
    }
    // deal with speical symbol
    tok.name = specSymbols[sMarker1[i].id];
    tok.num = sMarker1[i].id + 12;
    tokens.push_back(tok);
    // move start to end of next speical symbol
    start = sMarker1[i].start + specSymbols[sMarker1[i].id].size();
  }
  
  // if there is token after the last special symbols
  if (start < str.size()){
    string temp = str.substr(start, str.size()-start);
    if(!isLegalToken(temp)) {
      cout << "program stopped." << endl;
      exit(0);
    }
    else{
    }
    
  }
}

Tokenizer::Tokenizer(){
  //this->curTokenNum = 0;
}

Tokenizer::~Tokenizer(){
  instanceFlag = false;
}

Tokenizer::Tokenizer(char* filename){
  Tokenizer();
  ifstream inputF;
  inputF.open(filename);
  int i=0;
  do{
    string sub;
    inputF >> sub;
    this->dealToken(sub);
  } while(!inputF.eof());
  // if no illegal token, add EOF to the end
  Token tok;
  tok.name = "\0"; // use "\0" as a EOF character
  tok.num = 33;
  this->tokens.push_back(tok);
}

bool Tokenizer:: instanceFlag = false;
Tokenizer* Tokenizer::tokenizer = NULL;
Tokenizer* Tokenizer::initialize(char* filename){
  if(! instanceFlag){
    tokenizer = new Tokenizer(filename);
    instanceFlag = true;
    return tokenizer;
  }
  else{
    cout << "Error: Tokenizer has already been initialized!" << endl;
    cout << "program stoppted!" << endl;
    exit(0);
  }
}

Tokenizer* Tokenizer::getInstance(){
  if (! instanceFlag){
    cout << "Error: Tokenizer has not been initialized" << endl;
    cout << "program stopped!" << endl;
    exit(0);
  }
  else{
    return tokenizer;
  }
}

string Tokenizer::getToken(){ //returns (info about) current token
  /*
  cout << "curTokenNum=" << curTokenNum << endl;
  cout << "TokenType=" << this->tokens.at(curTokenNum).num << endl;
  cout << "tokenName:  " << this->tokens.at(curTokenNum).name << endl;
  */
  if (this->tokens.at(curTokenNum).num == this->eofNum ){
    cout << "Warning: has reached the end-of-file!" << endl;
  }
  return this->tokens.at(curTokenNum).name;
}

void Tokenizer::skipToken(){
  if (curTokenNum < tokens.size()){
    curTokenNum++;
  }
  else{
    cout << "Error: End of the file! There are no tokens!" << endl;
  }
}

int Tokenizer::intVal(){
  if (this->tokens.at(curTokenNum).num == 31){
    string intTemp = this->tokens.at(curTokenNum).name;
    return atoi(intTemp.c_str());
  }
  else{
    cout << "Error: current token is not an integer" << endl;
    cout << "program stopped!" << endl;
    exit(0);
  }
}

string Tokenizer::idName(){
  if(this->tokens.at(curTokenNum).num == 32){
    return this->tokens.at(curTokenNum).name;
  }
  else{
    cout << "Error: current token is not an identifier" << endl;
    cout << "program stopped!" << endl;
    exit(0);
  }
}

int Tokenizer::getTokenType(){
  return this->tokens.at(curTokenNum).num;
}
