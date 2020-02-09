#ifndef TOKEN_H
#define TOKEN_H

#include "CMD.h"

#include <iostream>

usign namespace std;

class Token : public CMD{
	public:
		virtual bool run();
		Token();
		Token(char* arr[], int size) {
			for(int i = 0; i < size; ++i){
				toks[i] = arr[i];
			}
		};
	protected:
		char* toks[64];
};

#endif
