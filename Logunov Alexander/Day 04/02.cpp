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
#include <vector>

using namespace std;

const int BUF = 256;

struct MyString {
	string s;

	MyString() {
		s = "";
	}
	MyString(string _s) {
		s = _s;
	}

	~MyString() {};

	void print() {
		cout << s << '\n';
	}
	void operator=(string a) {
		s = a;
	}
	MyString concat(MyString b) {
		return MyString(s + b.s);
	}
	MyString operator+(MyString b) {
		return MyString(s + b.s);
	}
	bool operator==(MyString b) {
		return s == b.s;
	}
	bool operator<(MyString b) {
		return s < b.s;
	}
	bool operator>(MyString b) {
		return s > b.s;
	}
	void clone(MyString a) {
		s = a.s;
	}
	int length() {
		return s.size();
	}
	MyString substr(int index, int len) {
		return MyString(s.substr(index, len));
	}
	bool empty() {
		return s.size() == 0;
	}
	char* toarray() {
		char *a = new char[s.size()];
		for (int i = 0; i < s.size(); i++)
			a[i] = s[i];
		return a;
	}
};

const long long POW = 257; 
const long long MOD = 1000033;
vector<MyString> hash_table[MOD];
vector<int> times[MOD];

long long count_hash(MyString s) {
	long long ans = 0, p = 1;
	for (int i = 0; i < s.length(); i++) {
		ans = (ans + p * s.s[i]) % MOD;
		p = (p * POW) % MOD;
	}
	return ans;
}

void add(MyString s) {
	int hash_s = count_hash(s);
		
	int idstr;
	for (idstr = 0; idstr < hash_table[hash_s].size() && !(hash_table[hash_s][idstr] == s); idstr++) {}
	if (idstr < hash_table[hash_s].size())
		times[hash_s][idstr]++;
	else {
		hash_table[hash_s].push_back(s);
		times[hash_s].push_back(1);
	}
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	cout << "Print the text string-by-string. Finish writing by '!' symbol.\n";
	string s;
	cin >> s;
	while (s != "!") {
		add(s);
		cin >> s;
	}
	
	double factor = 0;
	for (int i = 0; i < MOD; i++)
		factor += hash_table[i].size();
	factor /= MOD;
	printf("Load factor: %.6lf\n", factor);

	double average = 0;
	int maxlength = -1, maxlengthid = -1, cells = 0;
	for (int i = 0; i < MOD; i++) {
		cells += !hash_table[i].empty();
		average += hash_table[i].size();
		if (maxlength < (int)hash_table[i].size()) {
			maxlength = hash_table[i].size();
			maxlengthid = i;
		}
	}
	average /= cells;

	printf("Average chain length: %.6lf\n", average);

	printf("Maximal chain length: %d\n", maxlength);
	cout << "Words in it:\n";
	for (int i = 0; i < hash_table[maxlengthid].size(); i++)
		cout << hash_table[maxlengthid][i].s << '\n';
	cout << '\n';

	int stringnumber = 0;
	cout << "All strings:\n";
	for (int i = 0; i < MOD; i++) {
		for (int j = 0; j < hash_table[i].size(); j++) {
			stringnumber += times[i][j];
			cout << hash_table[i][j].s;
			printf(": %d times\n", times[i][j]);
		}
	}
	printf("(totally: %d)\n", stringnumber);

	printf("Free cells: %d\n", MOD - cells);

	getchar();
	getchar();

	return 0;
}