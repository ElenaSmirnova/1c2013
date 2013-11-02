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
const int MAXN = 10000;

void print_primes(int n) {
	bool prime[MAXN];

	prime[0] = prime[1] = 0;
	for (int i = 2; i <= n; i++)
		prime[i] = 1;

	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			cout << i << ' ';
			for (int j = i * 2; j <= n; j += i)
				prime[j] = 0;
		}
	}
	cout << '\n';
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	char s[BUF];
	int n;

	cout << "Print maximal prime number: ";
	scanf("%s", s);

	if (sscanf(s, "%d", &n) > 0) {
		print_primes(n);
	}
	else {
		cout << "Illegal format!\n";
	}

	gets(s);
	gets(s);

	return 0;
}