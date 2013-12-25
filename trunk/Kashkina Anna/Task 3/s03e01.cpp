#include <iostream>
#include <cstdio>
using namespace std;

//Binary tree : in-order (symmetric) traversal

const int maxn = 200000;
struct Btree {
	int p[maxn], l[maxn], r[maxn], val[maxn], sum[maxn];
	void upd(int id) {
		sum[id] = sum[l[id]] + sum[r[id]];
	}

	void link(int a, int b) {
		if (p[a]) {
			if (l[p[a]] == a) l[p[a]] = 0;
			if (r[p[a]] == a) r[p[a]] = 0;
			upd(p[a]);
		}
		if (l[b] == 0) 
			l[b] = a;
		else r[b] = a;
		upd(b);
		p[a] = b;
	}

	int begin() {
		if (l[0]) return l[0];
		return r[0];
	}	

	int print(int node) {
		if (!node) return 0;
		printf("%d ", val[node]);
		int s = print(l[node]);
		s += print(r[node]);
		if (s > 0)
			printf("%d ", val[node]);
		return 1;
	}
};

int main() {
    int n, p;
	Btree T;
	cout << "Input number of entries in tree\n";
	cin >> n;
	cout << "Input " << n << " numbers: i-th of them = the parent node of i-th node or 0, if no such\n";
	for (int i = 1; i <= n; ++i) {
		cin >> p;
		T.link(i, p);
		T.val[i] = i;
	}
	T.print(T.begin());
}
