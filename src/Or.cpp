#include "Or.h"
#include "Connector.h"
using namespace std;

Or::Or() {
	char arr[3];
	arr[0] = '|';
	arr[1] = '|';
	arr[2] = '\0';

	cons[0] = arr;
	cons[1] = '\0';
}

void Or::display(){
	cout << "OR" <<endl;
}

bool Or::run(){
	if(lhs->run()){
		return true;
	}
	else if (rhs->run()){
		return true;
	}
	return false;
}
