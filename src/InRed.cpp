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

	if(com == nullptr){return false;}
		
	while(fgets(BUF, max, com) != nullptr){
		cout << BUF;
	}
		
	pclose(com);

	return true;
	}
}



char* InRed::execute(){
	CMD* L = this->GetL();
	CMD* R = this->GetR();

	const int size = 5000;
	char* arr = new char[size];
	strcpy(arr, "");

	if(!(L->isCon()) && !(R->isCon())){
		string lhs = L->GetFullTok();
		string rhs = R->GetFullTok();	

		string fin = lhs + " < " + rhs;

		string r = "r";
	
		const int max = 256;
	
		char BUF[max];

		memset(BUF, '\0', max);
		
		FILE* com = popen(fin.c_str(), r.c_str());

		if(com == nullptr){return NULL;}
		
		while(fgets(BUF, max, com) != nullptr){
			strcat(arr, BUF);
		}
		
		pclose(com);

		return arr;
	}


}
