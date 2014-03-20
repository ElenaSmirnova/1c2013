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
int V, E, x, y, res;

void dfs(int x)
{
	was[x] = true;
	for(int i = 0; i < V; i++)
	{
		if(edg[x][i] == 1 && !was[i])
			dfs(i);
	}
}

int main()
{
	printf("print the number of vertices and edges\n");
	scanf("%d%d", &V, &E);
	printf("Print the edges (numeration of vertices starts from 0)\n");
	for(int i = 0; i < E; i++)
	{
		scanf("%d%d", &x, &y);
		edg[x][y] = 1;
	}
	
	for(int i = 0; i < V; i++)
		if(!was[i])
		{
			res++;
			dfs(i);
		};

	printf("%d", res);
	getchar();
	getchar();

}