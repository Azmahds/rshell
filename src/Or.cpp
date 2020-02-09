#include "Or.h"


bool Or::run(){
	if(lhs->run()){
		return true;
	}
	else if (rhs->run()){
		return true;
	}
	return false;
}
