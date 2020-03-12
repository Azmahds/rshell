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
#include "../header/InRed.h"
#include "../header/OutRed.h"
#include "../header/Pipe.h"

using namespace std;

string edit_string(string);

int main(){
  char *cmd;
  string input, p;
  bool run;
  vector<CMD*> command;
  vector<char*> t;
  
  while(input != "exit"){
 	 cout << "$ ";
 	 getline(cin,input);
	
	p = edit_string(input);
//cout << p << endl;
	if(p == "UNEVEN NUMP"){
		cout << "ERROR: UNEVEN PARENTHESES" << endl;

	}
	else{
 	 char **arr;
	
	 arr = parse(p);
	
/*	
	int z = 0;
	while(arr[z] != NULL){
		cout << arr[z] << endl;
		++z;
	}
*/		
	arr = infix_to_postfix(arr);

 	CMD* tree = buildTree(arr);

	tree->display();	

	delete [] arr;
	}
	
  }

  return 0;
}	



string edit_string(string input){
	 string s;
	 string x;
	 string p;
	 int nump = 0;	
	
	 if(input.at(input.size() - 1) == ';'){
		input.at(input.size() - 1) = ' ';
	 }

/*
	int n = 0;
	for(int i = 0; i < input.size();++i){
		x.push_back(input.at(i));
		for(n = i+1;  n < input.size()-1;  ++n){
			if((n+1 < input.size()) && (input.at(n)  ==  '&' && input.at(n+1)  == '&') ||  (input.at(n)  ==  '|' && input.at(n+1)  == '|') || input.at(n)  ==  ';' 
			|| (input.at(n)  ==  '|' && input.at(n-1) != '|') || input.at(n)  ==  '>' || input.at(n)  ==  '<'){break;}
		}

		if(input.at(i) == '|' || input.at(i) == ';' || input.at(i) == '&'){
			if(input.at(i+1) == '|' || input.at(i+1) == '&'){
				++i;
				x.push_back(input.at(i));
			}
			if(i == n){}
			else{
				if(input.at(n) == '<'){
					int  o = 0;
					for (o = n+1; o < input.size(); ++o){
						if(input.at(o) == '&' || input.at(o) == '|' || input.at(o) == ';' || input.at(o) == '>' || input.at(o) == '<'){break;}	
					}
	        			if(input.at(o) == '>'){
						x.push_back(' ');
						x.push_back('(');
						x.push_back('(');
						int l = 0;
						for(l = i+1;  l < o; ++l){
							x.push_back(input.at(l));
						}
						i = l-1;
						x.push_back(')');
						x.push_back(' ');
						for(l = i+3; l < input.size(); ++l){
						if(input.at(l) == '&' || input.at(l) == '|' || input.at(l) == ';' || input.at(l) == '>' || input.at(l) == '<'){break;}	
						}
						for(o = i+1; o < l; ++o){x.push_back(input.at(o));}
						i = o -1;
						x.push_back(')');
						x.push_back(' ');	
					}	
					else{
						x.push_back(' ');
						x.push_back('(');
						int l = 0;
						for(l = i+1;  l < o; ++l){
							x.push_back(input.at(l));
						}
						i = l-1;
						x.push_back(')');
						x.push_back(' ');
					}
				}
				else if(input.at(n) ==  '>' && input.at(n+1) != '>'){
					x.push_back(' ');
					x.push_back('(');
					int  k = 0;
					for (k = n+1; k < input.size(); ++k){
						if(input.at(k) == '&' || input.at(k) == '|' || input.at(k) == ';' || input.at(k) == '>' || input.at(k) == '<'){break;}	
					}
					int l = 0;
					for(l = i+1;  l < k; ++l){
						x.push_back(input.at(l));
					}
					i = l-1;
					x.push_back(')');
					x.push_back(' ');
				}
				else if(input.at(n) == '>' && input.at(n+1) == '>'){
					x.push_back(' ');
					x.push_back('(');
					int  k = 0;
					for (k = n+2; k < input.size(); ++k){
						if(input.at(k) == '&' || input.at(k) == '|' || input.at(k) == ';' || input.at(k) == '>' || input.at(k) == '<'){break;}	
					}
					int l = 0;
					for(l = i+1;  l < k; ++l){
						x.push_back(input.at(l));
					}
					i = l-1;
					x.push_back(')');
					x.push_back(' ');
				}
			}
		}
		else if(input.at(i) == '<'){
			if(input.at(n) == '>'){
				int m = 0;
				for(m = x.size()-2; m > -1; --m){
					if(x.at(m) == '&' || x.at(m) == '|' || x.at(m) == ';' || x.at(m) == '>' || x.at(m) == '<'){break;}
				}
				m += 1;
				x.insert(m, " (( ");
				for (m = i+1; m < n; ++m){x.push_back(input.at(m));}
				x.push_back(')');
				x.push_back(' ');			
				i = m;
				int next = 0;
				for (next = n+2; next < input.size(); ++next){
					if(input.at(next) == '&' || input.at(next) == '|' || input.at(next) == ';' || input.at(next) == '>' || input.at(next) == '<'){break;}	
				}
				for(m = i; m < next; ++m){x.push_back(input.at(m));}
				i = m -1;
				x.push_back(')');
				x.push_back(' ');			
			}
		}		 
	}
*/
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
		p = "UNEVEN NUMP";
	}	

	return p;
}
