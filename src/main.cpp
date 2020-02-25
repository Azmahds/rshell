#include  <stdio.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <sys/wait.h>
#include <string>


#include "CMD.h"
#include "Token.h"
#include "Connector.h"
#include "And.h"
#include "Or.h"
#include "Semicolon.h"
#include "Exit.h"
#include "postfix.hpp"

using namespace std;


int main(){
  char *cmd;
  string input;
  bool run;
  vector<CMD*> command;
  vector<char*> t;
  
  while(input != "exit"){
 	 cout << "$ ";
 	 getline(cin,input);
	 string s;
	 string p;	
	 for(int i = 0; i < input.size(); ++i){
		s.push_back(input.at(i));
		if( i+1 < input.size() && input.at(i+1) == ';'){
			s.push_back(' ');
		}
         } 

	 for(int i = 0; i < s.size(); ++i){
		p.push_back(s.at(i));
		if(i == 0 && s.at(i) == '('){
			p.push_back(' ');
		} 
		if( i+1 < s.size() && s.at(i) == '('){
			p.push_back(' ');
		}
		else if(i+1< s.size() && s.at(i+1) == ')'){
			p.push_back(' ');
		}
         } 

  	 char **arr;
	
	 arr = parse(p);

	
 	 arr = infix_to_postfix(arr);
/*	
	int z = 0;
	while(arr[z] != NULL){
		cout << arr[z] << endl;
		++z;
	}
*/

 	CMD* tree = buildTree(arr);
//	tree->display();
	tree->run();	
	delete [] arr;	
  }

  return 0;
}	

