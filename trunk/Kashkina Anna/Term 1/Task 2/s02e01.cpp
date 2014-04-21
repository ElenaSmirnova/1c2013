#include <iostream>
#include <cstdio>
#include <map>
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
	void clear() {
		while (sheaf.size()) {
			delete(sheaf.begin()->second);
			sheaf.erase(sheaf.begin());
		}
	}
	void insert(int a, int b, int val) {
		sheaf[a] = new Anode(val, b);
	}
public:
 	Anode* operator[] (const int& i) {
		return sheaf[i];
	}
};



int main() {
    int a, b, c;
	Alist L;
	cout << "Input nodes of the list (their values one-by-one). End your input with -1\n";
	for (int i = 1; ; ++i) {
		cin >> a;
		if (a == -1) break;
		L.insert(i, i + 1, a);
	}
	cout << "Input indexes of the nodes to get the information about them. End your input with -1\n";
	while (1) {
		cin >> a;
		if (a == -1) break;
		Anode* m = L[a];
		if (m) printf("Value: %d\n", m->val);
		else printf("Invalid number of the node\n");
	}
	L.clear();
}
