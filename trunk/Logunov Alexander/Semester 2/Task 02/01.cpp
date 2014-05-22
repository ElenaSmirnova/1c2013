#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> 
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;

enum {init, before_dot, dot, after_dot, exponent, sign, after_exp, fail, final};

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cout << "Print a number:\n";

	string s;
	getline(cin, s);

	for (int i = 0; i < (int)s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9')
			s[i] = '0';
		if (s[i] == '-')
			s[i] = '+';
	}
	s += '\n';

	int state = init;
	for (int i = 0; i < (int)s.size(); i++) {
		char c = s[i];
		switch(state) {
			case init: {
				switch(c) {
					case '0': state = before_dot; break;
					case ' ': break;
					default: state = fail;
				}
				break;
			}
			case before_dot: {
				switch(c) {
					case '0': break;
					case '.': state = dot; break;
					case 'E': state = exponent; break;
					case '\n': state = final; break;
					case ' ': break;
					default: state = fail;
				}
				break;
			}
			case dot: {
				switch(c) {
					case '0': state = after_dot; break;
					case ' ': break;
					default: state = fail;
				}
				break;
			}
			case after_dot: {
				switch(c) {
					case '0': break;
					case 'E': state = exponent; break;
					case '\n': state = final; break;
					case ' ': break;
					default: state = fail;
				}
				break;
			}
			case exponent: {
				switch(c) {
					case '0': state = after_exp; break;
					case '+': state = sign; break;
					case ' ': break;
					default: state = fail;
				}
				break;
			}
			case sign: {
				switch(c) {
					case '0': state = after_exp; break;
					case ' ': break;
					default: state = fail;
				}
				break;
			}
			case after_exp: {
				switch(c) {
					case '0': break;
					case '\n': state = final; break;
					case ' ': break;
					default: state = fail;
				}
				break;
			}
			case fail: break;
			case final: break;
		}

		cout << state << '\n';
	}

	if (state == final) {
		cout << "It's a number!\n";
	} else {
		cout << "It's not a number.\n";
	}
	getchar();

	return 0;
}