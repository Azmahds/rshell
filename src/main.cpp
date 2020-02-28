#include  <stdio.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <sys/wait.h>
#include <string>


#include "../header/CMD.h"
#include "../header/Token.h"
#include "../header/Connector.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Semicolon.h"
#include "../header/Exit.h"
#include "postfix.hpp"
#include "../header/Test.h"

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
	 int nump = 0;	
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
	
	for(int i =0; i < p.size(); ++i){
		if(p.at(i) == '(' || p.at(i) == ')'){
			++nump;
		}
	
	}

	if(nump % 2 != 0){
		cout << "ERROR: UNEVEN PARENTHESES" << endl;

	}
	else{
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
	
  }

  return 0;
}	
