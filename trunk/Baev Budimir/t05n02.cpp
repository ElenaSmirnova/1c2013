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


int component (int m[N][N],int t)
{
    int s=0;
    for (int j=0;j<=t-1;++j)
    {
        if (vq[j]==false)
        {
          vq[j]=true;
          bool h[t];
          for (int i=0;i<=t-1;++i)
          h[i]=false;
          h[j]=true;

          int k;

          int e=1;
          while (e==1)
          {
              e=0;
              for(k=j;k<=t-1;++k)
          {
              if (h[k]==true)
            for (int k1=j;k1<=t-1;++k1)
            {
                if ((h[k1]==false) and (m[k1][k]==1))
                {
                h[k1]=true;
                vq[k1]=true;
                e=1;
                }
            }
          }
          }
          ++s;
        }
    }
    return s;
}





main()
{
    for (int i=0;i<=N-1;++i)
        for(int j=0;j<=N-1;++j)
        mass[i][j]=0;
for (int j=0;j<=N-1;++j)
vq[j]=false;


mass[1][2]=mass[2][1]=1;
mass[2][3]=mass[3][2]=1;
mass[3][1]=mass[1][3]=1;
mass[4][5]=mass[5][4]=1;
mass[6][7]=mass[7][6]=1;
mass[7][8]=mass[8][7]=1;
mass[8][9]=mass[9][8]=1;
mass[9][10]=mass[10][9]=1;
mass[10][6]=mass[6][10]=1;


printf("Vasya,  ");
printf("%d",component(mass,11));

return 0;
return 0;
}
