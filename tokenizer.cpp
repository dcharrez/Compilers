#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <functional>
#include <map>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

map <string, int> classes = {{"keyword",0},{"operator_",0},{"number",0},
				{"integer",0},{"real",0},{"identifier",0},{"alpha",0}};
vector<string> ints={"0","1","2","3","4","5","6","7","8","9"}; 
vector<string> keywords={"if","else","then","begin","end"}; 
vector<string> operator_={"(",")","[","]","+","=",",","-",";"}; 
vector<string> alpha={"a","b","c","d","e","f","g","h","i","j","k","l",
				"m","n","o","p","q","r","s","t","u","v","w","x","y","z"}; 
vector<std::string>::iterator iter;

bool isKeyword(string ch);
bool isoperator_(char ch);
bool isInteger(char ch);
bool isnumber(string ch);
bool isReal(string ch);
bool isChar(string ch);
bool isAlpha(char ch);
int cnt_keyword=0;
int cnt_operator_=0;
int cnt_number=0;
int cnt_integer=0;
int cnt_alpha=0;
int cnt_char=0;
int cnt_real=0;

bool isKeyword(string ch);
bool isoperator_(string ch);
bool isnumber(string ch);
bool isInteger(string ch);
bool isReal(string ch);
bool isAlpha(string ch);
bool isChar(string ch);

int main(int argc, char *argv[])  {
	int tokenCount = 0;
	ifstream inFile( argv[1], ios::in);
	char line[80];
	char  *pch;
  
	while (inFile.getline(line, 80)) { 
		pch = strtok(line, " 	~`!@#$^&*_{}:<>|?");
		while (pch != NULL) {
			if (isKeyword(pch))
				cnt_keyword++;
			else if (isoperator_(pch))
				cnt_operator_++;
			else if (isChar(pch))
				cnt_char++;
			else if (isnumber(pch))
				cnt_number++;
			else if (isInteger(pch))
				cnt_integer++;
			else if (isReal(pch))
				cnt_real++;
			else if (isAlpha(pch))
				cnt_alpha++;
			pch = strtok (NULL, "    ~`!@#$^&*_{}:<>|?");
		}
	}
	inFile.close();
	return 0;
}

bool isKeyword(string ch) {
	iter=find(keywords.begin(),keywords.end(),ch);
	if(iter != keywords.end()) {
		classes["keyword"]++;
		cout << ch << " ---- is a keyword"<<endl;
		return true;
	}
	else
		return false;
}

bool isoperator_(string ch) {
	iter=find(operator_.begin(),operator_.end(),ch);
	if(iter != operator_.end()) {
		classes["operator_"]++;
		cout << ch << " ---- is a operator_"<<endl;
		return true;
	}
	else
		return false;
}

bool isnumber(string ch) {
	iter=find(ints.begin(),ints.end(),ch);
	if(iter != ints.end()) {
		classes["number"]++;
		classes["integer"]++;
		cout << ch << " ---- is an integer"<<endl;
		return true;
	}
	else
		return false;
}

bool isInteger(string ch) {
	char * p ;
	strtol(ch.c_str(), &p, 10) ;

	if (*p == 0) {
		classes["number"]++;
		cout << ch << " ---- is a number"<<endl;
		return true;
	} 
	else 
		return false;
}

bool isReal(string ch) {
	bool isreal=false;
	if (ch.find(".") != std::string::npos) {
		for (int j=0; j < ch.length(); j++)
		{ 
			if (ch[j]  != '.') {  
				string search ;
				search = ch[j];
				iter=find(ints.begin(),ints.end(),search);
				if(iter != ints.end())
			     	isreal = true;
				else
					isreal=false;
			}
		}
	}  

	if (isreal == true) {
		classes["real"]++;
		cout << ch << " ---- is a real number." << endl;
		return true;
	}
	else 
		return false;
}

bool isAlpha(string ch) {
	iter=find(alpha.begin(),alpha.end(),ch);
	if(iter != alpha.end() ) {
		classes["alphabet"]++;
		classes["identifier"]++;
		cout << ch << " ---- is a identifier" << endl;
		return true;
	}
	else
		return false;
}

bool isInteger(char c) {
	if( c>='0' and c<='9' )
		return true;
	return false;
}

bool isChar(string ch) {
	bool ischar=false;


	if(  !(ch[0]>='a' and ch[0]<='z') ) {
		return false;
	}
	for(int i=0;  i< ch.length(); i++ ) {
		if( isalpha(ch[i]) or isInteger(ch[i]) )
			ischar = true;
		else
			ischar = false;
	}

	if(ch.length() > 1 && ischar == true ) {
		classes["identifier"]++;
		cout << ch << " ---- is a identifier_"<<endl;
		return true;
	}
	else
		return false;
}
