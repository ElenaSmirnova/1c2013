#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> 
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 55;
const int INF = 1E9; //constant for non-existing edges

int n, m, a, b, w, used;
bool graph[MAXN][MAXN];
bool visited[MAXN];
vector<int> path;

bool bruteforce(int v) {
	if (used == n && graph[v][0]) 
		return 1;
	
	for (int i = 0; i < n; i++) {
		if (graph[v][i] && !visited[i]) {
			used++;
			visited[i] = 1;
			path.push_back(i);
			if (bruteforce(i))
				return 1;
			path.pop_back();
			visited[i] = 0;
			used--;
		}
	}

	return 0;
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cout << "Print number of vertexes N and number of edges M:\n";
	cin >> n >> m;
	cout << "Now print M pairs of integers (numeration from 0).\n";

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			graph[i][j] = 0;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a][b] = graph[b][a] = 1;
	}

	for (int i = 0; i < n; i++)
		visited[i] = 0;

	used = 1;
	visited[0] = 1;
	path.push_back(0);
	if (bruteforce(0)) {
		cout << "Hamiltonian cycle exists!\n";
		for (int i = 0; i < n; i++)
			cout << path[i] << ' ';
		cout << '\n';
	} else {
		cout << "Hamiltonian cycle doesn't exist.\n";
	}

	getchar();
	getchar();

	return 0;
}