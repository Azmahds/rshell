#include "Token.h"
#include <string.h>

using namespace std;


Token::Token() : CMD() {}

Token::Token(char*  arr) : CMD(){
 // arr is token
 // t is now toks but use array form instead of vector form
	int SIZE = 0;
	while(arr[SIZE] != '\0') {
		++SIZE;
	}   

	for(int i = 0; i < SIZE; ++i){
		if(arr[i] == ' '){
			arr[i] = '\0';
		}
	}
 	
	arr = strtok(arr, "\0");
	int i = 0;
	while(arr != NULL){
		toks[i] = arr;
		arr = strtok(NULL, "\0");
		++i;
	}
	
	toks[i] = '\0';

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
                        if(execvp(toks[0], toks) != 0){
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
