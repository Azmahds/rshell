//FOR TESTING WAITPID(), FORK(), AND EXECVP()

#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char* argv[]){
        pid_t n = fork();
        if (n == 0) {cout << "Hello Child" <<  endl;}
        else if(n > 0) {waitpid(n, NULL, WNOHANG); cout << "Hello Parent" << endl;}
        else {cout << "Error" << endl;}

        //int execvp(argv[2], argv[]);
        //cout << "END" << endl;

//      pid_t child_pid;
//      child_pid = fork ();
//      if (child_pid != 0){
//              cout << "parent" <<endl;
//      }
//      else{
//              waitpid(child_pid, NULL,WNOHANG);
//              cout << "after wait child"<<endl;
//      }

  return 0;
}
