#ifndef SEMICOLON_H
#define SEMICOLON_H

#include "Connector.h"

using namespace std;

class Semicolon : public Connector {
public:
virtual bool run();
Semicolon(){
	char arr[2];
	arr[0] = ';';
	arr[1] = '\0';

	char* arr1 = arr;
	cons[0] = arr1;
	cons[1] = '\0';
};

Semicolon(char* arr){
    cons[0] = arr;
   cons[1] = '\0';
};

};

#endif
