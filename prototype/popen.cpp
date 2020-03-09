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
	
	string l = "ec";
	string r = "r";
	string w = "w";

	const int MAX =  100;

	char buffer[MAX];
	char buffer2[MAX];

	memset(buffer, '\0',  MAX);
	memset(buffer2, '\0',  MAX);

	FILE* LHS = popen(l.c_str(), r.c_str());

	if(fgets(buffer, MAX, LHS)  == nullptr){
		cout <<  "WAS NULL";
	}

	pclose(LHS);

	return 0;
}
