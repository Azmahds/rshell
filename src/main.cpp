#include  <stdio.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <sys/wait.h>

#include "CMD.h"
#include "Token.h"
#include "Connector.h"
#include "And.h"
#include "Or.h"
#include "Semicolon.h"

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
	 char space = ' ';
	 for(int i = 0; i < input.size(); ++i){
		s.push_back(input.at(i));
		if( i+1 < input.size() && input.at(i+1) == ';'){
			s.push_back(space);
		}
         } 
	 if(s.at(s.size()-1) == ';'){
		s.push_back(space);
	 }
 	 if(input == "exit" || input == " exit" || input == "exit " || input == " exit "){
 	     break;
 	 }
  	 char **arr;
	
 	cout << "OUTPUTTING WHAT IS IN INPUT AFTER EXC" <<s << endl;  

	 arr = parse(s); 
	
//	int i = 0;
//	while(arr[i] != '\0' ){
//		cout << arr[i] << endl;
//		i++;
//	}
 //	if(prototype(arr)){}
  }


  return 0;
}	







char** parse(string input){
   char *token = new char [input.size()+1];
   for(int i = 0; i < input.size(); ++i){
        token[i] = input.at(i);
   }
   token[input.size()+1] = '\0';

   vector<char*> t;

    int SIZE = 0;
    while(token[SIZE] != '\0'){
      ++SIZE;
    }

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

    char **array = new char*[t.size()];
    for(unsigned i = 0; i < t.size(); ++i){
         array[i] = t.at(i);
    }
    array[t.size()] = '\0';
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
