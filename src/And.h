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

string display();

virtual void SetL(CMD* L);
virtual void SetR(CMD* R);
virtual bool isCon(){return true;};
virtual bool isEx(){return false;};

};

#endif
