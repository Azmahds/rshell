#include "Semicolon.h"
#include "Connector.h"
using  namespace std;

Semicolon::Semicolon(){
	char arr[2];
	arr[0] = ';';
	arr[1] = '\0';

	char* arr1 = arr;
	cons[0] = arr1;
	cons[1] = '\0';
}

void Semicolon::display(){
        cout << "SEMICOLON" <<endl;
}

bool Semicolon::run(){
	lhs->run();
	//rhs->run();
	return true;

  
}

void Semicolon::SetL(Token* L){
	lhs = L;
}

//virtual void SetR(Token* R);

