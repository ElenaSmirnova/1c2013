#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//Binary tree : on-line deleting the subtree

struct Btree;
struct Dtree;
void merge(Dtree*&, Dtree*, Dtree*);
pair<Dtree*, Dtree*> split(Dtree*, int);

struct Dtree {
        Dtree* l, *r;
        int val, dat;
        int y;
        Dtree() {}
        Dtree(int val, int dat) : dat(dat), val(val), y(rand() * RAND_MAX + rand()), l(0), r(0) {}
};

Dtree* add(Dtree*&, int, int);

bool check(Dtree* t, int x) {
        if (t->val == x) return 1;
        if (t->val < x) return (t->r ? check(t->r, x) : 0);
        return (t->l ? check(t->l, x) : 0);
}

int& get(Dtree* t, int x) {
        if (t->val == x) return t->dat;
        if (t->val < x) return get(t->r, x);
        return get(t->l, x);
}

Dtree* add(Dtree*& t, int x, int dat) {
        pair<Dtree*, Dtree*> a = split(t, x);
        Dtree* res = new Dtree(x, dat);
        merge(t, a.first, res);
        merge(t, t, a.second);
        return res;
}

void merge(Dtree* &t, Dtree* l, Dtree* r) {
        if (!l || !r) {
                t = (l ? l : r);
        } else if (l->y > r->y) {
                merge(l->r, l->r, r);
                t = l;
        } else {
                merge(r->l, l, r->l);
                t = r;
        }
}

pair<Dtree*, Dtree*> split(Dtree* t, int x) {
        if (!t) return make_pair(t, t);
        if (t->val < x) {
                pair<Dtree*, Dtree*> res = split(t->r, x);
                t->r = res.first;
                res.first = t;
                return res;
        } else {
                pair<Dtree*, Dtree*> res = split(t->l, x);
                t->l = res.second;
                res.second = t;
                return res;
        }
}

void dfs(Dtree* t) {
        if (!t) return;
        dfs(t->l);
        cout << "#" << t->val << ": " << t->dat << " ";
        dfs(t->r);
}

struct myArray {
        Dtree* head;
        myArray() { head = new Dtree(-1, -1); }
        public: int& operator[] (const int& i) {
                if (!check(head, i)) { add(head, i, 0); }
                return get(head, i);
        }
};

struct Btree {
        myArray p, l, r, val, sum;
        Btree() : p(myArray()), r(myArray()), val(myArray()), sum(myArray()) {}
	void upd(int id) {
		sum[id] = sum[l[id]] + sum[r[id]];
	}

	void link(int a, int b) {
		if (l[p[a]] == a || r[p[a] == a]) {
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
};

int main() {
    int n, p, me, v;
	Btree T;

	cout << "Input requests:\n1) write 0 A delete subtree A\n2) write A B to create vertex A and hang it to B (or make it root, if 0)\n3) write -1 to quit\nAfter each insertion you will see the tree.\n";
	for (;;) {
		cin >> me;
		if (me == -1) break;
		cin >> p;
		if (me == 0) {
			T.link(p, p);
		} else {
			T.val[me] = me;
			T.link(me, p);
		}
		T.print(T.begin());
		cout << endl;
	}
}
