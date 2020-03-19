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
		FILE *left;
		string lt;
		bool inif = false;
		if(l->isAnd() || l->isOr() || l->isSemicolon()){
			inif = true;
			l->run();
			lt = l->GetR()->GetFullTok();
		}
		else{
			left = l->execute();
		}
		
		string right = r->GetFullTok();		

		string r = "r";
		string w = "w";

		const int MAX =  500;

		char buffer[MAX];

		memset(buffer, '\0',  MAX);

	//	FILE* lhs;		
	//	if(!inif){lhs = popen(left, r.c_str());}
	//	else{lhs = popen(lt.c_str(), r.c_str());}

		FILE* rhs = popen(right.c_str(), w.c_str());
		
		if(rhs == nullptr) {pclose(left); pclose(rhs); return false;}	
//		if(lhs == nullptr){pclose(lhs); pclose(rhs); return true;} 
		if(left == nullptr) {pclose(left); pclose(rhs); return true;}		
		
		while(fgets(buffer, MAX, left) != nullptr){
			fputs(buffer, rhs);
		}

		pclose(left);
		pclose(rhs);

		return true;
        }
	else if (l->isCon() && r->isCon()){
		FILE *left;
		FILE* fright;
		string lt;
		string rt;
		bool inif = false;
		if(l->isAnd() || l->isOr() || l->isSemicolon()){
			inif = true;
			l->run();
			lt = l->GetR()->GetFullTok();
		}
		else{
			left = l->execute();
		}
		

		if(r->isAnd() || r->isOr() || r->isSemicolon()){
			inif = true;
			r->run();
			rt = r->GetL()->GetFullTok();
		}
		else{
			fright = r->execute();
		}
	

		string right = r->GetFullTok();		


		string r = "r";
		string w = "w";

		const int MAX =  500;

		char buffer[MAX];

		memset(buffer, '\0',  MAX);

	//	FILE* lhs;		
	//	if(!inif){lhs = popen(left, r.c_str());}
	//	else{lhs = popen(lt.c_str(), r.c_str());}

		FILE* rhs = popen(right.c_str(), w.c_str());
		
		if(rhs == nullptr) {pclose(left); pclose(rhs); return false;}	
//		if(lhs == nullptr){pclose(lhs); pclose(rhs); return true;} 
		if(left == nullptr) {pclose(left); pclose(rhs); return true;}		
		
		while(fgets(buffer, MAX, left) != nullptr){
			fputs(buffer, rhs);
		}

		pclose(left);
		pclose(rhs);

		return true;
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

FILE* Pipe::execute(){
	CMD* l = this->GetL();
	CMD* r = this->GetR();
	
	char *arr = new char[5000];

	memset(arr, '\0', 5000);
	
	if(l->isCon() && !(r->isCon())){
 		FILE *left;
		string lt;
		bool inif = false;
		if(l->isAnd() || l->isOr() || l->isSemicolon()){
			inif = true;
			l->execute();
			lt = l->GetR()->GetFullTok();
		}
		else{
		//	left = l->execute();
		}
		
		string right = r->GetFullTok();		
		string r = "r";
		string w = "w";

		const int MAX =  500;

		char buffer[MAX];

		memset(buffer, '\0',  MAX);

		FILE* lhs;		
	//	if(!inif){lhs = popen(left, r.c_str());}
	//	else{lhs = popen(lt.c_str(), r.c_str());}

		FILE* rhs = popen(right.c_str(), w.c_str());

		if(rhs == nullptr) {pclose(lhs); pclose(rhs); return nullptr;}	
		
		while(fgets(buffer, MAX, lhs) != nullptr){
			fputs(buffer, rhs);
			strcat(arr,  buffer);
		}

		pclose(lhs);
		pclose(rhs);

		return nullptr;
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

		if(rhs == nullptr) {pclose(lhs); pclose(rhs); return nullptr;}	
		
		while(fgets(buffer, MAX, lhs) != nullptr){
			fputs(buffer, rhs);
			strcat(arr, buffer);
		}

		pclose(lhs);
		pclose(rhs);

		return nullptr;
	}

}





/*


	CMD* L = this->GetL();
	CMD* R = this->GetR();

	string lhs = L->GetFullTok();
	string rhs = R->GetFullTok();	

	string fin = lhs + " < " + rhs;

	string r = "r";
	
	const int max = 256;
	
	char BUF[max];

	memset(BUF, '\0', max);
		
	FILE* com = popen(fin.c_str(), r.c_str());

	if(com == nullptr){return nullptr;}		

	return com;*/
