#include <iostream>
#include <cstdio>
using namespace std;

//Binary tree : on-line finding the least common ancestor

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
};

int main() {
    int n, p, me;
	Btree T;

	T.link(1, 0);
	T.val[1] = 1;
	cout << "Input requests:\n1) write 0 A B to see the least common ancestor of them\n2) write A B to create vertex A and hang it to B or to move A\'s subtree to B\n3) write -1 to quit\nRoot node is 1. After each insertion you will see the tree.\n";
	for (;;) {
		cin >> me;
		if (me == -1) break;
		cin >> p;
		if (me == 0) {
			cin >> me;
			printf("%d\n", T.LCA(me, p));
			continue;
		}
		T.link(me, p);
		T.val[me] = me;
		T.print(T.begin());
		cout << endl;
	}
}
