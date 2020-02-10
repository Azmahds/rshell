#include  <stdio.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <vector>

#include "../src/Token.h"
#include "../src/Connector.h"
#include "../src/CMD.h"
#include "../src/And.h"
#include "../src/Or.h"
#include "../src/Semicolon.h"


using namespace std;


vector<CMD*> parse(char* line){
    vector<CMD*> vec;
    char *token;
    char toks[64];
    int j = 0, k = 0, l = 0;   
    token = strtok(line, "\n");
    
    for(int i = 0; i < 1024; ++i){
	for(int j = k; j < 1024; ++j){
	   if(token[j]  == '&'){
		l = 1;
		break;
	   }
	   if(token[j]  == '|'){
             	l = 2;
		break;
           }
           if(token[j]  == ';'){
                l = 3;
		break;
           }
	   l = 4;   
	}
        if(l == 1){
	   toks[0] = token[j];
	   toks[1] = token[j+1];
	   toks[2] = '\0';
	   char *arr = toks;
	   vec.push_back(new And(arr, 64));
	}
		
    	k = j;
    }
    
    
    return vec;
}


bool prototype(char* cmd[]){
  pid_t n;
  int status;

  n = fork();

  if(n != 0){
    waitpid(0, &status, 0);
    return true;
  }
  else{
    int l = execvp(cmd[0], cmd);
    if(l < 0){cout << "ERROR RUNNING" << endl;}
    return false;
  }
}

int main(){

   
char *cmd;
char **args;
string input;
bool run;

getline(cin,input);

if(input == "exit"){
    cout << "exiting now" << endl;
}
else{

char arr[1024];

for(int i = 0; i < 1024; ++i){
    arr[i] = input.at(i);
    if (i +1 == input.size()){
        arr[i+1] = '\0';
        break;
    }
}
cmd = arr;

for(int i = 0; i < 1024; ++i){
    if(cmd[i] == '\0'){
        break;
    }
    cout << cmd[i] << endl;
}

args = parse(cmd);
for(int i = 0; i < 10; ++i){
    if(*args[i] == '\0'){
            break;
       }
        cout << *args[i] << endl;
       }                   
run = prototype(args);
 }

      return 0;
}
