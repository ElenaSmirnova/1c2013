#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;

//List : finding cycles

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
	void add(Anode* a, Anode* b) {
		Anode* rem = a->next;
		a->next = b;
		b->prev->next = rem;
		rem->prev = b->prev;
		b->prev = a;
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
	cout << "Input nodes of the list by two numbers: node and the next node (0, if no such).\nEnd your input with single -1\n";
	for (int i = 1; ; ++i) {
		cin >> a;
		if (a == -1) break;
		cin >> b;
		L.insprev(a, b, 0);
	}
	int hm = 0;
	
	for (Anode* cur = L.begin(); cur != L.end(); cur = cur->next)
		++hm;
	if (hm < L.size()) cout << "Cyclic\n";
	else cout << "Acyclic\n";

	L.clear();
}
