#ifndef INPUTRED_H_
#define INPUTRED_H_


#include "CMD.h"
#include "Connector.h"

using namespace std;

class InputRed : public Connector {
public:
virtual bool run() {return false;};
InputRed() {};
~InputRed(){};
InputRed& operator=(const InputRed& i){return *this;};
virtual void SetL(CMD* L){lhs = L;};
virtual void SetR(CMD* R){rhs = R;};
void display(){
	cout << "INPUTRED" << endl;
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
