#include "string.h"
#include <iostream>


int main(){

	char const * ch1 = "Test du =(char*)";
	string S = ch1;
	std::cout<<S.c_str()<<std::endl;

	char const * ch2 = "test du +";
	string S1 = string(ch2);
	char c='c';
	string S2 = S1 + c;
	std::cout<<S2.c_str()<<std::endl;

	char const * s1 = "Carabistouille et";
	char const * s2 = " Ratatouille (test du +(str))";
	string s = string(s1);
	std::cout << s.c_str() << std::endl;

	string f = string(s2);
	string sf = s + f;
	std::cout << sf.c_str() << std::endl;
		
  return 0;  
}
