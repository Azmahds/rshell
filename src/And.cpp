#include "And.h"
#include "Connector.h"
using namespace std;

And::And() {
	char arr[3];
	arr[0] = '&';
	arr[1] = '&';
	arr[2] = '\0';
	
	char *arr1 = arr;
	cons[0] = arr1;
	cons[1] = '\0';
}

string And::display(){
	return "AND";
}

bool And::run(){
	if(lhs->run()){
		rhs->run();
		return true;
	}
	return false;
}


void And::SetL(Token* L){
	lhs = L;
}

void And::SetR(Token* R){
	rhs = R;
}

