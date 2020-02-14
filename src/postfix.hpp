#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <fstream>
#include <sstream>

using namespace std;

/*
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
*/

char** infix_to_postfix(char** input){
   stack<char*> s;
   ostringstream oss;
   int SIZE = 0;
   
   while(input[i] != NULL){
	++SIZE;
   }
   
   int index = 0;
   int i1 = 0;
   char *arr[SIZE];
   char *aSym = (char*) "&&";
   char *oSym = (char*) "||";
   char *sSym = (char*) ";"; 

   for(int i = 0; i < SIZE; ++i){
	if(strcmp(input[i], aSym) == 0){
 	    char *sum = new char[512];
	    for(int l = i1; l < i; ++l){
		strcat(sum, input[l]);
		if(l+1 !=  i){strcat(sum, ' ');}
	    }
            i1 = i + 1;
	    arr[index] = sum;
	    ++index;
	    arr[index] = new (char*) "&&";
	    ++index;
        }
        else if(strcmp(input[i], oSym) == 0){
	    char *sum  = new  char[512];
            for(int l = i1; l < i; ++l){
                strcat(sum, input[l]);
                if(l+1 !=  i){strcat(sum, ' ');}
            }
            i1 = i + 1;
            arr[index] = sum;
            ++index;
	    arr[index] = new (char*) "||";
            ++index;
        }
        else if(strcmp(input[i], sSym) == 0){
		cout << "L SNZ BOIZZZZ" << endl;
        }	
   }
   if(i1 < SIZE){
 	char *sum = new char[512];
        while (i1 < SIZE){
	     strcat(sum, input[i1];
	     if(i1+1 != SIZE){strcat(sum, ' ');}
	     ++i1;
	}
	arr[index] = sum;
	++index;
   }
   arr[index] = '\0';
   SIZE = index;   
 








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


/*
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
*/
