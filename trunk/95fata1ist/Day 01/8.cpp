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

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	string s1, s2;
	cout << "Print a string: ";
	cin >> s1;
	s2 = s1;
	reverse(s2.begin(), s2.end());
	cout << (s1 == s2 ? "Yes\n" : "No\n");

	getchar();
	getchar();

	return 0;
}