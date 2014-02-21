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

struct stack {
	int num;
	char *a;

	void resize(int n) {
		num = 0;
		a = new char[n];
	}
	void push(char c) {
		a[num] = c;
		num++;
	}
	char pop() {
		num--;
		return a[num];
	}
	bool empty() {
		return num == 0;
	}
};

stack part[2];

void exitf() {
	getchar();
	getchar();
	for (int i = 0; i < 2; i++)
		delete[] part[i].a;
	exit(0);
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	string s;
	int n;
	cout << "Print a string: ";
	cin >> s;
	n = s.size();

	for (int i = 0; i < 2; i++)
		part[i].resize(n / 2);
	
	for (int i = 0; i < 2; i++) {
		for (int j = i * (n / 2); j < (i + 1) * n / 2; j++) {
			part[i].push(s[j]);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			cout << part[i].pop();
		}
	}

	exitf();

	return 0;
}