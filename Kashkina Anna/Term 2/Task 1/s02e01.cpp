#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int maxlen = 10000;
char s[maxlen];

int go[2][256];
const int fail = -1, ok = 1;
int state = 0;
int lexemeBeginning = 0;

char nextChar() {
	return s[lexemeBeginning];
}

bool isEnd() {
	return strlen(s) <= lexemeBeginning;
}

bool check() {
	int state = 0;
	char c;
	while (true) {
		switch (state) {
			case 0: 
				if (isEnd()) {state = ok; break;}
				c = nextChar();
				++lexemeBeginning;
			if (c >= '0' && c <= '9') {
				state = 0;
			} else
				state = fail;
			break;
		}
		if (state == ok || state == fail) break;
	}
	return (state == ok);
}

int main() {
	scanf("%s", s);
	cout << (check() ? "Number" : "Not a Number") << endl;
}
