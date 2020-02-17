#ifndef POSTFIX_HPP_
#define POSTFIX_HPP_

#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <fstream>
#include <sstream>
#include <cstring>

#include "CMD.h"
#include "Token.h"
#include "Connector.h"
#include "And.h"
#include "Or.h"
#include "Semicolon.h"
#include "Exit.h"

using namespace std;


CMD* buildTree(char** arr){
  stack<CMD*> s;
  int SIZE = 0;

  while(arr[SIZE] != NULL){
    ++SIZE;
  }
  ++SIZE;

  char *aSym = (char*) "&&";
  char *oSym = (char*) "||";
  char *sSym = (char*) ";";
  char *eSym = (char*) "exit";

  for(unsigned i = 0; i < SIZE; ++i){
    char *temp = arr[i];
    if (strcmp(temp, eSym) == 0){
      CMD *t = new Exit();
      s.push(t);
    }
    else if(strcmp(temp, aSym) == 0){
      CMD *t = new And();
      t->SetR(s.top());
      s.pop();
      t->SetL(s.top());
      s.pop();
      s.push(t);
    }

    else if(strcmp(temp, oSym) == 0){
      CMD *t = new Or();
      t->SetR(s.top());
      s.pop();
      t->SetL(s.top());
      s.pop();
      s.push(t);
    }

    else if(strcmp(temp, sSym) == 0){
      CMD *t = new Semicolon();
      t->SetR(s.top());
      s.pop();
      t->SetL(s.top());
      s.pop();
      s.push(t);
    }
    else{
      CMD* t = new Token(temp);
      s.push(t);
    }
  }
  CMD* t = s.top();
  s.pop();

  return t;
}
/*
char** infix_to_postfix(char** input){
   stack<char*> s;
   ostringstream oss;
   int SIZE = 0;
   
   while(input[i] != NULL){
	++SIZE;
   }
   
   int index = 0;
   int i1 = 0;
   char *arr[SIZE];
   char *aSym = (char*) "&&";
   char *oSym = (char*) "||";
   char *sSym = (char*) ";"; 

   for(int i = 0; i < SIZE; ++i){
	if(strcmp(input[i], aSym) == 0){
 	    char *sum = new char[512];
	    for(int l = i1; l < i; ++l){
		strcat(sum, input[l]);
		if(l+1 !=  i){strcat(sum, ' ');}
	    }
            i1 = i + 1;
	    arr[index] = sum;
	    ++index;
	    arr[index] = new (char*) "&&";
	    ++index;
        }
        else if(strcmp(input[i], oSym) == 0){
	    char *sum  = new  char[512];
            for(int l = i1; l < i; ++l){
                strcat(sum, input[l]);
                if(l+1 !=  i){strcat(sum, ' ');}
            }
            i1 = i + 1;
            arr[index] = sum;
            ++index;
	    arr[index] = new (char*) "||";
            ++index;
        }
        else if(strcmp(input[i], sSym) == 0){
		cout << "L SNZ BOIZZZZ" << endl;
        }	
   }
   if(i1 < SIZE){
 	char *sum = new char[512];
        while (i1 < SIZE){
	     strcat(sum, input[i1];
	     if(i1+1 != SIZE){strcat(sum, ' ');}
	     ++i1;
	}
	arr[index] = sum;
	++index;
   }
   arr[index] = '\0';
   SIZE = index;   
 








   for(unsigned i = 0; i < input.size();++i){
       c = input.at(i);
       if(c == ' '){
           continue;
       }
       if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
             while(!s.empty() && priority(c) <= priority(s.top())){
                 if(s.top() == '('){
                     break;
                 }
                 oss << s.top();
                 s.pop();
             }
             s.push(c);
           
       }
       else{ //c is an operand
           oss << c;
       }
   }
   while(!s.empty()){
       oss << s.top();
       s.pop();
   }
   return oss.str();
 }

*/
bool runTree(CMD* root){
  CMD* t = root;
  CMD* tL = root->GetL();
  CMD* tR = root->GetR();
  bool ran = true;

  if(tL != NULL && tL->isCon() == true){
    ran = runTree(tL);
  }

  if(t->isAnd()){
    if(tL->isCon()){
      if(ran){return tR->run();}
    }
    else{
      bool tf = tL->run();
      if(tf){return tR->run();}
      return false;
    }
  }
  else if(t->isOr()){
    if(tL->isCon()){
      if(ran){return true;}
      else{return tR->run();}
    }
    else{
      bool tf = tL->run();
      if(tf){return true}
      return tR->run();
    }
  }
  else if(t->isSemicolon()){
    if(tL->isCon()){
      return tR->run();
    }
    else{
      tL->run();
      return tR->run();
    }
  }
  return t->run();
}


#endif
