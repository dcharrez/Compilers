#include <iostream>
#include <string>

using namespace std;

bool sendErrorMessage();
bool isIdentifier(string  str);
bool isNumber(string str);
bool isReservedWord_While(string str);

bool isLetter(char c);
bool isDigit(char c);

int main(int argc, char const *argv[]) {

	char c;
	string str;

	cin >> str;
	cout << isIdentifier(str) << endl;
	cout << isNumber(str) << endl;
	cout << isReservedWord_While(str) << endl;
	// cout << str.length() << endl;
	// cout << str[3] << endl;


	// cin >> c;
	// cout << isLetter(c) << endl;
	// cout << isDigit(c) << endl;
	
	return 0;
}

bool sendErrorMessage() {
	cout << "Error" << endl;
	return false;
}

bool isIdentifier(string  str) {
	int state = 1;
	int strLen = str.length();
	int currentIndex = 0;
	while(currentIndex < strLen) {
		switch(state) {
			case 1:
				if( isLetter(str[currentIndex]) )
					state = 3;
				else  if( isDigit(str[currentIndex]) )
					state = 2;
				else
					return sendErrorMessage();	
				currentIndex++; break;
			case 2:
				return sendErrorMessage();	
			case 3:
				if( isLetter(str[currentIndex]) )
					state = 3;
				else if( isDigit(str[currentIndex]) )
					state = 3;
				else
					return sendErrorMessage();	
				currentIndex++; break;
		}
	}
	if(state != 3 ) {
		return sendErrorMessage();	
	}
	else
		return true;
}

bool isNumber(string str) {
	int state = 1;
	int strLen = str.length();
	int currentIndex = 0;
	while(currentIndex < strLen) {
		switch(state) {
			case 1:
				if( isLetter(str[currentIndex]) )
					state = 2;
				else  if( isDigit(str[currentIndex]) )
					state = 3;
				else
					return sendErrorMessage();	
				currentIndex++; break;
			case 2:
				return sendErrorMessage();
			case 3:
				if( isLetter(str[currentIndex]) )
					state = 2;
				else if( isDigit(str[currentIndex]) )
					state = 3;
				else
					return sendErrorMessage();	
				currentIndex++; break;
		}
	}
	if(state != 3 ) {
		return sendErrorMessage();	
	}
	else
		return true;
}

bool isReservedWord_While(string str) {
	int state = 1;
	string reservedWord = "while";
	int strLen = str.length();
	int currentIndex = 0;
	while(currentIndex < strLen) {
		switch(state) {
			case 1:
				if( reservedWord[currentIndex] == str[currentIndex])
					state = 3;
				else
					state = 2;
				currentIndex++; break;
			case 2:
				return sendErrorMessage(); break;
			case 3:
				if( reservedWord[currentIndex] == str[currentIndex])
					state = 3;
				else
					state = 2;
				currentIndex++; break;
		}
	}
	if(state != 3 or currentIndex+1 != reservedWord.length()) {
		return sendErrorMessage();	
	}
	else
		return true;
}

bool isLetter(char c) {
	if( (c>='a' and c<='z') or (c<='A' and c>='Z') )
		return true;
	return false;
}
bool isDigit(char c) {
	if( c>='0' and c<='9')
		return true;
	return false;
}
