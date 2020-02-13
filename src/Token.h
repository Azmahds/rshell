#ifndef TOKEN_H
#define TOKEN_H

#include "CMD.h"

#include <iostream>

using namespace std;

class Token : public CMD{
	public:
		Token();
		Token(char** arr);
		~Token();
		Token& operator=(const Token& t);
		bool run();
		void display();

	protected:
		char** toks;
		char** cmdline;
};

#endif
