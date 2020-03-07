
#ifndef POSTFIX_HPP_
#define POSTFIX_HPP_

#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <fstream>
#include <sstream>
#include <cstring>

#include "../header/CMD.h"
#include "../header/Token.h"
#include "../header/Connector.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Semicolon.h"
#include "../header/Exit.h"
#include "../header/Test.h"

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
  char *lArr = (char*) "<";
  char *rArr = (char*) ">";
  char *drArr = (char*) ">>";
  char *pSym = (char*) "|";

  for(unsigned i = 0; i < SIZE-1; ++i){
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
    
      if(s.empty()){
	t->SetL(t->GetR());
	t->SetR(NULL);
	s.push(t);
      }
      else{
      t->SetL(s.top());
      s.pop();
      s.push(t);
      }
    }
    
    else if(strcmp(temp, lArr) == 0){
      CMD *t = new OutRed();
      t->SetR(s.top());
      s.pop();
      t->SetL(s.top());
      s.pop();
      s.push(t);
    }
    
    else if(strcmp(temp, drArr) == 0 || strcmp(temp, rArr) == 0){
      CMD *t = new InRed(temp);
      t->SetR(s.top());
      s.pop();
      t->SetL(s.top());
      s.pop();
      s.push(t);
    }

    else if(strcmp(temp, pSym) == 0){
      CMD *t = new Pipe();
      t->SetR(s.top());
      s.pop();
      t->SetL(s.top());
      s.pop();
      s.push(t);
    }

    else{
       if(temp[0] == 't' || temp[0] == 'T'){
          if(temp[1] == 'e' && temp[2] == 's' && temp[3] == 't' && temp[4] == ' '){
		CMD* t = new TestClass(temp);
		s.push(t);
	  }
	  else{
	      CMD* t = new Token(temp);
              s.push(t);
	  }
    	}
       else if(temp[0] == '['){
	 CMD* t = new TestClass(temp);
         s.push(t);
       }
       else{
	 CMD* t = new Token(temp);
         s.push(t);
	}
    }
  }

  CMD* t = s.top();
  s.pop();

  return t;
}

bool runTree(CMD* root){
	root->run();
}





char** parse(string input){
   int SIZE = 0;
   char *token = new char [input.size() + 1];
   for(int i = 0; i < input.size(); ++i){
        token[i] = input.at(i);
 	SIZE++;
   }
   token[input.size()] = '\0';

   vector<char*> t;

    for(int i = 0; i < SIZE; ++i){
      if(token[i] == '"'){
                token[i] = '+';
                for (int j = i+1; j <  SIZE; ++j){
                        if(token[j] == '"'){ i = j+1; token[j] = '+'; break;}
                        ++i;
                }
        }
      if (token[i] == ' '){
        token[i] = '+';
      }
    }

    token = strtok(token, "+");

    while(token != NULL){
      t.push_back(token);
      token = strtok(NULL, "+");
    }
   
   delete [] token;
    char **array = new char*[t.size() + 1];
    for(unsigned i = 0; i < t.size(); ++i){
         array[i] = t.at(i);
    }
    array[t.size()] = NULL;




SIZE = 0;

while(array[SIZE] != NULL){
++SIZE;
}
++SIZE;

int index = 0;
int i1 = 0;
char **arr = new char* [SIZE+1];
char *aSym = (char*) "&&";
char *oSym = (char*) "||";
char *sSym = (char*) ";";
char *opSym = (char*) "(";
char *cpSym = (char*) ")";
char *pSym = (char*) "|";
char *irSym = (char*) "<";
char *oprSym = (char*) ">";
char *doprSym = (char*) ">>";


for(int i = 0; i < SIZE-1; ++i){

     if(strcmp(array[i], aSym) == 0){
        char *sum  = new  char[64];
        int sz = 0;
	strcpy(sum, "");
        for(int l = i1; l < i; ++l){
        strcat(sum, array[l]);
        ++sz;
        if(l+1 !=  i){strcat(sum, " "); ++sz;}
        }
            i1 = i + 1;
        if(sz != 0){
        arr[index] = sum;
        ++index;
        }
        char* add = new char[3];

        add[0] = '&';
        add[1] = '&';
        add[2] = '\0';
        arr[index] = add;
        ++index;
    }
    else if(strcmp(array[i], oSym) == 0){
        char *sum  = new  char[64];
        int sz = 0;
	strcpy(sum, "");
        for(int l = i1; l < i; ++l){
            strcat(sum, array[l]);
            ++sz;
            if(l+1 !=  i){strcat(sum, " ");++sz; }
        }
        i1 = i + 1;
        if(sz != 0){
        arr[index] = sum;
        ++index;
        }
        char* add = new char[3];

        add[0] = '|';
        add[1] = '|';
        add[2] = '\0';
        arr[index] = add;
        ++index;
    }
    else if(strcmp(array[i], sSym) == 0){
        char *sum  = new  char[64];
        int sz = 0;
    	strcpy(sum, "");
        for(int l = i1; l < i; ++l){
            strcat(sum, array[l]);
            ++sz;
            if(l+1 !=  i){strcat(sum, " "); sz++;}
        }
        i1 = i + 1;
        if(sz != 0){
        arr[index] = sum;
        ++index;
        }
        char* add = new char[2];

        add[0] = ';';
        add[1] = '\0';
        arr[index] = add;
        ++index;
    }
    else if(strcmp(array[i], cpSym) == 0){
        char *sum  = new  char[64];
        int sz = 0;
        strcpy(sum, "");
        for(int l = i1; l < i; ++l){
            strcat(sum, array[l]);
                sz++;
            if(l+1 !=  i){strcat(sum, " "); sz++;}
        }
        i1 = i + 1;
        if(sz != 0){
        arr[index] = sum;
        ++index;
        }
        char* add = new char[2];

        add[0] = ')';
        add[1] = '\0';
        arr[index] = add;
        ++index;
    }
    else if(strcmp(array[i], opSym) == 0){
    char *sum  = new  char[64];
        int sz = 0;
  	strcpy(sum, "");
       for(int l = i1; l < i; ++l){
            strcat(sum, array[l]);
                ++sz;
            if(l+1 !=  i){strcat(sum, " "); ++sz;}
         }
        i1 = i + 1;

        if(sz != 0){

        arr[index] = sum;
        ++index;
        }
        char* add = new char[2];

        add[0] = '(';
        add[1] = '\0';
        arr[index] = add;
        ++index;
    }
    else if(strcmp(array[i], pSym) == 0){
    char *sum  = new  char[64];
        int sz = 0;
  	strcpy(sum, "");
       for(int l = i1; l < i; ++l){
            strcat(sum, array[l]);
                ++sz;
            if(l+1 !=  i){strcat(sum, " "); ++sz;}
         }
        i1 = i + 1;

        if(sz != 0){

        arr[index] = sum;
        ++index;
        }
        char* add = new char[2];

        add[0] = '|';
        add[1] = '\0';
        arr[index] = add;
        ++index;
    }
    else if(strcmp(array[i], irSym) == 0){
    char *sum  = new  char[64];
        int sz = 0;
  	strcpy(sum, "");
       for(int l = i1; l < i; ++l){
            strcat(sum, array[l]);
                ++sz;
            if(l+1 !=  i){strcat(sum, " "); ++sz;}
         }
        i1 = i + 1;

        if(sz != 0){

        arr[index] = sum;
        ++index;
        }
        char* add = new char[2];

        add[0] = '<';
        add[1] = '\0';
        arr[index] = add;
        ++index;
    }
    else if(strcmp(array[i], doprSym) == 0){
        char *sum  = new  char[64];
        int sz = 0;
	strcpy(sum, "");
        for(int l = i1; l < i; ++l){
            strcat(sum, array[l]);
            ++sz;
            if(l+1 !=  i){strcat(sum, " ");++sz; }
        }
        i1 = i + 1;
        if(sz != 0){
        arr[index] = sum;
        ++index;
        }
        char* add = new char[3];

        add[0] = '>';
        add[1] = '>';
        add[2] = '\0';
        arr[index] = add;
        ++index;
    }
    else if(strcmp(array[i], oprSym) == 0){
    char *sum  = new  char[64];
        int sz = 0;
  	strcpy(sum, "");
       for(int l = i1; l < i; ++l){
            strcat(sum, array[l]);
                ++sz;
            if(l+1 !=  i){strcat(sum, " "); ++sz;}
         }
        i1 = i + 1;

        if(sz != 0){

        arr[index] = sum;
        ++index;
        }
        char* add = new char[2];

        add[0] = '>';
        add[1] = '\0';
        arr[index] = add;
        ++index;
    }

}

if(i1 < SIZE-1){
    char *sum  = new  char[64];
    strcpy(sum, "");
    while (i1 < SIZE-1){
        strcat(sum, array[i1]);
        if(i1+1 != SIZE-1){strcat(sum, " ");}
        ++i1;
        }

arr[index] = sum;
++index;
}

arr[index] = NULL;
SIZE = index;

char** arr2 = new char* [SIZE + 5];
char* spSym = (char*) " ";
int j = 0;
for(int i = 0; i < SIZE; ++i){
        if(strcmp(arr[i], spSym) != 0){
                arr2[j] = arr[i];
                ++j;
        }
}
arr2[j] = NULL;
SIZE = j;

delete [] arr;

    return arr2;
}





char** infix_to_postfix(char** arr2){

stack<char*> c;

int SIZE = 0;
while(arr2[SIZE] != NULL){
++SIZE;
}
++SIZE;

char** arr3 = new char* [SIZE + 5];

char *aSym = (char*) "&&";
char *oSym = (char*) "||";
char *sSym = (char*) ";";
char *opSym = (char*) "(";
char *cpSym = (char*) ")";

char *pSym = (char*) "|";
char *irSym = (char*) "<";
char *oprSym = (char*) ">";
char *doprSym = (char*) ">>";


int s = 0;
int i = 0;
while(arr2[i] != NULL){
        if((strcmp(arr2[i], aSym) == 0) || (strcmp(arr2[i], oSym) == 0) || (strcmp(arr2[i], sSym) == 0) || (strcmp(arr2[i], opSym) == 0) ){
                c.push(arr2[i]);
        }
	else if((strcmp(arr2[i], pSym) == 0) || (strcmp(arr2[i], irSym) == 0) || (strcmp(arr2[i], oprSym) == 0) || (strcmp(arr2[i], doprSym) == 0) ){
                c.push(arr2[i]);
        }
        else if(strcmp(arr2[i], cpSym) == 0){
                while(strcmp(c.top(), opSym) != 0  && (!c.empty())){
                        arr3[s] = c.top();
                        c.pop();
                        ++s;

                }
                if(strcmp(c.top(), opSym) == 0 ){
                        c.pop();
                }
		if(!c.empty() && strcmp(c.top(), opSym) == 0 ){
		  arr3[s] = c.top();
		  c.pop();
		  s++;
		}
		

        }
        else{
                arr3[s] = arr2[i];
                ++s;
        }
++i;
}

while(!c.empty()){
        arr3[s] = c.top();
        c.pop();
        ++s;
}
arr3[s] = NULL;

delete [] arr2;

return arr3;

}


#endif

