#include <iostream>
#include <string>

using namespace std;

double** table;

bool sendErrorMessage();

// automata

bool isIdentifier(string  str);
bool isNumber(string str);
bool isReservedWord_While(string str);

// transition table

bool isIdentifier_table(string  str);
bool isNumber_table(string str);
bool isReservedWord_IF_table(string str);


bool isLetter(char c);
bool isDigit(char c);

void createTransitionTable_ID();
void createTransitionTable_NUM();
void createTransitionTable_IF();

int main(int argc, char const *argv[]) {

	char c;
	string str;

	cin >> str;
	// cout << isIdentifier(str) << endl;
	// cout << isNumber(str) << endl;
	// cout << isReservedWord_While(str) << endl;

	createTransitionTable_ID();
	cout << isIdentifier_table(str) << endl;

	createTransitionTable_NUM();
	cout << isNumber_table(str) << endl;

	createTransitionTable_IF();
	cout << isReservedWord_IF_table(str) << endl;
	
	return 0;
}

bool sendErrorMessage() {
	// cout << "Error" << endl;
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

void createTransitionTable_ID() {
	int rows = 3;
	int columns = 3;
	table = new double*[rows];
	for( int i = 0; i < rows; i++ )
		table[i] = new double[columns];

	table[0][0] = 2;
	table[0][1] = 1;
	table[0][2] = 0;
	table[1][0] = 0;
	table[1][1] = 0;
	table[1][2] = 0;
	table[2][0] = 2;
	table[2][1] = 2;
	table[2][2] = 3;

}

void createTransitionTable_NUM() {
	int rows = 3;
	int columns = 3;
	table = new double*[rows];
	for( int i = 0; i < rows; i++ )
		table[i] = new double[columns];

	table[0][0] = 1;
	table[0][1] = 2;
	table[0][2] = 1;
	table[1][0] = 1;
	table[1][1] = 1;
	table[1][2] = 1;
	table[2][0] = 1;
	table[2][1] = 2;
	table[2][2] = 3;
}

void createTransitionTable_IF() {
	int rows = 3;
	int columns = 3;
	table = new double*[rows];
	for( int i = 0; i < rows; i++ )
		table[i] = new double[columns];

	table[0][0] = 2;
	table[0][1] = 1;
	table[0][2] = 1;
	table[1][0] = 1;
	table[1][1] = 1;
	table[1][2] = 1;
	table[2][0] = 1;
	table[2][1] = 2;
	table[2][2] = 3;
}

bool isIdentifier_table(string  str) {
	int state = 0;
	int input;
	int strLen = str.length();
	// 0 letter as input 1 digit as input 2 EOF
	for (int i = 0; i < strLen; ++i) {
		if( isLetter(str[i]) ) {
			input = 0;
		} else if( isDigit(str[i]) ) {
			input = 1;
		} else
			return sendErrorMessage();
		state = table[state][input];
		if(state == 1)
			return sendErrorMessage();
	}
	if( state == 2 )
		return true;
}

bool isNumber_table(string str) {
	int state = 0;
	int input;
	int strLen = str.length();
	// 0 letter as input 1 digit as input 2 EOF
	for (int i = 0; i < strLen; ++i) {
		if( isLetter(str[i]) ) {
			input = 0;
		} else if( isDigit(str[i]) ) {
			input = 1;
		} else
			return sendErrorMessage();
		state = table[state][input];
		if(state == 1)
			return sendErrorMessage();
	}
	if( state == 2 )
		return true;
}

bool isReservedWord_IF_table(string str) {
	int state = 0;
	int input;
	int strLen = str.length();
	// 0 letter as input 1 digit as input 2 EOF
	for (int i = 0; i < strLen; ++i) {
		if( str[i] == 'i' ) {
			input = 0;
		} else if( str[i] == 'f' ) {
			input = 1;
		} else
			return sendErrorMessage();
		state = table[state][input];
		if(state == 1)
			return sendErrorMessage();
	}
	if( state == 2 )
		return true;
}