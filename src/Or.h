#ifndef OR_H
#define OR_H

#include "Connector.h"

using namespace std;

class Or : public Connector {
public:
virtual bool run();
Or();
Or(char* arr){
    cons[0] = arr;
    cons[1] = '\0'; 
};

};

#endif
