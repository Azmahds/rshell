#ifndef EXIT_H
#define EXIT_H

#include "Token.h"

#include <iostream>

using namespace std;

class Exit : public Token{
        public:
                bool run() { exit(0); }
                Exit(){ex[0] = NULL;};
		~Exit(){};
		Exit& operator=(const Exit& e){return *this;};
		void display(){ cout  << "TODO" <<  endl; };
		virtual bool isCon(){return false;};
		virtual bool isEx(){return true;};
		virtual void SetL(CMD* L){};
		virtual void SetR(CMD* R){};
		virtual CMD* GetL(){return NULL;};
                virtual CMD* GetR(){return NULL;};
		virtual bool isAnd(){return false;};
		virtual bool isOr(){return  false;};
		virtual bool isSemicolon(){return false;};
		virtual string GetFullTok(){return "";};

	protected:
	char* ex[6];
};

#endif
