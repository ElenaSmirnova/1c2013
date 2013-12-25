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

//bicycle-type realization of list
MyString list[MOD];
int nxt[MOD], last[MOD], inlist[MOD], lastfree;
int hash_table_sz[MOD], times[MOD];

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
	for (idstr = last[hash_s]; idstr != -1 && !(list[idstr] == s); idstr = nxt[idstr]) {}
	if (idstr != -1)
		times[idstr]++;
	else {
		hash_table_sz[hash_s]++;
		nxt[lastfree] = last[hash_s];
		last[hash_s] = lastfree;
		list[lastfree] = s;
		times[lastfree] = 1;
		lastfree++;
	}
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	cout << "Print the text string-by-string. Finish writing by '!' symbol.\n";
	
	memset(last, -1, sizeof(last));
	memset(nxt, -1, sizeof(nxt));
	lastfree = 0;

	string s;
	cin >> s;
	while (s != "!") {
		add(s);
		cin >> s;
	}
	
	double factor = 0;
	for (int i = 0; i < MOD; i++)
		factor += hash_table_sz[i];
	factor /= MOD;
	printf("Load factor: %.6lf\n", factor);

	double average = 0;
	int maxlength = -1, maxlengthid = -1, cells = 0;
	for (int i = 0; i < MOD; i++) {
		cells += hash_table_sz[i] != 0;
		average += hash_table_sz[i];
		if (maxlength < hash_table_sz[i]) {
			maxlength = hash_table_sz[i];
			maxlengthid = i;
		}
	}
	average /= cells;

	printf("Average chain length: %.6lf\n", average);

	printf("Maximal chain length: %d\n", maxlength);
	cout << "Words in it:\n";
	for (int i = last[maxlengthid]; i != -1; i = nxt[i])
		cout << list[i].s << '\n';
	cout << '\n';

	int stringnumber = 0;
	cout << "All strings:\n";
	for (int i = 0; i < MOD; i++) {
		for (int j = last[i]; j != -1; j = nxt[j]) {
			stringnumber += times[j];
			cout << list[j].s;
			printf(": %d times\n", times[j]);
		}
	}
	printf("(totally: %d)\n", stringnumber);

	printf("Free cells: %d\n", MOD - cells);

	getchar();
	getchar();

	return 0;
}