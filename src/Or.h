#ifndef OR_H
#define OR_H

#include "Connector.h"

using namespace std;

class Or : public Connector {
public:
virtual bool run();
Or();
Or(char* arr[], int size){
    for (int i =0; i < size; ++i){
        cons[i] = arr[i];
    }   
};

};

#endif
