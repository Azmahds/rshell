#include  <stdio.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <sys/wait.h>

using namespace std;

void  parse(char* line, vector<char* > &t){

    char *token;
    int i = 0;


    token = strtok(line, "\0");

    cout << "outputting what is in token:  " << endl;
    for(int i = 0; i < 1024; ++i){
        if(token[i] == '\0'){
            break;
        }
        cout << token[i] << endl;
    }


    while(token[i] != '\0'){
        t.push_back(&token[i]) ;
        ++i;
    }

    for(int i = 0; i < t.size(); ++i){
        if(*(t.at(i)) == ' '){
            *(t.at(i)) = '\0';
        }
    }

    cout << "after" << endl;
    char nc = '\0';
    t.push_back(&nc);

    i = 0;

    while(*(t.at(i)) == '\0'){
        ++i;
    }

    while(*(t.at(i)) != '\0'){
        cout << *(t.at(i)) << endl;
        ++i;
    }

    cout << "done with parse" << endl;
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
vector<char* > tokens;
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

parse(cmd, tokens);

int i = 0;

char* cmd1[64];

for(unsigned j = 0; j < tokens.size(); ++j){
  cout << tokens.at(j) << endl;
}

cmd1[0] = tokens.at(0);

cout << cmd1[0] << endl;
run = prototype(cmd1);

return 0;

}

}
