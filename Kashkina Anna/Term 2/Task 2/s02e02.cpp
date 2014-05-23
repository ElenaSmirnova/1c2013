#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int maxlen = 10000;
char s[maxlen];

int table[6][256];
const int end = 1, ok = 0;
int state = 0;

char nextChar() {
	return getchar();
}


void run() {
	int state = ok;
	char c;
	table[ok]['/'] = 2;
	table[2]['*'] = 3;
	for (int i = 0; i < 256; ++i) {
		table[3][i] = 3;
		table[4][i] = 3;
	}
	table[3]['*'] = 4;
	table[4]['*'] = 4;
	table[4]['/'] = 5;

	string mem = "";
	while (true) {
		switch (state) {
			case 5:
				cout << mem << "\n";
				mem = "";
				state = ok;
				break;
			default: 
				c = nextChar();
				if (c == EOF) {state = end; break;}
				state = table[state][c];
				if (state == 2) mem = "";
				if (state >= 2) mem.push_back(c);
				//if (state != ok) cout << state << "!";
				break;
		}
		if (state == end) break;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	run();
}
