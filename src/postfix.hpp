#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <fstream>
#include <sstream>

using namespace std;

void buildTree(){
  string s;
  s = infix_to_postfix();
  stack<TreeNode*> r;

  for(unsigned i = 0; i < s.size(); ++i){
    char l = 'a' + i;
    TreeNode *temp = new TreeNode(s.at(i), l);

    if(priority(temp->data) == 0){
      r.push(temp);
    }
    else{
      temp ->right = r.top();
      r.pop();
      temp->left = r.top();
      r.pop();
      r.push(temp);
    }
  }
  root = r.top();
  r.pop();
}


string infix_to_postfix(char** input){
   stack<char*> s;
   ostringstream oss;
   int SIZE = 0;
   
   while(input[i] != NULL){
	++SIZE;
   }
   
   int index = 0;
   int s1 = -1;
   int s2 = -1;
   char *arr[SIZE];
   char *aSym = (char*) "&&";
   char *oSym = (char*) "||";
   char *sSym = (char*) ";"; 

   for(int i = 1; i <= SIZE; ++i){
	//bool one = false, two = false;
        //int s1 = -1;
   	//int s2 = -1;
	char* t2 = input[i];
	char* t1 = input[i-1];
	//for(unsigned j = 0; t1[j] != '\0'; ++j){
	//	if(t1[j] == ';'){
	//		s1 = j;
	//		one = true;
	//	}
	//}
	if(strcmp(input[i], aSym) == 0){
 					
        }
        else if(strcmp(input[i], oSym) == 0){

        }
        else if(strcmp(input[i], sSym) == 0){

        }	
   }
    
   for(unsigned i = 0; i < input.size();++i){
       c = input.at(i);
       if(c == ' '){
           continue;
       }
       if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
             while(!s.empty() && priority(c) <= priority(s.top())){
                 if(s.top() == '('){
                     break;
                 }
                 oss << s.top();
                 s.pop();
             }
             s.push(c);
           
       }
       else{ //c is an operand
           oss << c;
       }
   }
   while(!s.empty()){
       oss << s.top();
       s.pop();
   }
   return oss.str();
 }

void infix(TreeNode *node){ //left cur right
  if(node == NULL){
    return;
  }

  if(node->left != NULL){
    cout << "(";
    infix(node->left);
  }

  cout << node->data;

  if(node->right != NULL){
    infix(node->right);
    cout << ")";
  }
}
