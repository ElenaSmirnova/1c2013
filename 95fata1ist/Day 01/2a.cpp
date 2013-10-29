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

void bubble_sort(int *a, int n) {
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
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

			cout << "Print all elements of array: ";
			for (int i = 0; i < n; i++) {
				scanf("%s", s);
				if (sscanf(s, "%d", &a[i]) <= 0) {
					cout << "Illegal format!\n";
					gets(s);
					gets(s);
					return 0;
				}
			}

			bubble_sort(a, n);

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

	getchar();

	return 0;
}