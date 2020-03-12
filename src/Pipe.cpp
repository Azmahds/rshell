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

#include "../header/Pipe.h"

using namespace std;

bool Pipe::run() {
	CMD* l = this->GetL();
	CMD* r = this->GetR();

	if(l->isCon() && !(r->isCon())){
 		
        }	
	else{
		string left = l->GetFullTok();
		string right = r->GetFullTok();
		
		string r = "r";
		string w = "w";

		const int MAX =  500;

		char buffer[MAX];

		memset(buffer, '\0',  MAX);

		FILE* lhs = popen(left.c_str(), r.c_str());
		FILE* rhs = popen(right.c_str(), w.c_str());

		if(rhs == nullptr) {pclose(lhs); pclose(rhs); return false;}	
		
		while(fgets(buffer, MAX, lhs) != nullptr){
			fputs(buffer, rhs);
		}

		pclose(lhs);
		pclose(rhs);

		return true;
	}
}

char* Pipe::execute(){
	return NULL;
}
