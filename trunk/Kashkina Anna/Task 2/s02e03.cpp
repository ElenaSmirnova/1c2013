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
	void clear() {
		while (sheaf.size()) {
			delete(sheaf.begin()->second);
			sheaf.erase(sheaf.begin());
		}
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
		if (sheaf.find(b) == sheaf.end()) sheaf[b] = new Anode(-1, 0);
		sheaf[a] = new Anode(val, b);
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
	cout << "Input nodes of the list by three numbers: number of the node, next node (0, if no such) and its value\nEnd your input with -1\n";
	while (1) {
		cin >> a;
		if (a == -1) break;
		cin >> b >> c;
		L.insert(a, b, c);
	}
	int cur = L.begin(), past = 0;
	while (1) {
		int nextf = L[cur]->next;
		L.chnext(cur, past);
		past = cur;
		cur = nextf;
		if (!cur) break;
	}
	cur = L.begin();
	while (1) {
		printf("%d(at %d) ", L[cur]->val, cur);
		if (cur == L.end()) break;
		printf("=> ");
		cur = L[cur]->next;
	}
	L.clear();
}
