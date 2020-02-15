#ifndef SEMICOLON_H
#define SEMICOLON_H

#include "Connector.h"

using namespace std;

class Semicolon : public Connector {
public:
bool run();
Semicolon();

Semicolon(char* arr){
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
