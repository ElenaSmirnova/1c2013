#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;

//List : get element by number

struct Anode {
	int next, val;
	Anode() {}
	Anode(int next) : next(next) {}
	Anode(int val, int next) : val(val), next(next) {}
};

struct Alist {
	map<int, Anode*> sheaf;
	map<int, int> ins, outs;
	set<int> begins, ends;
	int begin() {
		return *begins.begin();
	}
	int end() {
		return *ends.begin();
	}
	void delnode(int i) {
		delete(sheaf[i]);
		sheaf.erase(i);
	}
	void clear() {
		while (sheaf.size())
			delnode(sheaf.begin()->first);
	}
	void upd(int i) {
		begins.erase(i);
		ends.erase(i);
		if (ins[i] == 0) begins.insert(i);
		if (outs[i] == 0) ends.insert(i);
	}
	void add(int a, int b) {
		if (a && b) {
			++outs[a]; ++ins[b]; upd(a); upd(b);
		}
	}
	void del(int a, int b) {
		if (a && b) {
			--outs[a]; --ins[b]; upd(a); upd(b);
		}
	}
	int size() {
		return sheaf.size();
	}
	void insert(int a, int b, int val) {
		add(a, b);
		if (sheaf.find(a) != sheaf.end()) delete(sheaf[a]);
		sheaf[a] = new Anode(val, b);
	}
	void killbegin() {
		int me = begin();
		del(me, sheaf[me]->next);
		begins.erase(me); ends.erase(me);
		delnode(me);
	}
	void chnext(int a, int b) {
		del(a, sheaf[a]->next);
		sheaf[a]->next = b;
		add(a, sheaf[a]->next);
	}
public:
 	Anode* operator[] (const int& i) {
		return sheaf[i];
	}
};



int main() {
    int a, b, c;
	Alist L;
	cout << "Input nodes of the list by 2 numbers: number of the node and number of the next node (0, if no such)\nEnd your input with -1\n";
	while (1) {
		cin >> a;
		if (a == -1) break;
		cin >> b;
		L.insert(a, b, 0);
	}
	int cur = L.begin(), past = 0;
	while (L.begins.size())
		L.killbegin();
	if (L.size()) cout << "Has cycles\n";
	else cout << "No cycles\n";
	L.clear();
}
