#include  <stdio.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <sys/wait.h>

using namespace std;

vector<char*> parse(char* token);

bool prototype(vector<char*> toks);

int main(){
  char *cmd;
  vector<char*> tokens;
  string input;
  bool run;

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

//  cout << endl << "VECTOR: " << endl;
//  for(unsigned j = 0; j < tokens.size(); ++j){
//   cout << tokens.at(j) << endl;
//  }
//  cout << "END VECTOR" << endl << endl;


  if(prototype(tokens)){cout << "SUCCESS" << endl;}
//  else {cout << "FAILURE" << endl;}

  return 0;
}

vector<char*> parse(char *token){
    vector<char*> t;
    int SIZE = 0;

    while(token[SIZE] != '\0'){
      ++SIZE;
    }

    for(int i = 0; i < SIZE; ++i){
      if (token[i] == ' '){
        token[i] = '-';
      }
    }

    token = strtok(token, "-");

    while(token != NULL){
      t.push_back(token);
      token = strtok(NULL, "-");
    }
    return t;
}

bool prototype(vector<char*> toks){
  pid_t pid;
  pid_t wpid;
  int status;
  char *cmd[toks.size()];

//  cout << "CMD: " << endl;
//  for(unsigned i = 0; i < toks.size(); ++i){
//    cmd[i] = toks.at(i);
//    cout << cmd[i] << endl;
//  }

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

