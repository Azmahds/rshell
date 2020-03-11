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
     cons[1] = NULL;
};

void display();
char* execute(){return NULL;};
virtual void SetL(CMD* L);
virtual void SetR(CMD* R);
virtual bool isCon(){return true;};
virtual bool isEx(){return false;};
virtual CMD* GetL(){return lhs;};
virtual CMD* GetR(){return rhs;};
virtual bool isAnd(){return true;};
virtual bool isOr(){return  false;};
virtual bool isSemicolon(){return false;};
virtual string GetFullTok(){return "";};
};

#endif
