#include "Token.h"

using namespace std;


Token::Token() : CMD() {toks = NULL; cmdline = NULL;}

Token::Token(char** arr) : CMD(){
                        toks = arr;
}

Token::~Token(){}

Token& Token::operator=(const Token& t){return *this;}

void Token::display(){
	cout << "TOKEN" <<endl;
}

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
                case 0: 
                        if(execvp(toks[0], cmdline) != 0){
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
