#ifndef AND_H
#define AND_H

#include "Connector.h"

using namespace std;

class And : public Connector {
public:
virtual bool run();
And();
And(char** arr, int size){
    for (int i =0; i < size; ++i){
        cons[i] = arr[i];
    }
};

};

#endif
