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
		void SetCmd(char **arr){cmdline = arr;};
		virtual void display(){
        		cout << "TOKEN" <<endl;
		};

	protected:
		char** toks = NULL;
		char** cmdline = NULL;
};

#endif
