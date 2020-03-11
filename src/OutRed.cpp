#include "../header/OutRed.h"
#include <stdio.h>

bool OutRed::run() {
	CMD* L = this->GetL();
	CMD* R = this->GetR();

	if(!(L->isCon()) && !(R->isCon())){
		string lhs = L->GetFullTok();
		string hs = R->GetFullTok();	
		string rhs;
		
		string w = "w";
		string r  = "r";
		string a = "a";

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
		char BUF2[max];

		memset(BUF, '\0', max);
		memset(BUF2, '\0', max);		
		


		FILE* com1 = popen(lhs.c_str(), r.c_str());
		FILE* com2;		
		if(rhs.at(0) == '>' && rhs.at(1) == '>'){
			 com2 = fopen(hs.c_str(), a.c_str());
		}
		else{
			 com2 = fopen(hs.c_str(), w.c_str());
		}

         	if(com1 == nullptr || com2 == nullptr){return false;}



		while(fgets(BUF, max, com1) != nullptr){
			fputs(BUF, com2);                				
		}
	


		pclose(com1);
		fclose(com2);

		return true;
	}
}

