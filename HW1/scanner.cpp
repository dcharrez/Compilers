#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

enum operators { less, lessEqual, greater, greaterEqual,
				 different, assign, equal };

enum reserverdWords { r_while, r_for, r_if, r_else };

enum others { op_parentheses, cl_parentheses, op_brackets, cl_brackets,
			  period, comma, op_quotation, cl_quotation, colon, semicolon };


void scanner(string fileName);
void show(int id_token);
void proccessLine(string line);

bool isLess(string token);
bool isLessEquall(string token);
bool isGreater(string token);
bool isGreatherEqual(string token);
bool isDifferent(string token);
bool isEqual(string token);
bool isAssign(string token);

bool isWhile(string token);
bool isFor(string token);
bool isIf(string token);
bool isElse(string token);

bool isOpParentheses(string token);
bool isClParentheses(string token);
bool isOpBrackets(string token);
bool isClBrackets(string token);
bool isOpQuotation(string token);
bool isClQuotation(string token);
bool isColon(string token);
bool isSemicolon(string token);
bool isComma(string token);
bool isPeriod(string token);

bool isLetter(char c);
bool isDigit(char c);

int main () {

  scanner("program.txt");

  return 0;
}

void scanner(string fileName) {
	string line;
  ifstream myfile (fileName);
  if (myfile.is_open()) {
    while ( getline (myfile,line) ) {
    	proccessLine(line);
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

}

void proccessLine(string line) {
	for (int i = 0; i < line.size(); ++i) {
		
	}


	// istringstream iss(line);
	// vector<string> tokens{istream_iterator<string>{iss},
 //                      istream_iterator<string>{}};

 //    for (int i = 0; i < tokens.size(); ++i) {
 //    	lexicalAnalyzer(tokens[i]);
 //    }
}

void show(int id_token, string lexeme) {
	switch(id_token) {
		case num_id:
			cout << "Token = NUM " << lexeme << endl;  
	}
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


bool isLess(string token) {
	if( token == "<" )
		return true;
	return false;
}

bool isLessEquall(string token) {
	if( token == "<=" )
		return true;
	return false;
}

bool isGreater(string token) {
	if( token == ">" )
		return true;
	return false;
}

bool isGreatherEqual(string token) {
	if( token == ">=" )
		return true;
	return false;
}

bool isDifferent(string token) {
	if( token == "!=" )
		return true;
	return false;
}

bool isEqual(string token) {
	if( token == "==" )
		return true;
	return false;
}

bool isAssign(string token) {
	if( token == "=" )
		return true;
	return false;
}


bool isWhile(string token) {
	if( token == "while" )
		return true;
	return false;
}

bool isFor(string token) {
	if( token == "for" )
		return true;
	return false;
}

bool isIf(string token) {
	if( token == "if" )
		return true;
	return false;
}

bool isElse(string token) {
	if( token == "else" )
		return true;
	return false;
}


bool isOpParentheses(string token) {
	if( token == "(" )
		return true;
	return false;
}

bool isClParentheses(string token) {
	if( token == ")" )
		return true;
	return false;
}

bool isOpBrackets(string token) {
	if( token == "[" )
		return true;
	return false;
}

bool isClBrackets(string token) {
	if( token == "]" )
		return true;
	return false;
}

bool isOpQuotation(string token) {
	if( token == "\"" )
		return true;
	return false;
}

bool isClQuotation(string token) {
	if( token == "\"" )
		return true;
	return false;
}

bool isColon(string token) {
	if( token == ":" )
		return true;
	return false;
}

bool isSemicolon(string token) {
	if( token == ";" )
		return true;
	return false;
}

bool isComma(string token) {
	if( token == "," )
		return true;
	return false;
}

bool isPeriod(string token) {
	if( token == "." )
		return true;
	return false;
}
