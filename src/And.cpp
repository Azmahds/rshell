#include "And.h"

bool And::run(){
	if(lhs->run()){
		rhs->run();
		return true;
	}
	return false;
}
