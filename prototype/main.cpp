#include  <stdio.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>




using namespace std;


char** parse(char* line){
    char** toks[64];
    char *token;
    int i = 0;

    token = strtok(line, "\n");
    toks[i] = token;
    ++i;

    return toks;
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
run = prototype(args);
}

return 0;

}
