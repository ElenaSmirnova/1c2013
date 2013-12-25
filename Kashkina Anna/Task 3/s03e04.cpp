#include <iostream>
#include <cstdio>
using namespace std;

//Binary tree : on-line inserting

const int maxn = 200000;
struct Btree {
	int p[maxn], l[maxn], r[maxn], val[maxn], sum[maxn];
	void upd(int id) {
		sum[id] = sum[l[id]] + sum[r[id]];
	}

	void link(int a, int b) {
		if (l[b] && r[b]) return;
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

	void print(int node) {
		if (!node) return;
		printf("(%d", val[node]);
		if (l[node] && r[node]) {
			printf(":(");
			print(l[node]);
			printf(";");
			print(r[node]);
			printf(")");
		} else {
			if (l[node] || r[node]) {
				printf(":");
				print(l[node] + r[node]);
			}
		}
		printf(")");
	}
};

int main() {
    int n, p, me;
	Btree T;

	T.link(1, 0);
	T.val[1] = 1;
	cout << "Input requests: two numbers A and B. If A = 0, this prints B\'s parent.\nIf A > 0: If A already exists, this will move it to B, otherwise A will be created.\nEnd your input with single -1\nRoot node is 1. After each insertion you will see the tree.\n";
	for (;;) {
		cin >> me;
		if (me == -1) break;
		cin >> p;
		if (me == 0) {
			printf("%d\n", T.p[p]);
			continue;
		}
		T.link(me, p);
		T.val[me] = me;
		T.print(T.begin());
		cout << endl;
	}
}
