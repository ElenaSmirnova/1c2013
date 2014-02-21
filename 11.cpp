// 11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#define maxN 1000

bool edge[maxN][maxN];
bool visited[maxN];
int n,m,components;

void dfs(int v) {
	visited[v]=1;
 	for(int w=0;w<n;w++) {
 	 	if(!visited[w] && edge[v][w]) {
 	 	 	dfs(w);
 	 	}
    }
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Enter number of vertexes: ");
	scanf("%d",&n);
	printf("Enter number of edges: ");
	scanf("%d",&m);
	printf("Enter edges: ");
	for(int i=0;i<m;i++) {
	    int a,b;
	    scanf("%d %d",&a,&b);
	    edge[--a][--b]=edge[b][a]=1;
	}	
	for(int i=0;i<n;i++) {
	 	if(!visited[i]) {
	 		dfs(i);
	 		components++;
	 	}
	}
	printf("There is %d components\n",components);
	scanf("\n");
	return 0;
}