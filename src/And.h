#ifndef AND_H
#define AND_H

#include "Connector.h"

using namespace std;

class And : public Connector {
public:
bool run();
And();
And(char* arr){
     cons[0] = arr;
     cons[1] = '\0';
};

void display();

virtual void SetL(Token* L);
virtual void SetR(Token* R);


};

#endif
