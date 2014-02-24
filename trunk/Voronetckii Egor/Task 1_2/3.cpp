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
const int N = 1e4;

struct Edge;
struct Vertex
{
	Edge *firstEdge;
	bool was;
	int dist;
};
struct Edge
{
	int cost;
	Edge *nextEdge;
	Vertex *end;
};
void AddEdge(Vertex *u, Vertex *v, int cost)
{
	Edge *e1 = new Edge;
	Edge *e2 = new Edge;
	e1->nextEdge = u->firstEdge;
	e2->nextEdge = v->firstEdge;
	e1->end = v, e2->end = u;
	u->firstEdge = e1;
	v->firstEdge = e2;
	e1->cost = e2->cost = cost;
}

void DFS(Vertex *v)
{
	v->was = true;
	v->dist = -inf;
	for (Edge *e = v->firstEdge; e != NULL; e = e->nextEdge)
		if (!e->end->was) DFS(e->end);
}

void Dijkstra(Vertex *start, Vertex *end, Vertex *first)
{
	first->dist = 0;
	while (true)
	{
		Vertex *current = NULL;
		for (Vertex *i = start; i < end; i++)
			if (!i->was)
				if (current == NULL || i->dist < current->dist) current = i;
		if (current == NULL || current->dist == inf) return;
		current->was = true;
		for (Edge *e = current->firstEdge; e != NULL; e = e->nextEdge)
			if (e->end->dist > e->cost + current->dist)
			{
				e->end->dist = e->cost + current->dist;
				if (e->end->was == true)
				{
					for (Vertex *i = start; i < end; i++)
						i->was = false;
					DFS(first);
					return;
				}
			}
	}
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
	printf("Enter all edges in format (start vertex, end vertex, cost), numeration from 0\n");
	Vertex *vertexArray = new Vertex[vertexNum];
	for (int i = 0; i < vertexNum; i++)
		vertexArray[i].firstEdge = NULL, vertexArray[i].was = false, vertexArray[i].dist = inf;
	for (int i = 0; i < edgeNum; i++)
	{
		int start, end, cost;
		scanf("%d%d%d", &start, &end, &cost);
		if (start < 0 || end < 0 || start >= vertexNum || end >= vertexNum || cost >= N)
		{
			printf("Incorrect input\n");
			return 0;
		}
		AddEdge(vertexArray + start, vertexArray + end, cost);
	}
	int firstVertex;
	printf("Enter number of start vertex\n");
	scanf("%d", &firstVertex);
	if (firstVertex < 0 || firstVertex >= vertexNum)
	{
		printf("Incorrect input\n");
		return 0;
	}
	Dijkstra(vertexArray, vertexArray + vertexNum, vertexArray + firstVertex);
	printf("distantions:\n");
	for (int i = 0; i < vertexNum; i++)
		if (vertexArray[i].dist == inf) printf("inf ");
		else if (vertexArray[i].dist == -inf) printf("-inf ");
		else printf("%d ", vertexArray[i].dist);
	return 0;
}