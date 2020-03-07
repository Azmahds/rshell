#ifndef PIPE_H_
#define PIPE_H_


#include "CMD.h"
#include "Connector.h"

using namespace std;

class Pipe : public Connector {
public:
virtual bool run() {return false;};
Pipe() {};
~Pipe(){};
Pipe& operator=(const Pipe& p){return *this;};
virtual void SetL(CMD* L){lhs = L;};
virtual void SetR(CMD* R){rhs = R;};
void display(){
	cout << "PIPE" << endl;
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

