#pragma comment(linker, "/STACK:67108864")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> 
#include <sstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

const int BUF = 256;
const int MAXN = 1000;

int check(char *s) {
	int n = strlen(s), balance = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			balance++;
		else if (s[i] == ')')
			balance--;
		else
			return -1;
		if (balance < 0)
			return 0;
	}
	return balance == 0;
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	char s[BUF];
	int n;

	cout << "Print a brackets sequence: ";
	scanf("%s", s);
	switch (check(s)) {
		case -1: {
			cout << "Bad symbol somewhere!\n";
			break;
		}
		case 0: {
			cout << "Bad sequence!\n";
			break;
		}
		case 1: {
			cout << "Good sequence!\n";
			break;
		}
	}

	gets(s);
	gets(s);

	return 0;
}