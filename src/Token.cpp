#include "Token.h"

using namespace std;

bool Token::run(){
  	pid_t pid;
        pid_t wpid;
        int status;

        pid = fork();

        if (pid < 0){
                perror("FORK FAILURE");
                exit(false);
        }

        switch(pid){
                default:
                        while(!WIFEXITED(status)){
                                wpid = waitpid(pid, &status, WUNTRACED);
                        }
                case 0:   
			execvp(toks[0], toks);
			perror("EXECVP FAILURE");
			exit(false);
        }
	return true;
}
