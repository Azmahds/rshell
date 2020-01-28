#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char* argv[]){
        pid_t n = fork();
        if (n != 0) {cout << "Hello Parent" <<  endl;}
        else {waitpid(n, NULL, WNOHANG); cout << "Hello Child" << endl;}
return 0;
}
