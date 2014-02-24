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

typedef long long ll;
typedef long double ld;
const ld eps = 1e-12;
const int inf = 1e9;
const int N = 2e6;

bool Edges[30][30];
bool Dynamic[N][30];

int main()
{     
	int vertexNum, edgeNum;
	printf("Enter number of vertices and edges\n");
	scanf("%d%d", &vertexNum, &edgeNum);
	if (vertexNum < 0 || edgeNum < 0 || vertexNum > 20 || edgeNum > N)
	{
		printf("Incorrect input\n");
		return 0;
	}
	printf("Enter all edges in format (start vertex, end vertex), numeration from 0\n");
	for (int i = 0; i < edgeNum; i++)
	{
		int start, end;
		scanf("%d%d", &start, &end);
		if (start < 0 || end < 0 || start >= vertexNum || end >= vertexNum)
		{
			printf("Incorrect input\n");
			return 0;
		}
		Edges[start][end] = true, Edges[end][start] = true;
	}
	Dynamic[1][0] = true;
	for (int mask = 1; mask < (1 << vertexNum); mask++)
		for (int j = 0; j < vertexNum; j++)
			if (Dynamic[mask][j])
				for (int k = 1; k < vertexNum; k++)
					if (!(mask & (1 << k)) && Edges[j][k])
						Dynamic[mask | (1 << k)][k] = true;
	bool answer = false;
	for (int i = 1; i < vertexNum; i++)
		if (Dynamic[(1 << vertexNum) - 1][i] == true && Edges[i][0] == true) answer = true;
	if (vertexNum != 2 && (vertexNum < 2 || answer)) printf("yes\n");
	else printf("no\n");
	return 0;
}