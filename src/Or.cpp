#include "../header/Or.h"
#include "../header/Connector.h"
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
	lhs->display();
	cout << "OR" << endl;
	rhs->display();
}

bool Or::run(){
	if(lhs->run() == true){
		return true;
	}
	else if (rhs->run() == true){
		return true;
	}
	return false;
}

void Or::SetL(CMD* L){
	lhs = L;
}
void Or::SetR(CMD* R){
	rhs = R;
}

