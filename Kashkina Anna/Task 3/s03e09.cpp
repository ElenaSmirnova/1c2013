#include <iostream>
#include <cstdio>
using namespace std;

//Binary tree : zero ways

const int maxn = 200000;
struct Btree {
	int p[maxn], l[maxn], r[maxn], val[maxn], sum[maxn];
	void upd(int id) {
	}
	void isolate(int a) {
		if (l[p[a]] == a || r[p[a]] == a) {
			if (l[p[a]] == a) l[p[a]] = 0;
			if (r[p[a]] == a) r[p[a]] = 0;
			upd(p[a]);
		}
	}
	void llink(int a, int b) {
		isolate(a);
		l[b] = a;
		upd(b);
		p[a] = b;
	}
	void rlink(int a, int b) {
		isolate(a);
		r[b] = a;
		upd(b);
		p[a] = b;
	}
	void link(int a, int b) {
		if (l[b] == 0) 
			llink(a, b);
		else rlink(a, b);
	}

	int begin() {
		if (l[0]) return l[0];
		return r[0];
	}	

	void print(int node) {
		if (!node) return;
		printf("(%d", node);
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
	
	int LCA(int n1, int n2) {
		int v1 = n1, v2 = n2;
		while (v1) ++sum[v1], v1 = p[v1];
		while (v2) ++sum[v2], v2 = p[v2];

		v1 = 1;
		while (1) {
			if (sum[l[v1]] == sum[v1]) {
				v1 = l[v1];
				continue;
			}
			if (sum[r[v1]] == sum[v1]) {
				v1 = r[v1];
				continue;
			}
			break;
		}
		int res = v1;
		v1 = n1; v2 = n2;
		while (v1) --sum[v1], v1 = p[v1];
		while (v2) --sum[v2], v2 = p[v2];
		return res;
	}
	void find(int x, int at) {
		if (!at) return;
		if (val[at] == x) printf("#%d ", at);
		find(x, l[at]);
		find(x, r[at]);
	}
	void skip(int x) {
		if (l[p[x]] == x) l[p[x]] = 0;
		if (r[p[x]] == x) r[p[x]] = 0;
		if (l[x]) link(l[x], p[x]);
		if (r[x]) link(r[x], p[x]);
		l[x] = r[x] = 0;
		link(x, x);
	}
	void setsum(int a) {
		if (a == 1) return;
		if (l[p[a]] == a) sum[a] = 1;
		else sum[a] = -1;
	}
	
	void dfs(int a, int s = 0) {
		if (!a) return;
		if (s == 0) {
			int z = a;
			printf("{");
			while (z) {printf("%d", z); if (z != 1) printf(", "); z = p[z]; }
			printf("}\n");
		}
		dfs(l[a], s + sum[l[a]]);
		dfs(r[a], s + sum[r[a]]);
	}
};

int main() {
    int n, p, me, v;
	Btree T;
	T.val[1] = 1;
	T.link(1, 0);
	cout << "Input requests:\n1) write 0 A B to add node A to the left of B\n2) write 1 A B to add node A to the right of B\n3) write -1 to quit\nRoot node is 1. After each request you will see the tree and all 0-sum sequences.\n";
	for (;;) {
		cin >> me;
		if (me == -1) break;
		cin >> p >> v;
		if (me == 0) {
			T.llink(p, v);
		} else {
			T.rlink(p, v);
		}
		T.setsum(T.p[p]);
		T.print(T.begin());
		cout << endl;
		T.dfs(T.begin());
		cout << endl;
	}
}
