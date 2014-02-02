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
int powerq (int a,int n)
{
    if (n==0)
    {
        return 1;
    }
    else if (n>0)
    {
        return (powerq(a,n-1)*a);
    }
    else
    {
        return (powerq(a,n+1)/a);
    }
}


int main()
{
    printf("%d",powerq(2,4));
    return 0;
}
