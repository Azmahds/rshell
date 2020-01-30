//FOR TESTING WAITPID(), FORK(), AND EXECVP()

#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

bool prototype(char* cmd[]);

int main(){
  char* cmd1[2];
  char* cmd2[3];
  char* cmd3[4];

  cmd1[0] = "ls";
  cmd1[1] = 0;

  cmd2[0] = "ls";
  cmd2[1] = "-a";
  cmd2[2] = 0;

  cmd3[0] = "echo";
  cmd3[1] = "TEST";
  cmd3[2] = "FUNCTION";
  cmd3[3] = 0;

  cout << "STARTING TEST 1" << endl;
  if(prototype(cmd1)){cout << "Success #1" << endl << endl;}

  cout << "STARTING TEST 2" << endl;
  if(prototype(cmd2)){cout << "Success #2" << endl << endl;}

  cout << "STARTING TEST 3" << endl;
  if(prototype(cmd3)){cout << "Success #3" << endl << endl;}

  return 0;
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
