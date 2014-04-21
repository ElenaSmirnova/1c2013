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
bool answer;

void hamilton(int a, int le)
{
	was[a] = true;
	if(edg[a][0] == 1 && le == V)
		answer = true;
	else
	{
		for(int i = 0; i < V; i++)
		{
			if(edg[a][i] == 1 && !was[i])
				hamilton(i, le + 1);
		}
	}
	was[a] = false;
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
		edg[y][x] = 1;
	}
	
	hamilton(0, 1);

	if(answer)
		printf("yes");
	else
		printf("no");
	getchar();
	getchar();

}





