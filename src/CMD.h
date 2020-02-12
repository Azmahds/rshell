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
virtual bool run() = 0;
CMD();
virtual void display() = 0;

};
#endif
