#ifndef SEMICOLON_H
#define SEMICOLON_H

#include "Connector.h"

using namespace std;

class Semicolon : public Connector {
public:
virtual bool run();
Semicolon();
Semicolon(char* arr[], int size){
    for (int i =0; i < size; ++i){
        cons[i] = arr[i];
    }
};

};

#endif
