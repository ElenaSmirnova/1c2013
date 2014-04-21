#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
int n, m;
vector<vector<pair<int, int> > > e;
vector<int> usd, dest;

void dijkstra(int start) {
	for (int i = 1; i <= n; ++i) dest[i] = -1;
	dest[start] = 0;
	for (int i = 1; i <= n; ++i) {
		int minf = -1;
		int who = -1;
		for (int j = 1; j <= n; ++j)
			if (dest[j] != -1) {
				if ((minf == -1 || minf < dest[j]) && !usd[j]) {
					minf = dest[j];
					who = j;
				}
			}
		usd[who] = 1;
		for (int j = 0; j < e[who].size(); ++j)
			if (dest[e[who][j].first] == -1 || 
			dest[e[who][j].first] > dest[who] + e[who][j].second) {
				dest[e[who][j].first] = dest[who] + e[who][j].second;
			}
	}
	for (int i = 1; i <= n; ++i)
		cout << dest[i] << " ";
	cout << endl;
}

int main() {
    cout << "1. print number of vertices and number of edges\n";
    cin >> n >> m;
    e.resize(n + 1);
    usd.resize(n + 1);
	dest.resize(n + 1);

    cout << "2. print " << m << " triples of integers: first two in range 1.." << n <<
" and third -- non-negative weight\n";
    int af, bf, cf;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &af, &bf, &cf);
        e[af].pb(mp(bf, cf));
        e[bf].pb(mp(af, cf));
    }
    cout << "3. print number of vertice from which to start\n";
    int st;
    cin >> st;
    dijkstra(st);
}