#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
int n, m;
vector<vector<int> > e;
vector<int> usd;

void dfs(int v) {
    usd[v] = 1;
    for (int j = 0; j < (int)e[v].size(); ++j)
        if (!usd[e[v][j]]) dfs(e[v][j]);
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
    int answer = 0;
    for (int i = 1; i <= n; ++i)
    	if (!usd[i]) {
    		dfs(i);
    		++answer;
    	}
    cout << "3. your graph has " << answer << " connected components\n";
}