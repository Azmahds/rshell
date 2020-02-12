#ifndef AND_H
#define AND_H

#include "Connector.h"

using namespace std;

class And : public Connector {
public:
virtual bool run();
And() {
	char arr[3];
	arr[0] = '&';
	arr[1] = '&';
	arr[2] = '\0';
	
	char *arr1 = arr;
	cons[0] = arr1;
	cons[1] = '\0';
};
And(char* arr){
     cons[0] = arr;
     cons[1] = '\0';
};

virtual void display(){
	cout << "AND" << endl;
};

};

#endif
