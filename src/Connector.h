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
void SetL(Token* L){lhs = L;};
void SetR(Token* R){rhs = R;};
void display(){
	cout << "Connector" << endl;
}


protected:
char* cons[2];
Token* lhs;
Token* rhs;
};

#endif

