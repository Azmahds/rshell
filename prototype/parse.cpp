#include  <stdio.h>
#include <cstring>
#include <iostream>
#include <unistd.h>


using namespace std;

void  parse(char *cmd, char **toks){
     while (*cmd != '\0') {   
          while (*cmd == ' '){
               *cmd++ = '\0';
          }

          *toks++ = cmd;

          while (*cmd != '\0' && *cmd != ' '){
               cmd++;
          }
     }
}

int main(){
     char  cmd[500];             
     char  *toks[50];              

     while ((strcmp(toks[0], "exit") != 0)) {                   
          cout << "$" ;  
          gets(cmd); 
          cout << endl;
          parse(cmd, toks); 
     }

return 0;
}
