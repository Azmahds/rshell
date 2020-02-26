#include "../head/Test.h"


#include <iostream>

using namespace std;


TestClass::TestClass(char *arr){
	int SIZE = 0;
        while(arr[SIZE] != '\0') {
                ++SIZE;
        }
	if(arr[0] == 't' || arr[0] == 'T'){
		for(unsigned i = 0; i < 4; ++i){
			arr[i] = '+';
		}
	}
        for(int i = 0; i < SIZE; ++i){
                if(arr[i] == ' ' || arr[i] == '[' || arr[i] == ']'){
                        arr[i] = '+';
                }
        }

        arr = strtok(arr, "+");
        int i = 0;
        while(arr != '\0'){
                toks[i] = arr;
                arr = strtok(NULL, "+");
                ++i;
        }
	

	if(i < 2){
	  toks[i] =  toks[i-1];
	  char *eFlag = new char[2];
	  eFlag[0] = '-';
	  eFlag[1] = 'e';
	  eFlag[2] = '\0';
	  toks[i-1] = eFlag;
	  ++i; 
	}
        toks[i] = NULL;

}


bool TestClass::run(){
	struct stat buf;
        int num = -1;
	char *eFlag =  (char*) "-e";
	char *dFlag =  (char*) "-d";
	char *fFlag =  (char*) "-f";        

	num = stat(toks[1], &buf);
	
	if(num == -1){
		cout << "(false)" << endl;
		return false;
	}
	
	if(strcmp(toks[0], eFlag) == 0){	
		cout << "(true)" << endl;
		return true;
	}
	else if(strcmp(toks[0], dFlag) == 0){
		if(S_ISDIR(buf.st_mode)){
			cout << "(true)" << endl;
			return true;
		}
		cout << "(false)" << endl;
		return false;
        }
	else if(strcmp(toks[0], fFlag) == 0){
		if(S_ISREG(buf.st_mode)){
                        cout << "(true)" << endl;
                        return true;
                }
                cout << "(false)" << endl;
                return false;
        }
	return false;
}

void TestClass::display(){
	int i  = 0;
	cout << "TESTCLASS" << endl;
	while(toks[i] != NULL){
		cout << toks[i] << ' ';
		++i;
	}
	cout << endl;
}
