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

enum {init, befd, dot, aftd, exponent, sign, aftexp, fail, final};

int main() {

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	//cout << "Print a number:\n";

	string s;
	cin >> s;

	for (int i = 0; i < (int)s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9')
			s[i] = '7';
		if (s[i] == '-')
			s[i] = '+';
	}
	s += '\n';

	int state = init;
	for (int i = 0; i < (int)s.size(); i++) {
		char c = s[i];
		switch(state) {
			case init: 
			{
				switch(c) 
				{
					case '7': state = befd; break;
					case ' ': break;
					default: state = fail;
				}
				break;
			}
			case befd: 
			{
				switch(c) 
				{
					case '7': break;
					case '.': state = dot; break;
					case 'E': state = exponent; break;
					case '\n': state = final; break;
					case ' ': break;
					default: state = fail;
				}
				break;
			}
			case dot: 
			{
				switch(c) 
				{
					case '7': state = aftd; break;
					case ' ': break;
					default: state = fail;
				}
				break;
			}
			case aftd: 
			{
				switch(c) 
				{
					case '7': break;
					case 'E': state = exponent; break;
					case '\n': state = final; break;
					case ' ': break;
					default: state = fail;
				}
				break;
			}
			case exponent: 
				{
				switch(c) 
				{
					case '7': state = aftexp; break;
					case '+': state = sign; break;
					case ' ': break;
					default: state = fail;
				}
				break;
			}
			case sign: 
			{
				switch(c) 
				{
					case '0': state = aftexp; break;
					case ' ': break;
					default: state = fail;
				}
				break;
			}
			case aftexp: 
			{
				switch(c) 
				{
					case '7': break;
					case '\n': state = final; break;
					case ' ': break;
					default: state = fail;
				}
				break;
			}
			case fail: break;
			case final: break;
		}

		//cout << state << '\n';
	}

	if (state == final) {
		cout << "Yes!\n";
	} else {
		cout << "No\n";
	}
	getchar();

	return 0;
}