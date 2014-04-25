#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

const int n = 5;
 
int c[n] ;   // ����� ����, �� ������� ���������� �������
int path[n]; // ������ ���������� ������
int v0 = 2;    // ��������� �������
 
//������� ���������
int a[n][n] =
{
    0,1,1,0,0,
    1,0,0,1,0,
    1,0,0,1,0,
    0,1,1,0,1,
    0,0,1,1,0
};
 
void print(void)
{
	int p;
        for ( p = 0 ; p < n; p++)
     cout << path[p] + 1 << "\t";
     cout << path[0] + 1 ;
         cout<<"\n" ;
}
 
//������������ ���������� ������������ �����
int gamilton ( int k)
{
	int v,q1=0;
    for(v = 0; v < n && !q1; v++)
    {
      if(a[v][path[k-1]]||a[path[k-1]][v])
      {
		if (k == n &&  v == v0 ) 
			q1 = 1;
		else if (c[v] == -1) 
			{
			  c[v] = k ; path[k]=v; 
			  q1=gamilton (k+1) ;
			  if (!q1) c[v] = -1;  
			} 
		else continue;
		} 
    }   
	
	return q1;
}
 
int main()
{
	setlocale(LC_ALL, "Russian");

	int j = 0;
    cout << "����������� ����:" << endl;
        for(j = 0; j < n; j++) c[j] = -1;
        path[0] = v0 ;
          c[v0] = v0;

    if (gamilton(1)) 
		print(); 
	else 
		cout<<"��� �������\n";

    return 0;
}