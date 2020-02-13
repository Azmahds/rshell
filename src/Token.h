#ifndef TOKEN_H
#define TOKEN_H

#include "CMD.h"

#include <iostream>

using namespace std;

class Token : public CMD{
	public:
		Token() : CMD() {toks = NULL; cmdline = NULL;};
		Token(char** arr) : CMD(){
			toks = arr;
		};
		~Token(){};
		Token& operator=(const Token& t){return *this;};
		bool run();
		void SetCmd(char **arr){cmdline = arr;};
		void display(){
 		cout << "TOKEN" <<endl;
		};

	protected:
		char** toks;
		char** cmdline;
};

#endif
