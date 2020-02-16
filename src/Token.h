#ifndef TOKEN_H
#define TOKEN_H

#include "CMD.h"

#include <iostream>

using namespace std;

class Token : public CMD{
	public:
		Token();
		Token(char* arr);
		~Token();
		Token& operator=(const Token& t);
		bool run();
		string display();
		virtual bool isCon(){return false;};
		virtual bool isEx(){return false;};
		virtual void SetL(CMD* L){};
		virtual void SetR(CMD* R){};

	protected:
		char* toks[1024];
};

#endif
