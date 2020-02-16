#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "CMD.h"
#include "Token.h"

using namespace std;

class Connector : public CMD {
public:
virtual bool run() = 0;
Connector() {};
Connector(char* arr){
    cons[0] = arr;
    cons[1] = '\0';
};
~Connector(){};
Connector& operator=(const Connector& c){return *this;};
virtual void SetL(CMD* L){};
virtual void SetR(CMD* R){};
string display(){
	return "CONNECTOR";
}
virtual bool isCon(){return true;};
virtual bool isEx(){return false;};

protected:
char* cons[2];
CMD* lhs;
CMD* rhs;
};

#endif

