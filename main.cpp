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

using namespace std;

vector<char*> parse(char* token);
bool prototype(vector<char*> toks);
vector<CMD*> SetClasses(vector<char*> cline);

int main(){
  char *cmd;
  vector<char*> tokens;
  string input;
  bool run;
  vector<CMD*> command;

  cout << "$ ";
  getline(cin,input);

  if(input == "exit"){
      cout << "exiting now" << endl;
  }

  char arr[input.size()];
  for(int i = 0; i < input.size(); ++i){
    arr[i] = input.at(i);
  }
  arr[input.size()] = '\0';

  cmd = arr;

  tokens = parse(cmd);
  
  command = SetClasses(tokens);
  
  return 0;
}

vector<CMD*> SetClasses(vector<char*> cline){
  vector<CMD*> cmd;
  char *arr[cline.size()];
 
  for(unsigned i = 0; i < cline.size(); ++i){
	arr[i] = cline.at(i);
  }
  arr[cline.size()] = '\0';

  Token* temp = new Token();
  cmd.push_back(temp->SetCmd(arr));

cout << cmd.at(0) << endl; 
}
	

vector<char*> parse(char *token){
    vector<char*> t;
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

    while(token != NULL){
      t.push_back(token);
      token = strtok(NULL, "+");
    }
    return t;
}



bool prototype(vector<char*> toks){
  pid_t pid;
  pid_t wpid;
  int status;
  char *cmd[toks.size()];

  pid = fork();
  if (pid < 0){
          perror("FORK FAILURE");
          exit(false);
  }

  switch(pid){
          case 0:
        			execvp(cmd[0], cmd);
        			perror("EXECVP FAILURE");
        			exit(false);
          default:
                  while(!WIFEXITED(status) && !WIFSIGNALED(status)){
                          wpid = waitpid(pid, &status, WUNTRACED);
                  }
  }
	return true;
}
