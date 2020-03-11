#include "../header/InRed.h"


bool InRed::run() {
	CMD* L = this->GetL();
	CMD* R = this->GetR();

	if(!(L->isCon()) && !(R->isCon())){
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
