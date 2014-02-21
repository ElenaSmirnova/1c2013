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

int fib(int n) {
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	char s[BUF];
	int n;

	cout << "Print a number: ";
	scanf("%s", s);

	if (sscanf(s, "%d", &n) > 0) {
		if (n >= 0) {
			cout << fib(n) << '\n';
		}
		else {
			cout << "Wrong number!\n";
		}
	}
	else {
		cout << "Illegal format!\n";
	}

	gets(s);
	gets(s);

	return 0;
}