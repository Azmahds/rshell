#include "../header/OutRed.h"


bool OutRed::run() {
	CMD* L = this->GetL();
	CMD* R = this->GetR();

	if(!(L->isCon()) && !(R->isCon())){
		string lhs = L->GetFullTok();
		string hs = R->GetFullTok();	
		string rhs;
		
		string w = "w";
		string r  = "r";

		char* rArr = (char*)  ">";
                char* drArr = (char*) ">>";
                char* temp = cons[0];
	
		if(strcmp(rArr, temp) == 0){
            		rhs =   "> " + hs;	
                }

                else if(strcmp(drArr, temp) == 0){
			rhs =  ">> " + hs;
	        }	

		const int max = 256;
	
		char BUF[max];

		memset(BUF, '\0', max);
		
		FILE* com1 = popen(lhs.c_str(), r.c_str());
		FILE* com2 = popen(rhs.c_str(), w.c_str());

		if(com1 == nullptr || com2 == nullptr){return false;}

		while(fgets(BUF, max, com) != nullptr){
			fputs(BUF, com2);                				
		}
	
		pclose(com1);
		pclose(com2);
		
		return true;
	}
}

