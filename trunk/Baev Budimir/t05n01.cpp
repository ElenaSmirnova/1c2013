#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <time.h>
using namespace std;

const int N = 100;
int mass[N][N];

bool gamil(int m[N][N],int t)
{
    if (t==2)
        return false;
    if (t==1)
        return true;

    bool cans[t][t];
    for (int i=0;i<=t-1;++i)
        for (int j=0;j<=t-1;++j)
        cans[j][i]=cans[i][j]=true;

    bool incl[t];         //shows if vertex belongs to our cycle
    for (int i=0;i<=t-1;++i)
        if (i==0)
            incl[i]=true;
        else incl[i]=false;
    int s=0;
    int q[t];
    q[0]=0;

    int epsilon=0;
    bool breaqk=true;
    while(breaqk)
    {
        epsilon=0;
    for (int i=0;i<=t-1;++i)
    {

        if ((incl[i]==false) and (cans[i][q[s]]==true) and (mass[i][q[s]]==1))
        {
        ++s;
        q[s]=i;
        epsilon=1;
        incl[i]=true;
        if ((s==t-1) and (mass[i][0]==1))
            {
            return true;
            breaqk=false;
            }
        break;
        }
    }
    if (epsilon==0)
    {
        --s;
        if (s==-1)
        {
            return false;
            breaqk=false;
        }

        for (int j=0;j<=t-1;++j)
        cans[q[s+1]][j]=cans[j][q[s+1]]=true;
        cans[q[s]][q[s+1]]=cans[q[s+1]][q[s]]=false;
        incl[q[s+1]]=false;
    }
    }

}


main()
{
for (int i=0;i<=N-1;++i)
    for(int j=0;j<=N-1;++j)
        mass[i][j]=0;

mass[1][2]=mass[2][1]=1;
mass[2][3]=mass[3][2]=1;
mass[3][1]=mass[1][3]=1;
mass[4][5]=mass[5][4]=1;
mass[6][7]=mass[7][6]=1;
mass[7][8]=mass[8][7]=1;
mass[8][9]=mass[9][8]=1;
mass[9][10]=mass[10][9]=1;
mass[10][6]=mass[6][10]=1;
mass[7][3]=mass[3][7]=1;
mass[6][5]=mass[5][6]=1;
mass[0][1]=mass[1][0]=1;
mass[4][0]=mass[0][4]=1;


printf("Vasya,  ");
printf("%d",gamil(mass,11));

    return 0;
    return 0;
}
