#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;

//List : reversing list

struct Anode {
	Anode* next, *prev;
	int val, check, id;
	void init() {
		next = prev = this;
	}
	Anode(int id) : id(id) {init();}
	Anode(int id, int val) : id(id), val(val) {init();}
	void upd() {
		next->prev = this;
		prev->next = this;
	}
	friend void Aswap(Anode* a, Anode* b) {
		swap(a->prev, b->prev);
		swap(a->next, b->next);	
		if (a->next == a) swap(a->next, b->prev);
		else swap(a->prev, b->next);
		a->upd();
		b->upd();
	}
	friend void add(Anode* a, Anode* b) {
		Anode* rem = a->next;
		a->next = b;
		b->prev->next = rem;
		rem->prev = b->prev;
		b->prev = a;
	}
	friend void isolate(Anode* a) {
		a->prev->next = a->next;
		a->next->prev = a->prev;
		a->next = a->prev = a;
	}
	friend void reverse(Anode* a) {
		if (a->next->next == a) return;
		Anode* rem1 = a->prev;
		Anode* rem2 = a->next->next;
		rem1->next = rem2;
		rem2->prev = rem1;
		a->prev = a->next;
		a->prev->next = a;
		reverse(rem1);
		add(a, rem1);
	}
};

struct Alist {
	map<int, Anode*> sheaf;
	void del(int, int);
	Anode* begin() {
		return sheaf[0]->next;
	}
	Anode* end() {
		return sheaf[0];
	}
	Alist() {
		sheaf[0] = new Anode(0);
	}
	void delnode(Anode* i) {
		add(i->prev, i->next);
		delete(i);
		sheaf.erase(i->id);
	}
	void clear() {
		while (sheaf.size())
			delnode(sheaf.begin()->second);
	}
	int size() {
		return sheaf.size() - 1;
	}
	void insprev(int a, int b, int val) {
		if (sheaf.find(a) == sheaf.end()) {
			sheaf[a] = new Anode(a, val);
		} else
			sheaf[a]->val = val;
		if (sheaf.find(b) == sheaf.end()) {
			sheaf[b] = new Anode(b);
		}
		add(sheaf[a], sheaf[b]);
	}
	void insnext(int a, int b, int val) {
		insprev(a, b, val);
		Aswap(sheaf[a], sheaf[b]);
	}
	int count(int val) {
		Anode* cur = begin();
		int res = 0;
		while (cur) {
			if (cur->val == val) {
				++res;
				cur->check = 1;
			}
			cur = cur->next;
		}
		return res;
	}
	Anode* scan() {
		int a;
		vector<int> v;
		for (int i = 1; ; ++i) {
			cin >> a;
			if (a == -1) break;
			v.push_back(a);
		}
		int minf = size() + 1;
		for (int i = 0; i < v.size(); ++i)
			insprev(i + minf, (i + 1 < v.size() ? i + minf + 1 : minf), v[i]);
		if (v.size()) {
			v.clear();
			return sheaf[minf];
		}
		return end();
	}
	void print() {
		for (Anode* cur = begin(); cur != end(); cur = cur->next)
			printf("%d ", cur->val);
	}
public:
 	Anode* operator[] (const int& i) {
		return sheaf[i];
	}
};



int main() {
    int a, b, c;
	vector<int> v;
	Alist L1;
	cout << "Input nodes of the first sorted list one-by-one.\nEnd your input with -1\n";
	add(L1.end(), L1.scan());
	cout << "Input nodes of the second sorted list one-by-one.\nEnd your input with -1\n";
	Anode *i2 = L1.scan();
	Anode *i1 = L1.begin();
	while (i2 != L1.end()) {
		Anode *nextf = (i2 == i2->next ? L1.end() : i2->next);
		while ((i1 != L1.end()) && (i1->val < i2->val)) i1 = i1->next;
		isolate(i2);
		add(i2, i1);
		i2 = nextf;
	}
	L1.print();
	
	
	L1.clear();
}
