#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

int fibrec(int n)
{
if ((n==0) || (n==1)) return n;
else return(fibrec(n-1)+fibrec(n-2));
}


int fibint(int n)
{
       int a[n+1];
       a[0]=0;
       a[1]=1;
       for (int i=2;i<=n;i++)
       a[i]=a[i-1]+a[i-2];

       int res = a[n];
       delete[] a;
       return res;
}



int main ()
{
int n;
cin>>n;
printf("%d\n",fibrec(n));
printf("%d",fibint(n));

return 0;
}
