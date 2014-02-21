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
const int INF = 1E9; //constant for non-existing edges

int n, m, a, b, w;
int graph[MAXN][MAXN], dist[MAXN];
int visited[MAXN];

void dijkstra(int start) {
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
		dist[i] = INF;
	}
	
	visited[start] = 1;
	dist[start] = 0;

	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++)
			if (visited[j] == 1 && (v == -1 || dist[j] < dist[v]))
				v = j;

		if (v == -1)
			break;
		
		for (int j = 0; j < n; j++)
			if (graph[v][j] != INF && dist[j] > dist[v] + graph[v][j]) {
				visited[j] = 1;
				dist[j] = dist[v] + graph[v][j];
			}
		
		visited[v] = 2;
	}
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cout << "Print number of vertexes N and number of edges M:\n";
	cin >> n >> m;
	cout << "Now print M edges in format: {start, finish, weight}.\n";

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			graph[i][j] = INF;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		graph[a][b] = graph[b][a] = w;
	}

	cout << "From what vertex do you want to start?\n";
	cin >> a;
	dijkstra(a);

	printf("All distances:\n");
	for (int i = 0; i < n; i++) {
		printf("Vertex %d: ", i);
		if (visited[i] == 0)
			cout << "no way\n";
		else
			cout << dist[i] << '\n';
	}
	getchar();
	getchar();

	return 0;
}