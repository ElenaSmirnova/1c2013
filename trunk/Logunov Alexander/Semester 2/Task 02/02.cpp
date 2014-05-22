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

enum {init, slash, comment, star};

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cout << "Write some code on C++.\n";
	cout << "Finish the process by \"END\" without quotes.\n";

	string s, code = "";
	int state = init;

	while (true) {
		getline(cin, s);
		if (s == "END")
			break;

		s += '\n';

		for (int i = 0; i < (int)s.size(); i++) {
			char c = s[i];
			switch(state) {
				case init: {
					switch(c) {
						case '/': state = slash; break;
						default: state = init;
					}
					break;
				}
				case slash: {
					switch(c) {
						case '*': {
							state = comment;
							code += "/*";
							break;
						}
						default: state = init;
					}
					break;
				}
				case comment: {
					switch(c) {
						case '*': {
							state = star;
							code += c;
							break;
						}
						default: code += c;
					}
					break;
				}
				case star: {
					switch(c) {
						case '/': {
							state = init;
							code += c;
							code += '\n';
							break;
						}
						default: {
							state = comment;
							code += c;
						}
					}
					break;
				}
			}
		}
	}

	cout << code;

	getchar();

	return 0;
}