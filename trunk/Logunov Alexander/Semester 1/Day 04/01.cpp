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

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	MyString a, b("123"), c("123456");
	a = b + c;
	a.print();
	b.clone(a);
	a = "124";
	cout << "Length of " << b.s << " equals to " << b.length() << '\n';
	cout << a.s << " < " << b.s << "? " << (a < b) << '\n';
	cout << a.s << " = " << b.s << "? " << (a == b) << '\n';
	cout << a.s << " > " << b.s << "? " << (a > b) << '\n';

	b = c.substr(1, 3);
	c = "";	
	cout << "Is B empty? " << b.empty() << '\n';
	cout << "Is C empty? " << c.empty() << '\n';

	char *d = a.toarray();
	int sized = a.length();
	for (int i = 0; i < sized; i++)
		cout << d[i];
	cout << '\n';

	getchar();

	return 0;
}