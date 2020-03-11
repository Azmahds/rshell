#include <iostream>
#include <vector>
#include  <string>
#include  <cstring>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <unistd.h>
#include  <cassert>
#include <fcntl.h>
#include <stdio.h>

using namespace std;

int main(){
	
	string l = "ex.txt";
	string r = "r";
	string w = "w";
	
	char c;

	const int MAX =  100;

	char buffer[MAX];
	char buffer2[MAX];

	memset(buffer, '\0',  MAX);
	memset(buffer2, '\0',  MAX);

	FILE* LHS = popen(l.c_str(), w.c_str());
	
	if(LHS == nullptr){
		cout << "DID NOT WORK" << endl;
	}
	
	pclose(LHS);

//	int thx = system(l.c_str());

	return 0;
}
