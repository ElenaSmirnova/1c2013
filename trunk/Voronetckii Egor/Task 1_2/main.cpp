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
const int N = 1e5;

struct Edge;
struct Vertex
{
	Edge *firstEdge;
	bool was;
};
struct Edge
{
	Edge *nextEdge;
	Vertex *end;
};
void AddEdge(Vertex *u, Vertex *v)
{
	Edge *e1 = new Edge;
	Edge *e2 = new Edge;
	e1->nextEdge = u->firstEdge;
	e2->nextEdge = v->firstEdge;
	e1->end = v, e2->end = u;
	u->firstEdge = e1;
	v->firstEdge = e2;
}

void DFS(Vertex *v)
{
	v->was = true;
	for (Edge *e = v->firstEdge; e != NULL; e = e->nextEdge)
		if (!e->end->was) DFS(e->end);
}
       
int main()
{     
	int vertexNum, edgeNum;
	printf("Enter number of vertices and edges\n");
	scanf("%d%d", &vertexNum, &edgeNum);
	if (vertexNum < 0 || edgeNum < 0 || vertexNum > N || edgeNum > N)
	{
		printf("Incorrect input\n");
		return 0;
	}
	printf("Enter all edges in format (start vertex, end vertex), numeration from 0\n");
	Vertex *vertexArray = new Vertex[vertexNum];
	for (int i = 0; i < vertexNum; i++)
		vertexArray[i].firstEdge = NULL, vertexArray[i].was = false;
	for (int i = 0; i < edgeNum; i++)
	{
		int start, end;
		scanf("%d%d", &start, &end);
		if (start < 0 || end < 0 || start >= vertexNum || end >= vertexNum)
		{
			printf("Incorrect input\n");
			return 0;
		}
		AddEdge(vertexArray + start, vertexArray + end);
	}
	int componentCount = 0;
	for (int i = 0; i < vertexNum; i++)
		if (!vertexArray[i].was) DFS(vertexArray + i), componentCount++;
	printf("%d connected components\n", componentCount);
	return 0;
}