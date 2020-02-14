#include  <stdio.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <sys/wait.h>

#include "src/CMD.h"
#include "src/Token.h"
#include "src/Connector.h"
#include "src/And.h"
#include "src/Or.h"
#include "src/Semicolon.h"
//#include "src/postfix.hpp"

using namespace std;

vector<CMD*> parse(string);
bool prototype(char** toks);

int main(){
  string input;
  bool run;
  vector<CMD*> command;
  vector<char*> t;
  
  while(input != "exit"){
 	 cout << "$ ";
 	 getline(cin,input);

 	 if(input == "exit"){
 	     break;
 	 }
  	 command = parse(input);
 	//if(prototype(arr)){}
  }


  return 0;
}	

vector<CMD*>  parse(string input){
   char *token = new char [input.size()];
   for(int i = 0; i < input.size(); ++i){
    	token[i] = input.at(i);
   }
   token[input.size()] = '\0';    

   vector<char*> t;
   vector<CMD*> c;
			
    int SIZE = 0;	
    while(token[SIZE] != '\0'){
      ++SIZE;
    }

    for(int i = 0; i < SIZE; ++i){
      if (token[i] == ' '){
        token[i] = '+';
      }
    }

    token = strtok(token, "+");
    int i = 0;
    while(token != NULL){
      t.push_back(token);
      token = strtok(NULL, "+");
    }
    
    vector<char*> tok;
    char *aSym = (char*) "&&";
    char *oSym = (char*) "||";
    char *sSym = (char*) ";";
    CMD* temp = NULL; 
    Token* hs = NULL;

   for(int i = 0; i < t.size(); ++i){
	if(strcmp(t.at(i), aSym) == 0){
//	 temp = new Token(tok);
//	 c.push_back(temp);
//	 hs = temp; 
//	 temp = new And();
//	 temp->SetL(hs);
	 
	}
	else if(strcmp(t.at(i), oSym) == 0){

        }
	else if(strcmp(t.at(i), sSym) == 0){

        }
	tok.push_back(t.at(i));
    }    

    
    return c;
}



bool prototype(char** toks){
  pid_t pid;
  pid_t wpid;
  int status;

  pid = fork();
  if (pid < 0){
          perror("FORK FAILURE");
          exit(false);
  }

  switch(pid){
          case 0:
        	if(execvp(toks[0], toks) != 0){
        		perror("EXECVP FAILURE");
        		exit(false);
		}
		exit(true);
          default:
                  if (waitpid(pid, &status, WUNTRACED) < 0){
                          perror("CHILD IN PROGRESS");
                  }
		  if(WIFEXITED(status)){
			return true;
		  }
  }
	return true;
}

