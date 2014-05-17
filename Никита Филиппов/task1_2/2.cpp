#include "stdafx.h"
#include <iostream>
using namespace std;

int x;
int n=0;
    int mas[5][5]=
	{/*таблица смежности 5*5  */
		{0,1,0,0,0},
		{1,0,1,0,0},
		{0,1,0,0,0},
		{0,0,0,0,1},
		{0,0,0,1,0},
	};
	bool flag[5]={false,false,false,false,false};


void dfs(int x)
	{
		
		flag[x]=true;
		for (int i=0;i<5;i++) 
		{
			if (mas[x][i]==1 && flag[i]==false) dfs(i);
		}
	

	}	
int main()
{
	
	
		for (int j=0;j<5;j++) 
		{
			if (flag[j]==false) {n++;dfs(j);}
		}
	cout<<n;
return 0;
	
}
	

	
