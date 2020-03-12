#ifndef CMD_H
#define CMD_H

#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <cstdlib>
#include <sys/types.h>
#include <stdlib.h>

using namespace std;

class CMD {
public:
CMD() = default;
virtual ~CMD(){};
virtual CMD& operator=(const CMD& c){return *this;};
virtual bool run() = 0;
virtual FILE* execute()=0;
virtual void display() = 0;
virtual bool isCon() = 0;
virtual bool isEx() = 0;
virtual void SetL(CMD* L) = 0;
virtual void SetR(CMD* R) = 0;
virtual CMD* GetL() = 0;
virtual CMD* GetR() = 0;
virtual bool isAnd()=0;
virtual bool isOr()=0;
virtual bool isSemicolon()=0;
virtual string GetFullTok()=0;
};
#endif
