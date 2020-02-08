#ifndef TOKEN_H
#define TOKEN_H

#include "CMD.h"

#include <iostream>

usign namespace std;

class Token : public CMD{
	public:
		virtual bool run();
		Token();

};

#endif
