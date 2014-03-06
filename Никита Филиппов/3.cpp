#include "stdafx.h"
#include <iostream>
using namespace std;
 int maxk=1000;
int x;
int n=0;
	int mas[6][6]=
	{/*таблица смежности 6*6  */
		{0,1,1,1,1,0},
		{1,0,1,0,0,1},
		{1,1,0,0,1,1},
		{1,0,0,0,1,1},
		{1,0,0,1,0,1},
		{0,1,0,1,1,0},
	};
	int W[6][6]=
	{/*веса */
		{maxk,5,3,8,2,maxk},
		{5,maxk,6,maxk,maxk,4},
		{3,6,maxk,maxk,maxk,maxk},
		{8,maxk,maxk,maxk,1,7},
		{2,maxk,maxk,1,maxk,2},
		{maxk,4,maxk,7,2,maxk},
	};


int  main()
{
	for (int k = 0;k<6;k++)
		for (int i = 0;i<6;i++)
			for (int j = 0;j<6;j++)
      W[i][j] =min( W[i][j], (W[i][k] + W[k][j]));

	for (int i = 0; i < 6; i++)
{
for (int j = 0; j < 6; j++)
{
printf("%d ", W[i][j]);
}
printf("\n");
}
	return 0;
}