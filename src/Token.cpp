#include "Token.h"

using namespace std;

virtual bool Token::run(){
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
                        while(!WIFEXITED(status) && !WIFSIGNALED(status)){
                                wpid = waitpid(pid, &status, WUNTRACED);
                        }
                case 0: 
			//char *arr = toks;  
			execvp(toks[0], cmdline);
			perror("EXECVP FAILURE");
			exit(false);
        }
	return true;
}
