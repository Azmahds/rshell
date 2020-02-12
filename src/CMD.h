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
protected:
char **cmdline = NULL;

public:
virtual bool run() = 0;
CMD();
CMD(char** line){cmdline = line;};

virtual void display(){
	cout << "CMD" << endl;
};

};
#endif
