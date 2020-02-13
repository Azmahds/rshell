#ifndef OR_H
#define OR_H

#include "Connector.h"

using namespace std;

class Or : public Connector {
public:
bool run();
Or();
~Or(){};
Or& operator=(const Or& o){return *this;};
Or(char* arr){
    cons[0] = arr;
    cons[1] = '\0'; 
};

void display();
};
#endif
