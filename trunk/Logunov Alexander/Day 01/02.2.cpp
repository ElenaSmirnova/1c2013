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
const int MAXDIFF = 1000;

void counting_sort(int *a, int n, int minval, int maxval) {
	int c[MAXDIFF];
	for (int i = 0; i <= maxval - minval; i++)
		c[i] = 0;

	for (int i = 0; i < n; i++)
		c[a[i] - minval]++;

	int num = 0;
	for (int i = 0; i <= maxval - minval; i++)
		for (int j = 0; j < c[i]; j++)
			a[num++] = minval + i;
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
			int minval, maxval, a[MAXN];

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

			minval = maxval = a[0];
			for (int i = 1; i < n; i++) {
				minval = min(minval, a[i]);
				maxval = max(maxval, a[i]);
			}

			counting_sort(a, n, minval, maxval);

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