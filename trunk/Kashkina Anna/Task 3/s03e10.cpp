#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

//Stack : bracket sequences

struct Btree;
struct Dtree;
void merge(Dtree*&, Dtree*, Dtree*);
pair<Dtree*, Dtree*> split(Dtree*, int);

struct Dtree {
        Dtree* l, *r;
        int val;
		char dat;
        int y;
        Dtree() {}
        Dtree(int val, char dat) : dat(dat), val(val), y(rand() * RAND_MAX + rand()), l(0), r(0) {}
};

Dtree* add(Dtree*&, int, char);

bool check(Dtree* t, int x) {
        if (t->val == x) return 1;
        if (t->val < x) return (t->r ? check(t->r, x) : 0);
        return (t->l ? check(t->l, x) : 0);
}

char& get(Dtree* t, int x) {
        if (t->val == x) return t->dat;
        if (t->val < x) return get(t->r, x);
        return get(t->l, x);
}

Dtree* add(Dtree*& t, int x, char dat) {
        pair<Dtree*, Dtree*> a = split(t, x);
        Dtree* res = new Dtree(x, dat);
        merge(t, a.first, res);
        merge(t, t, a.second);
        return res;
}

void merge(Dtree* &t, Dtree* l, Dtree* r) {
        if (!l || !r) {
                t = (l ? l : r);
        } else if (l->y > r->y) {
                merge(l->r, l->r, r);
                t = l;
        } else {
                merge(r->l, l, r->l);
                t = r;
        }
}

pair<Dtree*, Dtree*> split(Dtree* t, int x) {
        if (!t) return make_pair(t, t);
        if (t->val < x) {
                pair<Dtree*, Dtree*> res = split(t->r, x);
                t->r = res.first;
                res.first = t;
                return res;
        } else {
                pair<Dtree*, Dtree*> res = split(t->l, x);
                t->l = res.second;
                res.second = t;
                return res;
        }
}

void dfs(Dtree* t) {
        if (!t) return;
        dfs(t->l);
        cout << "#" << t->val << ": " << t->dat << " ";
        dfs(t->r);
}

struct myArray {
        Dtree* head;
        myArray() { head = new Dtree(-1, -1); }
        public: char& operator[] (const int& i) {
                if (!check(head, i)) { add(head, i, 0); }
                return get(head, i);
        }
};

struct stack {
	int len;
	myArray a;
	stack() : len(0), a(myArray()) {}
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
