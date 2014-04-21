#include <cstdio>
#include <cassert>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int edg[100][100];
bool was[100];
int V, E, x, y, res, ind, w;
int shortpath[100];

void minp(int a)
{
	for(int i = 0; i < V; i++)
		shortpath[i] = 100500;
	shortpath[a] = 0;
	for(int j = 0; j < V; j++)
	{
		int min = 100500;
		for (int i = 0; i < V; i++)
		{
			if(!was[i] && shortpath[i] < min)
			{
				min = shortpath[i];
				ind = i;
			}
		}
		was[ind] = true;

		for (int i = 0; i < V; i++)
			if(!was[i] && edg[ind][i] + shortpath[ind] < shortpath[i])
				shortpath[i] = edg[ind][i] + shortpath[ind];
	}
}

int main()
{
	printf("print the number of vertices and edges\n");
	scanf("%d%d", &V, &E);

	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			edg[i][j] = 100500;

	for(int i = 0; i < V; i++)
		edg[i][i] = 0;

	printf("Print the edges with weights (numeration of vertices starts from 0)\n");
	for(int i = 0; i < E; i++)
	{
		scanf("%d%d%d", &x, &y, &w);
		edg[x][y] = w;
		edg[y][x] = w;
	}

	minp(0);

	for(int i = 0; i < V; i++)
		printf("%d\n", shortpath[i]);

	getchar();
	getchar();
}





