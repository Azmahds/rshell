#include  <stdio.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <sys/wait.h>

using namespace std;

vector<char*> parse(char* token);

bool prototype(char **toks);

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
  char *arr1[3];
  char *arr2[64];
	
  arr1[0] =  "ls";
  arr1[1] =  "-a";
  arr1[2] =  '\0';

  arr2[0] =  "ls";
  arr2[1] =  "-a";
  arr2[2] =  "&&";
  arr2[3] = "echo";
  arr2[4] =  "hello";
  arr2[5] = '\0';

  if(prototype(arr1)){cout << "SUCCESS" << endl;}
  else {cout << "FAILURE" << endl;}

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

bool prototype(char **toks){
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
                        if(waitpid(pid, &status, WUNTRACED) < 0){
                        	perror("CHILD IN PROCESS");        
                        }
			if(WIFEXITED(status)){
				return true;
			}
        }
	return true;
}

