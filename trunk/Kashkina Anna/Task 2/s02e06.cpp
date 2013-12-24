#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;

//List : get element by number

struct Anode {
	int next, val, check;
	Anode() {}
	Anode(int next) : next(next) {}
	Anode(int val, int next) : val(val), next(next), check(0) {}
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
	void killnode(int pre, int me) {
		if (pre)
			chnext(pre, sheaf[me]->next); 
		del(me, sheaf[me]->next); 
		begins.erase(me); ends.erase(me);
		delnode(me);
	}
	int count(int val) {
		int cur = begin(), res = 0;
		while (cur) {
			if (sheaf[cur]->val == val) {
				++res;
				sheaf[cur]->check = 1;
			}
			cur = sheaf[cur]->next;
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
		L.insert(i + 1, (i + 1 < v.size() ? i + 2 : 0), v[i]);
    for (int cur = L.begin(); cur; cur = L[cur]->next) {
 		if (!L[cur]->check) {
			printf ("%d occurences of %d\n", L.count(L[cur]->val), L[cur]->val);
		}
	}
	
	L.clear();
}
