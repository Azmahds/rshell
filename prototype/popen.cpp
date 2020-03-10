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
	
	string l = "ls";
	string r = "r";
	string w = "w";
	
	char c;

	const int MAX =  100;

	char buffer[MAX];
	char buffer2[MAX];

	memset(buffer, '\0',  MAX);
	memset(buffer2, '\0',  MAX);

	FILE* LHS = popen(l.c_str(), r.c_str());
	

	pclose(LHS);

	int thx = system(l.c_str());

	return 0;
}
