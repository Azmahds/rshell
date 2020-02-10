#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "CMD.h"
#include "Token.h"

using namespace std;

class Connector : public CMD {
public:
virtual bool run();
Connector();
Connector(char* arr[], int size){
    for (int i =0; i < size; ++i){
        cons[i] = arr[i];
    }   
};
void SetL(Token* L){lhs = L;};
void SetR(Token* R){rhs = R;};

protected:
char* cons[64];
Token* lhs;
Token* rhs;
};

#endif

