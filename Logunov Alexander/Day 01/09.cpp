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

void quicksort(int *a, int l, int r) {
	int val = a[l + rand() % (r - l + 1)], i = l, j = r;

	while (i <= j) {
		while (a[i] < val)
			i++;
		while (a[j] > val)
			j--;

		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	
	if (l < j)
		quicksort(a, l, j);
	if (i < r)
		quicksort(a, i, r);
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	int n;
	cout << "Print number of elements in array: ";
	read_int(n);

	int a[MAXN];
	cout << "Print all elements of array: ";
	for (int i = 0; i < n; i++)
		read_int(a[i]);

	quicksort(a, 0, n - 1);

	cout << "Sorted array: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';

	getchar();
	getchar();

	return 0;
}