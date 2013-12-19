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

stack open;
string s;

void exitf() {
	getchar();
	getchar();
	delete[] open.a;
	exit(0);
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	int n;
	cout << "Print a string: ";
	cin >> s;
	n = s.size();

	open.num = 0;
	open.a = new char[n];
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			open.push('(');
		} else if (s[i] == ')') {
			if (open.empty()) {
				printf("Fail: Too small balance on %d-th position.", i + 1);
				exitf();
			} else
				open.pop();
		} else {
			printf("Fail: Illegal symbol on %d-th position.", i + 1);
			exitf();
		}
	}
	if (!open.empty()) {
		printf("Fail: Not all brackets were closed.");
	} else {
		printf("Correct sequence!");
	}

	exitf();

	return 0;
}