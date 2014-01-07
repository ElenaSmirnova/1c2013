#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

#define N 100000

void bubs (int *a,int n)   //bubble sort
{
    int i,j,gurb;
    for (i=0;i<=n;++i)
    for (j=1;j<=n;++j)
    {
        if (a[j]>a[j+1])
        {
            gurb = a[j];
            a[j]=a[j+1];
            a[j+1]=gurb;
        }
    }
}



void countsort(int *a,int n,int mav,int miv)  // counting sort
{
 int bqw [N+1] ;
 int i,index;
 int j;
 index=1;
 for (i=miv;i<=mav;++i)
 {
     bqw[i]=0;
 }
 for (i=1;i<=n;++i)
 {
     bqw[a[i]]=bqw[a[i]]+1;
 }
     for (j=0;j<=N;++j)
     {
         for (i=1;i<=bqw[j];++i)
         {
             a[index]=j;
             ++index;
         }
     }
}



int main()
{
    printf("Enter number of elements : ");
    int lenga;
    cin >> lenga;
    int Example[lenga];
    int i;
    printf("Write all elements of massve in line: \n");
    for (i=1;i<=lenga;++i)
    {
        cin >> Example[i];
    }


//bubs(Example,lenga);
countsort(Example,lenga,N,0);
int s;
for (s=1;s<=lenga;++s)
{
    printf("   ");
    printf("%d",Example[s]);
}


return 0;
}
