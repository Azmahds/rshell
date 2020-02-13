#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "CMD.h"
#include "Token.h"

using namespace std;

class Connector : public CMD {
public:
bool run();
Connector();
Connector(char* arr){
    cons[0] = arr;
    cons[1] = '\0';
};
void SetL(Token* L){lhs = L;};
void SetR(Token* R){rhs = R;};

protected:
char* cons[2];
Token* lhs;
Token* rhs;
};

#endif

