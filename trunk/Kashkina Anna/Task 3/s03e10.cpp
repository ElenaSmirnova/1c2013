#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

//Stack : bracket sequences

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

void fail(int at) {
	cout << "Bracket number " << at << " is wrong\n";
	exit(0);
}

int main() {
	stack S;
	string s;
	cout << "Input the sequence of brackets:\n";
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (string("([{<").find(s[i]) != string::npos)
			S.push(s[i]);
		else if (!S.size() || abs(int(S.pop()) - int(s[i])) > 3)
			fail(i + 1);
	}
	if (S.size()) fail(s.size() + 1);
	cout << "Correct\n";
}
