#ifndef PIPE_H_
#define PIPE_H_


#include "CMD.h"
#include "Connector.h"

#include <cstring>
#include <iostream>
#include <vector>
#include  <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <unistd.h>
#include  <cassert>
#include <fcntl.h>
#include <stdio.h>
using namespace std;

class Pipe : public Connector {
public:
virtual char* execute();
virtual bool run();
Pipe() {
	char* pSym = (char*)  "|";
	cons[0] = pSym;
	cons[1] = NULL;
};
~Pipe(){};
Pipe& operator=(const Pipe& p){return *this;};
virtual void SetL(CMD* L){lhs = L;};
virtual void SetR(CMD* R){rhs = R;};
void display(){
        cout << "PIPE" <<  endl;
        lhs->display();
	rhs->display();
}
virtual bool isCon(){return true;};
virtual bool isEx(){return false;};
virtual CMD* GetL(){return lhs;};
virtual CMD* GetR(){return rhs;};
virtual bool isAnd(){return  false;};
virtual bool isOr(){return  false;};
virtual bool isSemicolon(){return  false;};
virtual string GetFullTok(){return "";};

};

#endif

