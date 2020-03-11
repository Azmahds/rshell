#ifndef TEST_H_
#define TEST_H_


#include "CMD.h"
#include "Token.h"

#include <iostream>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include  <string>
using namespace std;

class TestClass : public Token{
	public:
		TestClass(){};
		TestClass(char* arr);
		~TestClass() {}; // implemented
		TestClass& operator=(const TestClass& t);
		bool run();
		void display();
		virtual bool isCon(){return false;};
		virtual bool isEx(){return false;};
		virtual void SetL(CMD* L){};
		virtual void SetR(CMD* R){};
		virtual CMD* GetL(){return NULL;};
		virtual CMD* GetR(){return NULL;};
		virtual bool isAnd(){return false;};
		virtual bool isOr(){return  false;};
		virtual bool isSemicolon(){return false;};
		virtual string GetFullTok(){return "";};
		char* execute(){return NULL;};
};



#endif
