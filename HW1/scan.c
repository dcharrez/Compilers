#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM 256
#define AS '='

int scanner();
void show(int  token);
bool isdigit(char c);

File *f;
char lexeme[80];

int main(int argc, char const *argv[])
{
	int token;
	f=stdin;

	if(n==2) {
		f = fopen(argv[1], "rt");
		if(f==NULL)
			f = stdin;
	}
	if(f==stdin)
		printf("Enter text ...... finish with ctrl z \n");

	while(1) {
		token = scanner();
		if(token == EOF)
			break;
		show(token);
	}

	if(f!=stdin)
		fclose(f);

	return 0;
}

int scanner() {
	int c;
	int i;

	do
		c = fgetc(f);
	while( isspace(c) );

	if( c == EOF )
		return EOF;

	if(isdigit(c)) {
		i = 0;
		do {
			lexeme[i++] = c;
			c = fgetc(f);
		} while( isdigit(c) );

		lexeme[i] = 0;
		ungetc(c,f);
		return NUM;
	}

	if((c=='=')) {
		lexeme[0] = c;
		lexeme[1] = 0;
		return AS;
	}
}

void show( int token ) {
	switch(token) {
		case NUM: printf("token = NUM [%s]\n", lexeme ); break;
		case AS: printf("token = AS [%c]\n", token ); break;
	}
}

bool isdigit(char c) {
	if(c>='0' and c<='9')
		return true;
	return false;
}