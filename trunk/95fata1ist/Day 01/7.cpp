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

int read_int(int &x) {
	char s[BUF];
	scanf("%s", s);
	if (sscanf(s, "%d", &x) <= 0) {
		cout << "Illegal format!\n";
		gets(s);
		gets(s);
		exit(0);
	}		
}

const int MAXN = 10000;

long double pow(int a, int n) {
	long double answer = 1;
	if (n >= 0) {
		for (int i = 0; i < n; i++)
			answer *= a;		
	}
	else {
		for (int i = 0; i < -n; i++)
			answer /= a;
	}
	return answer;
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	int a, n;
	cout << "Print base: ";
	read_int(a);
	cout << "Print power: ";
	read_int(n);
	cout.precision(10);
	cout << pow(a, n) << '\n';

	getchar();
	getchar();

	return 0;
}