
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
      if(tf){return true;}
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



char** infix_to_postfix(char** input){
int SIZE = 0;


while(input[SIZE] != NULL){
++SIZE;
}
++SIZE;

int index = 0;
int i1 = 0;
char **arr = new char* [SIZE];
char *aSym = (char*) "&&";
char *oSym = (char*) "||";
char *sSym = (char*) ";";



for(int i = 0; i < SIZE-1; ++i){

     if(strcmp(input[i], aSym) == 0){
        char *sum = new char[512];
        for(int l = i1; l < i; ++l){
        strcat(sum, input[l]);
        if(l+1 !=  i){strcat(sum, " ");}
        }
            i1 = i + 1;
        arr[index] = sum;
        ++index;
        char* add = new char[3];

        add[0] = '&';
        add[1] = '&';
        add[2] = '\0';
        arr[index] = add;
        ++index;
    }
    else if(strcmp(input[i], oSym) == 0){
    char *sum  = new  char[512];
        for(int l = i1; l < i; ++l){
            strcat(sum, input[l]);
            if(l+1 !=  i){strcat(sum, " ");}
        }
        i1 = i + 1;
        arr[index] = sum;
        ++index;
        char* add = new char[3];

        add[0] = '|';
        add[1] = '|';
        add[2] = '\0';
        arr[index] = add;
        ++index;
    }
    else if(strcmp(input[i], sSym) == 0){
    char *sum  = new  char[512];
        for(int l = i1; l < i; ++l){
            strcat(sum, input[l]);
            if(l+1 !=  i){strcat(sum, " ");}
        }
        i1 = i + 1;
        arr[index] = sum;
        ++index;
        char* add = new char[2];

        add[0] = ';';
        add[1] = '\0';
        arr[index] = add;
        ++index;
    }
}

if(i1 < SIZE-1){
char *sum = new char[512];
    while (i1 < SIZE-1){
        strcat(sum, input[i1]);
        if(i1+1 != SIZE-1){strcat(sum, " ");}
        ++i1;
	}

arr[index] = sum;
++index;
}

arr[index] = NULL;
SIZE = index;

for(int i =0; i < SIZE; ++i){
    if(((strcmp(arr[i], aSym) == 0) || (strcmp(arr[i], oSym) == 0) || (strcmp(arr[i], sSym) == 0)) && (i+1 < SIZE)){
        swap(arr[i], arr[i+1]);
        if(i+2 < SIZE){
            i = i + 1 ;
        }
    }
}

return arr;

}


I



//------------------CHANGING THIS PART TO PREFIX INSTEAD OF POSTFIX----------



// to change to prefix you need to first reverse the array
// switch the paranthesis to face the oppisite way
// get the postfix expression of new revesrse
// after the postfix is done reverse that 




for(int i =0; i < SIZE-1; ++i){
    if((arr[i] == "&&" || arr[i] == "||" || arr[i] == ";") && (i+1 < SIZE-1)){
        swap(arr[i], arr[i+1]);
        if(i+2 < SIZE-1){
            i = i + 1 ;
        }
    }
}

return arr;

}

I


#endif

