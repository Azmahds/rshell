#include  <stdio.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <sys/wait.h>
#include <string>


#include "CMD.h"
#include "Token.h"
#include "Connector.h"
#include "And.h"
#include "Or.h"
#include "Semicolon.h"
#include "Exit.h"
#include "postfix.hpp"

using namespace std;

char** parse(string);
bool prototype(char** toks);


int main(){
  char *cmd;
  string input;
  bool run;
  vector<CMD*> command;
  vector<char*> t;
  
  while(input != "exit"){
 	 cout << "$ ";
 	 getline(cin,input);
	 string s;
	 string p;	
	 for(int i = 0; i < input.size(); ++i){
		s.push_back(input.at(i));
		if( i+1 < input.size() && input.at(i+1) == ';'){
			s.push_back(' ');
		}
         } 

	 for(int i = 0; i < s.size(); ++i){
		p.push_back(s.at(i));
		if(i == 0 && s.at(i) == '('){
			p.push_back(' ');
		} 
		if( i+1 < s.size() && s.at(i) == '('){
			p.push_back(' ');
		}
		else if(i+1< s.size() && s.at(i+1) == ')'){
			p.push_back(' ');
		}
         } 

//cout << p << endl;

 	 if(input == "exit" || input == " exit" || input == "exit " || input == " exit "){
      	     exit(0);
 	 }
  	 char **arr;
	
	 arr = parse(p);

	
 	 arr = infix_to_postfix(arr);
/*	
	int z = 0;
	while(arr[z] != NULL){
		cout << arr[z] << endl;
		++z;
	}
*/

 	CMD* tree = buildTree(arr);
//	tree->display();
	tree->run();

	
	delete [] arr;	

  }


  return 0;
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
    return array;
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




