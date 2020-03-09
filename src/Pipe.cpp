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
	
	bool lCon = false;
	bool rCon =  false;
	
	bool fin = false;

	if(l->isCon() && r->isCon()){
		lCon = l->run();
		return r->run();
	}
	
	else if(l->isCon() && !(r->isCon())){
                lCon = l->run();
		
		
        }
	
	else if(!(l->isCon()) && r->isCon()){
                lCon = l->run();
        }		
	
	else{

		Token* lT = l;
		Token* rT = r;
 
		string left = lT->GetFullTok();
		string right = rT->GetFullTok();

		string r = "r";
		string w = "w";

		const int MAX =  256;

		char buffer[MAX];
		char buffer2[MAX];

		memset(buffer, '\0',  MAX);
		memset(buffer2, '\0',  MAX);

		FILE* lhs = popen(left.c_str(), r.c_str());
		FILE* rhs = popen(right.c_str(), r.c_str());

		if(fgets(buffer, MAX, lhs)  == nullptr){
			if(fgets(buffer, MAX, rhs) != nullptr) {pclose(lhs); pclose(rhs); return true;}
		}
		
		if(fgets(buffer, MAX, rhs) != nullptr) {fin = true;}
		

		pclose(lhs);
		pclose(rhs);

		return fin;
	}

}
