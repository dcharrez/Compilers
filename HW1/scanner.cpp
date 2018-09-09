#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

#define num_id 1
#define id_id 2
#define asignation 3

void scanner(string fileName);
void show(int id_token);
void proccessLine(string line);

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
	istringstream iss(line);
	vector<string> tokens{istream_iterator<string>{iss},
                      istream_iterator<string>{}};

    for (int i = 0; i < tokens.size(); ++i) {
    	lexicalAnalyzer(tokens[i]);
    }
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