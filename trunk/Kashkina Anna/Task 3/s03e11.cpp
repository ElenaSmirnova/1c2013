#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

//Stack : reversing halfs

const int maxn = 200000;
struct stack {
	char a[maxn];
	int len;
	stack() : len(0) {}
	void push(char c) {
		a[len] = c;
		++len;
	}
	char pop() {
		if (len == 0) return '*';
		--len;
		return a[len];
	}
	char top() {
		if (len == 0) return '*';
		return a[len - 1];
	}
	int size() {
		return len;
	}
};

int main() {
	stack S;
	string s;
	cout << "Input the string:\n";
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		S.push(s[i]);
		if (((i + 1) % (s.size() / 2)) == 0) {
			while (S.size()) cout << S.pop();
		}
	}
}
