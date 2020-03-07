#include "../header/Semicolon.h"
#include "../header/Connector.h"
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
	lhs->display();
        cout  <<  "SEMICOLON" << endl;
	rhs->display();
}

bool Semicolon::run(){
	lhs->run();
	if(rhs != NULL){
		rhs->run();
	}
	return true;

  
}

void Semicolon::SetL(CMD* L){
	lhs = L;
}

void Semicolon::SetR(CMD* R){
	rhs = R;
}

