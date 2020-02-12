#ifndef SEMICOLON_H
#define SEMICOLON_H

#include "Connector.h"

using namespace std;

class Semicolon : public Connector {
public:
virtual bool run();
Semicolon();
Semicolon(char* arr){
    cons[0] = arr;
   cons[1] = '\0';
};

};

#endif
