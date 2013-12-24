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
public:
 	Anode* operator[] (const int& i) {
		return sheaf[i];
	}
};



int main() {
    int a, b, c;
	vector<int> v;
	Alist L;
	cout << "Input nodes of the list one-by-one.\nEnd your input with -1\n";
	for (int i = 1; ; ++i) {
		cin >> a;
		if (a == -1) break;
		v.push_back(a);
	}
	for (int i = 0; i < v.size(); ++i)
		L.insprev(i + 1, (i + 1 < v.size() ? i + 2 : 0), v[i]);
	if (v.size())
		add(L[0], L[1]);
    for (Anode* cur = L.begin(); cur != L.end(); ) {
		Anode* mcur = cur, *nextf = cur->next;
		while (mcur->val < mcur->prev->val && mcur->prev != L.end()) Aswap(mcur, mcur->prev);
		cur = nextf;
	}
	for (Anode* cur = L.begin(); cur != L.end(); cur = cur->next)
		printf("%d ", cur->val);
        	
	L.clear();
}
