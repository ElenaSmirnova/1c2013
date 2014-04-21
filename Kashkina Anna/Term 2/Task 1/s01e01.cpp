#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
int n, m;
vector<vector<int> > e;
vector<int> usd;

bool findcycle(int v, int hm = 1) {
    usd[v] = 1;
    for (int j = 0; j < (int)e[v].size(); ++j)
        if ((!usd[e[v][j]] && findcycle(e[v][j], hm + 1)) || (hm == n && e[v][j] == 1)) {
                if (hm == n) {cout << "3. Your graph has hamiltonian cycle:\n";}
                cout << v << " ";
                return 1;
        }
    usd[v] = 0;
    return 0;
}

int main() {
    cout << "1. print number of vertices and number of edges\n";
    cin >> n >> m;
    e.resize(n + 1);
    usd.resize(n + 1);

    cout << "2. print " << m << " pairs of positive integers in range 1.." << n <<
" to make the set of edges\n";
    int af, bf;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &af, &bf);
        e[af].pb(bf);
        e[bf].pb(af);
    }
    if (!findcycle(1)) cout << "3. No hamiltonian cycles found\n";
}