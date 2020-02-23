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
		if(arr[i] == '"'){
			arr[i] =  '+';
			for(unsigned j =  i +  1; j <  SIZE; ++j){
				if(arr[j] == '"'){
					arr[j] = '+';
					i = j + 1;
				}
			}
		}

		if(arr[i] == ' '){
			arr[i] = '+';
		}
	}
 	
	arr = strtok(arr, "+");
	int i = 0;
	while(arr != '\0'){
		toks[i] = arr;
		arr = strtok(NULL, "+");
		++i;
	}
	
	toks[i] = NULL;

}


Token::~Token(){}

Token& Token::operator=(const Token& t){return *this;}

string Token::display(){
	string t = "TOKEN";
	return t;
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
				return false;
                        	exit(false);
                        }
		default:
                        if(waitpid(pid, &status, WUNTRACED) < 0){
                        	perror("CHILD IN PROCESS");        
                        }
			if(WIFEXITED(status)){
				return true;
			}else{return false;}
        }
	return false;
}
