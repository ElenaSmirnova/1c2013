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

void partition(int *a, int n) {
	int val = a[0], i = 0, j = n - 1;

	while (i < j) {
		while (a[i] < val)
			i++;
		while (a[j] > val)
			j--;

		if (i <= j) {
			swap(a[i], a[j]);
			if (a[i] != val)
				i++;
			if (a[j] != val)
				j--;
		}
	}
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	char s[BUF];
	int n;

	cout << "Print number of elements in array: ";
	scanf("%s", s);

	if (sscanf(s, "%d", &n) > 0) {
		if (n >= 0) {
			int a[MAXN];
			srand(n * n + 49);
			for (int i = 0; i < n; i++)
				a[i] = rand();
	
			cout << "Current array:\n";
			for (int i = 0; i < n; i++)
				cout << a[i] << ' ';
			cout << '\n';

			partition(a, n);

			cout << "Result:\n";
			for (int i = 0; i < n; i++)
				cout << a[i] << ' ';
			cout << '\n';
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