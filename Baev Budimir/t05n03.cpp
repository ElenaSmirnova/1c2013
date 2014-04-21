#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;




const int N = 100;
int mass[N][N];
bool vq[N];

int distance (int x,int y,bool vq[N]) //in graph mass[N][N] with vertixes from vq distance between x and y
{
    int h1[N];
    if (x==y)
    return 0;
    for (int i=0;i<=N-1;++i)
    if (vq[i]==true)
    if (mass[i][x]!=0)
    {
        bool h[N];
    for (int i=0;i<=N-1;++i)
        h[i]=vq[i];
    h[i]=false;
    h1[i]=mass[i][x]+ distance(i,y,h);
    }
    else h1[i]=10000000;
    int s=10000000;
    for (int j=0;j<=N-1;++j)
    if ((vq[j]==true) and (h1[j]<s))
        s=h1[j];
    return s;
}



main()
{
    for (int i=0;i<=N-1;++i)
        for(int j=0;j<=N-1;++j)
        mass[i][j]=0;
for (int j=0;j<=N-1;++j)
if (j<=10)
    vq[j]=true;
    else vq[j]=false;


mass[1][2]=mass[2][1]=12;
mass[2][3]=mass[3][2]=12;
mass[3][1]=mass[1][3]=1;
mass[4][5]=mass[5][4]=1;
mass[4][1]=mass[1][4]=3;
mass[4][6]=mass[6][4]=1;
mass[6][7]=mass[7][6]=1;
mass[7][8]=mass[8][7]=1;
mass[8][9]=mass[9][8]=1;
mass[9][10]=mass[10][9]=1;
mass[10][6]=mass[6][10]=1;


printf("%d",distance(2,9,vq));
}
