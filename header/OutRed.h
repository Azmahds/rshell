#ifndef OUTRED_H_
#define OUTRED_H_


#include "CMD.h"
#include "Connector.h"

using namespace std;

class OutRed : public Connector {
public:
virtual bool run() {return false;};
OutRed() {};
~OutRed(){};
OutRed& operator=(const OutRed& o){return *this;};
virtual void SetL(CMD* L){lhs = L;};
virtual void SetR(CMD* R){rhs = R;};
void display(){
	cout << "OUTRED" << endl;
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

