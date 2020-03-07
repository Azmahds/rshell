#ifndef INPUTRED_H_
#define INPUTRED_H_


#include "CMD.h"
#include "Connector.h"

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class InRed : public Connector {
public:
virtual bool run() {return false;};
InRed() {};
InRed() { 
	char* lArr = (char*) "<";
	cons[0] = lArr;
	cons[1] = NULL;
};
~InRed(){};
InRed& operator=(const InRed& i){return *this;};
virtual void SetL(CMD* L){lhs = L;};
virtual void SetR(CMD* R){rhs = R;};
void display(){
	cout << "INPUTRED" << endl;
	lhs->display();
        rhs->display();
}
virtual bool isCon(){return true;};
virtual bool isEx(){return false;};
virtual CMD* GetL(){return lhs;};
virtual CMD* GetR(){return rhs;};
virtual bool isAnd(){return  false;};
virtual bool isOr(){return  false;};
virtual bool isSemicolon(){return  false;};

};

#endif
