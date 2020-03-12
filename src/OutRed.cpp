#include "../header/OutRed.h"
#include <stdio.h>

bool OutRed::run() {
	CMD* L = this->GetL();
	CMD* R = this->GetR();
	
	if(L ==  NULL){
		string hs = R->GetFullTok();
                string rhs;
                string w = "w", a = "a";

                char* rArr = (char*)  ">";
                char* drArr = (char*) ">>";
                char* temp = cons[0];

                if(strcmp(rArr, temp) == 0){rhs =   "> " + hs;}
                else if(strcmp(drArr, temp) == 0){rhs =  ">> " + hs;}

                FILE* com2;

                if(rhs.at(0) == '>' && rhs.at(1) == '>'){com2 = fopen(hs.c_str(), a.c_str());}
                else{com2 = fopen(hs.c_str(), w.c_str());}
                
		if(com2 == nullptr){return false;}
		
                fclose(com2);

                return true;	
	}

	else if(!(L->isCon()) && !(R->isCon())){
		string lhs = L->GetFullTok();
		string hs = R->GetFullTok();	
		string rhs;		
		string w = "w";
		string r  = "r";
		string a = "a";

		char* rArr = (char*)  ">";
                char* drArr = (char*) ">>";
                char* temp = cons[0];

		if(strcmp(rArr, temp) == 0){rhs =   "> " + hs;}
                else if(strcmp(drArr, temp) == 0){rhs =  ">> " + hs;}	

		const int max = 256;
	
		char BUF[max];

		memset(BUF, '\0', max);	

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
	
	else if((L->isCon()) &&  !(R->isCon())){
		string hs = R->GetFullTok();
                string rhs;
                string w = "w";
                string r  = "r";
                string a = "a";
	
		char *lhs = L->execute();

                char* rArr = (char*)  ">";
                char* drArr = (char*) ">>";
                char* temp = cons[0];

                if(strcmp(rArr, temp) == 0){rhs =   "> " + hs;}
                else if(strcmp(drArr, temp) == 0){rhs =  ">> " + hs;}

                FILE* com2;

                if(rhs.at(0) == '>' && rhs.at(1) == '>'){
                         com2 = fopen(hs.c_str(), a.c_str());
                }
                else{
                         com2 = fopen(hs.c_str(), w.c_str());
                }

                if(com2 == nullptr){ delete [] lhs; return false;}
                
                fputs(lhs, com2);

                fclose(com2);

		delete [] lhs;
                return true;
	}
}


FILE* OutRed::execute(){
        this->run();
	CMD* L = this->GetL();
        CMD* R = this->GetR();

 	FILE* ans = nullptr;
 
        const int max = 256;
        char BUF[max];
        memset(BUF, '\0', max);

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

		if(strcmp(rArr, temp) == 0){rhs =   "> " + hs;}
                else if(strcmp(drArr, temp) == 0){rhs =  ">> " + hs;}	

		memset(BUF, '\0', max);	

		FILE* com1 = popen(lhs.c_str(), r.c_str());
		FILE* com2;		
		
		if(rhs.at(0) == '>' && rhs.at(1) == '>'){
			 com2 = fopen(hs.c_str(), a.c_str());
		}
		else{
			 com2 = fopen(hs.c_str(), w.c_str());
		}

         	if(com1 == nullptr){return nullptr;}

		while(fgets(BUF, max, com1) != nullptr){
			fputs(BUF, com2);
		}

		pclose(com1);
		fclose(com2);
		
		ans = fopen(hs.c_str(), r.c_str());

		return ans;
	}
	
	else if((L->isCon()) &&  !(R->isCon())){
		string hs = R->GetFullTok();
                string rhs;
                string w = "w";
                string r  = "r";
                string a = "a";
	
		FILE *lhs = L->execute();

                char* rArr = (char*)  ">";
                char* drArr = (char*) ">>";
                char* temp = cons[0];

                if(strcmp(rArr, temp) == 0){rhs =   "> " + hs;}
                else if(strcmp(drArr, temp) == 0){rhs =  ">> " + hs;}

                FILE* com2;

                if(rhs.at(0) == '>' && rhs.at(1) == '>'){
                         com2 = fopen(hs.c_str(), a.c_str());
                }
                else{
                         com2 = fopen(hs.c_str(), w.c_str());
                }

                if(com2 == nullptr){fclose(lhs); fclose(com2); return nullptr;}
                if(lhs == nullptr){fclose(lhs); fclose(com2); return nullptr;}
		
		while(fgets(BUF, max, lhs) != nullptr){
	                fputs(BUF, com2);
		}
	
                fclose(com2);
		fclose(lhs);
		
		ans = fopen(hs.c_str(), r.c_str());
 
                return ans;
	}

}
