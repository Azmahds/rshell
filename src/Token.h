#ifndef TOKEN_H
#define TOKEN_H

#include "CMD.h"

#include <iostream>

using namespace std;

class Token : public CMD{
	public:
		virtual bool run();
		Token();
		Token(char** arr) {
			toks = arr;
		};

		virtual void display(){
        		cout << "TOKEN" <<endl;
		};

	protected:
		char** toks;
};

#endif
