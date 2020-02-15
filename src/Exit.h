#ifndef EXIT_H
#define EXIT_H

#include "Token.h"

#include <iostream>

usign namespace std;

class Exit : public Token{
        public:
                bool run();
                Exit() {ex[0] = '\n';};
		Exit(char* arr[]) {ex[0] = '\n';};
		virtual bool isCon(){return false;};
		virtual bool isEx(){return true;};
	Protected:
	char* ex[6];
};

#endif
