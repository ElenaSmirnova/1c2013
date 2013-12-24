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
	cout << "Input nodes of the list by 3 numbers: number of the node, number of the next (0, if no such) node and the value\nEnd your input with -1\n";
	while (1) {
		cin >> a;
		if (a == -1) break;
		cin >> b >> c;
		L.insert(a, b, c);
	}
	int cur = L.begin();
	pair<pair<int, int>, int> minf = make_pair(make_pair(L[L.begin()]->val, 1), L.begin());
	for (int i = 1; ; ++i) {
		minf = min(minf, make_pair(make_pair(L[cur]->val, i), cur));
		if (cur == L.end()) break;
		cur = L[cur]->next;
	}
	printf("Node %d is %d-th from the beginning (node %d) and has the least value (%d)\n", minf.second, minf.first.second, L.begin(), minf.first.first);
	L.clear();
}
