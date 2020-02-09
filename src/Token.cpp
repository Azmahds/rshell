#include "Token.h"

using namespace std;

bool Token::run(){
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
