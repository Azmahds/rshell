#ifndef OR_H
#define OR_H

#include "Connector.h"

using namespace std;

class Or : public Connector {
public:
bool run();
Or();
~Or(){};
Or& operator=(const Or& o){return *this;};
Or(char* arr){
    cons[0] = arr;
    cons[1] = NULL; 
};
char* execute(){this->run();return NULL;};
virtual void SetL(CMD* L);
virtual void SetR(CMD* R);
virtual bool isCon(){return true;};
virtual bool isEx(){return false;};
virtual CMD* GetL(){return lhs;};
virtual CMD* GetR(){return rhs;};
virtual bool isAnd(){return false;};
virtual bool isOr(){return  true;};
virtual bool isSemicolon(){return false;};
virtual string GetFullTok(){return "";};
void display();
};
#endif
