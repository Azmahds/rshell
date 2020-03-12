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


char* OutRed::execute(){
        CMD* L = this->GetL();
        CMD* R = this->GetR();

        const int size = 5000;
        char* arr = new char[size];
        strcpy(arr, "");
        
        const int max = 256;
        char BUF[max];
        memset(BUF, '\0', max);

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
                
		if(com2 == nullptr){return NULL;}
		
                fclose(com2);

                return arr;	
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

		memset(BUF, '\0', max);	

		FILE* com1 = popen(lhs.c_str(), r.c_str());
		FILE* com2;		
		
		if(rhs.at(0) == '>' && rhs.at(1) == '>'){
			 com2 = fopen(hs.c_str(), a.c_str());
		}
		else{
			 com2 = fopen(hs.c_str(), w.c_str());
		}

         	if(com1 == nullptr || com2 == nullptr){return NULL;}

		while(fgets(BUF, max, com1) != nullptr){
			strcat(arr, BUF);
			fputs(BUF, com2);                				
		}

		pclose(com1);
		fclose(com2);

		return arr;
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

                if(com2 == nullptr){ delete [] lhs; fclose(com2); return NULL;}
                
		arr = lhs;

                fputs(lhs, com2);
		
                fclose(com2);

		delete [] lhs;
                return arr;
	}

}
