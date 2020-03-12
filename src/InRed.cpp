#include "../header/InRed.h"


bool InRed::run() {
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

	if(com == nullptr){cout << "ERROR" << endl; return false;}
		
	while(fgets(BUF, max, com) != nullptr){
		cout << BUF;
	}
		
	pclose(com);

	return true;
	
}



FILE* InRed::execute(){

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

	return com;
}
