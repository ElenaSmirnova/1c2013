#include "stdafx.h"
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include "graph.h"

using namespace std;

bool exists(const char *filename) 
{
	return ifstream(filename) != nullptr;
}

int main()
{
	if (exists("graph.txt")) 
		freopen("graph.txt", "r", stdin);
	else 
	{
		printf("File graph.txt does not exist\n");

		return 0;
	}

	int number = 0;
	int edges = 0;
	scanf("%d%d", &number, &edges);

	int **matrix = createIntMatrix(number + 1);

	for (int i = 0; i < edges; i++) 
	{
		int firstNode = 0;
		int secondNode = 0;
		int value = 0;
		scanf("%d%d%d", &firstNode, &secondNode, &value);
		addIntMatrixMutualConnection(matrix, firstNode, secondNode, value);
	}

	int *prev = new int[number  + 1];
	memset(prev, 0, (number + 1) * sizeof(int));

	int *dist = djikstra(matrix, prev, number, 1, true);
	cout << endl;

	for (int i = 1; i <= number; i++) 
		cout << "Minimal distance to " << i << " : " <<  dist[i] << endl;;

	delete[] prev;
	delete[] dist;
	deleteIntMatrix(matrix, number + 1);
	
	return 0;
}