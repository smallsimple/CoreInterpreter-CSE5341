#ifndef TOKENIZER_H
#define TOKENIZER_H

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<sstream>
#include<ctype.h>

using namespace std;

struct Token{// struct to record token's name and number
  int num;
  string name;
};

struct SpecMarker{//mark start position and id of special symbols in one string
  int start;
  int id;
};


class Tokenizer {//Tokenizer class
  
 private:
  static bool instanceFlag;
  static Tokenizer *tokenizer;
  Tokenizer();                      //constructor
  Tokenizer(char* filename );       //constructor
  
  static string resWords[11];       //11 reserved words
  static string specSymbols[19];    //19 special symbols
  vector<Token> tokens;             //store the token information
  void dealToken(string );          //produce token from input string
  vector<SpecMarker> searchSpec(string );  //find special symbols and split string
  int isRes(string );               //is a reserved word? 
  bool isIntegers(string );         //is an integer?
  bool isIdenti(string);            //is an identifier?
  bool isLegalToken(string);        //is a legal token?
  static int curTokenNum;
  
 public:
  static Tokenizer* initialize(char* );
  static Tokenizer* getInstance();
  void printTokensName();           //print the tokens' name
  void printTokensNum();            //print the tokens' number
  ~Tokenizer();
  string getToken();                //returns (info about) current token
  void skipToken();                 //skips current token;
  int intVal();                     //returns the value of current integer
  string idName();                  //returns the name of the current id
  int getTokenType();               //returns the token type (integer)
  const static int intNum, idNum, eofNum;
};

#endif
