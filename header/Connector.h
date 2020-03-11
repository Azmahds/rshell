#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "CMD.h"
#include "Token.h"


#include <iostream>
#include <vector>
#include  <string>
#include  <cstring>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <unistd.h>
#include  <cassert>
#include <fcntl.h>
#include <stdio.h>
using namespace std;

class Connector : public CMD {
public:
virtual bool run() = 0;
char* execute(){return NULL;};
Connector() {};
Connector(char* arr){
    cons[0] = arr;
    cons[1] = NULL;
};
~Connector(){};
Connector& operator=(const Connector& c){return *this;};
virtual void SetL(CMD* L){};
virtual void SetR(CMD* R){};
void display(){
	cout << "CONNECTOR" << endl;
}
virtual bool isCon(){return true;};
virtual bool isEx(){return false;};
virtual CMD* GetL(){return lhs;};
virtual CMD* GetR(){return rhs;};
virtual bool isAnd()=0;
virtual bool isOr()=0;
virtual bool isSemicolon()=0;
virtual string GetFullTok(){return "";};

protected:
char* cons[2];
CMD* lhs = NULL;
CMD* rhs = NULL;
};

#endif

