// graph1.cpp: Gamiltonian.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
	int mas[5][5]=
	{
		{0,0,1,0,1},
		{0,0,1,1,1},
		{1,1,0,0,0},
		{0,1,0,0,1},
		{1,1,0,1,0},
	};
	bool visited[5]={false,false,false,false,false};
	
bool gamiltonian (int v,int start,int length)
{
	if ((length==1) && (mas[v][start]==1)) return true;
	visited[v]=true;
	for (int i=0;i<5;i++)
	{
		if (mas[i][v]=1) 
		{
			if (visited[i]==false)
			{
				if (gamiltonian(i,start,length-1)==true) return true;
			}
			
		}
	}
	visited[v]=false;
	return false;
}
int main()
{
	if (gamiltonian(0,0,5)) cout<<"Hamiltonian cycle exists"; else cout<<"Hamiltonian cycle does not exists";

}
	

	

