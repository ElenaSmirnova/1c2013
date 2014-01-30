#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;
int incl(string s1,string s2)    // how many s1 includes in s2?
{
    int n1 = s1.size();
    int n2 = s2.size();
    int res=0;
    for (int i=0;i!=(n2-n1+1);++i)
    {
             if (s2.substr(i, n1) == s1)
                        ++res;
    }
    return res;
}
int main()
{
    string s1;
    string s2;
    cin >>s1;
    cin >>s2;
    printf("%d",incl(s1,s2));
    return 0;
}
