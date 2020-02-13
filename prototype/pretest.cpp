#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <fstream>
#include <sstream>

using namespace std;

void arithmeticExpression::buildTree(){
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


string arithmeticExpression::infix_to_postfix(){
   stack<char> s;
   ostringstream oss;
   char c;
   for(unsigned i = 0; i< infixExpression.size();++i){
       c = infixExpression.at(i);
       if(c == ' '){
           continue;
       }
       if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
           if( c == '('){
               s.push(c);
           }
           else if(c == ')'){
               while(s.top() != '('){
                   oss << s.top();
                   s.pop();
               }
               s.pop();
           }
           else{
               while(!s.empty() && priority(c) <= priority(s.top())){
                   if(s.top() == '('){
                       break;
                   }
                   oss << s.top();
                   s.pop();
               }
               s.push(c);
           }
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

void arithmeticExpression::infix(TreeNode *node){ //left cur right
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

