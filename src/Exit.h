#ifndef EXIT_H
#define EXIT_H

#include "Token.h"

#include <iostream>

usign namespace std;

class Exit : public Token{
        public:
                virtual bool run();
                Exit() {ex[0] = '\n';};
		Exit(char* arr[]) {ex[0] = '\n';};
	Protected:
	char* ex[6];
};

#endif
