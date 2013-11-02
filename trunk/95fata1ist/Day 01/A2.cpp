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

typedef long long ll;

const int BUF = 256;
const int MAXN = 100;

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	char s[BUF];
	int n;

	cout << "Print a number: ";
	scanf("%s", s);

	if (sscanf(s, "%d", &n) > 0) {
		if (n >= 0) {
			ll fib[MAXN];

			fib[0] = 0;
			fib[1] = 1;
			for (int i = 2; i <= n; i++)
				fib[i] = fib[i - 1] + fib[i - 2];

			cout << fib[n] << '\n';
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