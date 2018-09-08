#include <iostream>
#include <string>

using namespace std;

bool isIdentifier(string  str);
bool isNumber(string str);
bool isReservedWord(string str);

bool isLetter(char c);
bool isDigit(char c);

int main(int argc, char const *argv[]) {

	char c;

	cin >> c;
	cout << isLetter(c) << endl;
	cout << isDigit(c) << endl;
	
	return 0;
}

bool isIdentifier(string  str) {
	// int state = 1;
	// while(true) {
	// 	switch(state):
	// 	case 1:

	// }
}
bool isNumber(string str);
bool isReservedWord(string str);

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
