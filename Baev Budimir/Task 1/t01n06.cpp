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

void pripr(int n)
{
    int a[n];
    int s=0,e;
    for (int i=2;i<=n;i++)
    {
        e=1;
      if (i==2)
      {
          s=1;
          a[1]=2;
          printf("2,");
      }
      else for(int j=1;j<=s;++j)
      {
          if ((i % a[j])==0)
          {
              e=0;
              break;
          }
      }

       if ((e==1) and (i!=2))
      {
          s++;
          a[s]=i;
          printf("%d%,",i);
      }
    }
}

main()
{
pripr(100);
}
