#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> 
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 55;

int n, m, a, b, components;
bool graph[MAXN][MAXN];
bool visited[MAXN];

void dfs(int v) {
	visited[v] = 1;
	for (int w = 0; w < n; w++) {
		if (graph[v][w] && !visited[w])
			dfs(w);
	}
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

	components = 0;
	for (int i = 0; i < n; i++)
		if (!visited[i]) {
			components++;
			dfs(i);
		}

	printf("Your graph has %d components!\n", components);
	getchar();
	getchar();

	return 0;
}