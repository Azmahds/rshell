#ifndef TOKEN_H
#define TOKEN_H

#include "CMD.h"

#include <iostream>

using namespace std;

class Token : public CMD{
	public:
		Token();
		Token(char* arr);
		~Token(); // implemented
		Token& operator=(const Token& t);
		bool run();
		void display();
		string GetFullTok(){string f = full_tok; return f;};
		virtual bool isCon(){return false;};
		virtual bool isEx(){return false;};
		virtual void SetL(CMD* L){};
		virtual void SetR(CMD* R){};
		virtual CMD* GetL(){return NULL;};
		virtual CMD* GetR(){return NULL;};
		virtual bool isAnd(){return false;};
		virtual bool isOr(){return  false;};
		virtual bool isSemicolon(){return false;};
		
	protected:
		char* toks[1024];
		string full_tok = "";
};

#endif
