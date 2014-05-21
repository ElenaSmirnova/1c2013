#include "stdafx.h"
#include "dfa.h"
#include <fstream>
#include <iostream>

using namespace std;

int move(char ch, int state, int **masState, char *masCh)
{
	int numCh = sizeof(masCh) - 2; 
	for (int i = 0; i <= numCh; i++)
		if (ch == masCh[i])
		{
			numCh = i;
			break;
		}
	return masState[numCh][state];
}

void printComment(char fileName[])
{
	ifstream fState("state.txt");
	if (!fState)
	{
		cout << "Can't open file state" << endl;
		return;
	}
	int h = 0;
	int w = 0;
	fState >> h >> w;
	char *masCh = new char[h];
	int **masState = new int*[h];
	for (int i = 0; i < h; i++)
		masState[i] = new int[w];

	for (int i = 0; i < h; i++)
	{
		fState >> masCh[i];
		for (int j = 0; j < w; j++)
			fState >> masState[i][j];
	}
	fState.close();

	ifstream fin(fileName);
	if (!fin)
	{
		cout << "Can't open file " << fileName << endl;
		return;
	}
	char ch = 0;
	int i = 0;
	char comment[100] = {0};
	fin >> ch;
	int state = 0;
	int stateBefore = 0;
	while (!fin.eof())
	{
		stateBefore = state;
		fin.get(ch);
		state = move(ch, state, masState, masCh);
		if (state == 2 && (stateBefore == 1 || stateBefore == 0))
		{
			comment[i++] = '/';
			comment[i++] = '*';
		}
        else if (state == 2 || state == 3)
			comment[i++] = ch;
        else if(state == 0 && stateBefore == 3)
		{
			comment[i] = '/';
			i = 0;
			cout << comment << endl;
		}
	}
	fin.close();
}