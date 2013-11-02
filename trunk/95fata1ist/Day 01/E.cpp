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

int count_substr(string s, string s1) {
	int ans = 0;
	for (int i = 0; i < s.size() - s1.size() + 1; i++)
		ans += s.substr(i, s1.size()) == s1;
	return ans;
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	string s, s1;
	cout << "Print S: ";
	cin >> s;
	cout << "Print S1: ";
	cin >> s1;
	
	cout << count_substr(s, s1) << '\n';

	getchar();
	getchar();

	return 0;
}