#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

//List : removing positive elements

const int base = 239;
const int mod = 10007;

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
	int hash() {
		int h = 0;
		for (int i = 0; i < s.size(); ++i)
			h = (h * base + s[i] + mod) % mod;
		return h;
	} 
public:
	 char& operator[](const int& i) {
		return s[i];
	}
	friend bool operator==(const Astr& a, const Astr& b) {
		return a.s == b.s;
	}
	friend bool operator!=(const Astr& a, const Astr& b) {
		return !(a == b);
	}
}; 

struct Hnode {
	Hnode* next;
	Astr me;
	int len;
	Hnode() {}
	Hnode(Astr me) : me(me) {}
	Hnode(Astr me, int len) : me(me), len(len) {}
};
struct Htable {
	Hnode* head[mod];
	int em, sum, maxf;
	Htable() : em(mod), sum(0), maxf(0) {memset(head, 0, sizeof head);}
	bool check(Astr s) {
		Hnode* begin = head[s.hash()];
		while (begin && s != begin->me) begin = begin->next;
		return (begin != 0);
	}
	void ins(Astr s) {
		if (check(s)) return;
		Hnode* tmp;
		int mhash = s.hash();
		tmp = head[mhash];
		if (!tmp) --em;
		head[mhash] = new Hnode(s, (tmp ? tmp->len + 1 : 1));
		head[mhash]->next = tmp;
		++sum;
		maxf = max(maxf, head[mhash]->len);
	}
	double LF() {
		return (sum + 0.0) / (mod - em);
	}
	int empty() {
		return em;
	}
};

int main() {
    int n, F, E;
	Htable H;
	string s;
	int hm = 0;
	while (!cin.eof()) {
		cin >> s;
		++hm;
		H.ins(Astr(s));
	}
	cout << "Load factor: " << H.LF() << "\nEmpty entries: " << H.empty() << "\nNumber of entries: " << H.sum << endl << "Number of chains: " << mod - H.empty() << endl;
}
