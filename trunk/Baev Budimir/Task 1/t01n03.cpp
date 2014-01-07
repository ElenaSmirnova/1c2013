#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void crsort(int *a,int n)
{
   int gurb,i,j;
   i=1;
   j=2;
   for (j=2;j<=n;++j)
   {
       if (a[i]>a[j])
       {
          if (j!=i+1)
          {
                gurb = a[i];
                a[i]=a[j];
                a[j]=gurb;
                i=i+1;
          }
          if (j>i+1)
          {
              gurb =a[i];
              a[i]=a[j];
              a[j]=a[i+1];
              a[i+1]=gurb;
              i=i+1;
          }
       }
   }
}

int main()
{
int n;
cin >> n;
int a[n];
for (int i=1;i<=n;++i)
{
    a[i]=rand() % 10;
}
for (int i=1;i<=n;++i)
{
    printf("%d",a[i]);
    printf("  ");
}
printf("\n");
crsort(a,n);
for (int i=1;i<=n;++i)
{
    printf("%d",a[i]);
    printf("  ");
}
    return 0;
}
