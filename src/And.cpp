#include "../header/And.h"
#include "../header/Connector.h"
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

void And::display(){
	lhs->display();
	cout << "AND" <<  endl;
	rhs->display();
}

bool And::run(){
	if(lhs->run() ){
		if(rhs->run()){
			return true;
		}
		
	}
	return false;
}


void And::SetL(CMD* L){
	lhs = L;
}

void And::SetR(CMD* R){
	rhs = R;
}

