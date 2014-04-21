#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

//List : removing positive elements

struct Astr {
	string s;
	Astr() : s("") {}
	Astr(string s) : s(s) {}
	Astr substr(int i, int len) {
		return Astr(s.substr(i, len));
	}
	int size() {
		return s.size();
	}
	bool empty() {
		return s.empty();
	}
	const char* c_str() {
		return s.c_str();
	}
	void clear() {
		s.clear();
	}
	Astr clone() {
		return Astr(s);
	}
	friend Astr operator+(const Astr& a, const Astr& b) {
		return Astr(a.s + b.s);
	} 
public:
	 char& operator[](const int& i) {
		return s[i];
	}
	friend bool operator==(const Astr& a, const Astr& b) {
		return a.s == b.s;
	}

}; 


int main() {
    int n, F, E;

	cout << (Astr("Abacaba") + Astr("dabacaba")).c_str() << endl;
	cout << (Astr("0123456").substr(2, 3)).c_str() << endl;
}
