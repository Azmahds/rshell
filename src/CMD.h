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
virtual ~CMD() = default;
virtual CMD& operator=(const CMD& c) = default;
virtual bool run() = 0;
virtual void display() = 0;
virtual void SetCmd(char** arr) = 0;
};
#endif
