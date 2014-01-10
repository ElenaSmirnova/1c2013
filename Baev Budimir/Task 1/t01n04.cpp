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


int chee(char *s)
{
    int n=strlen(s);
    int j=0;
    for (int i=1;i<=n;++i)
    {
        if (s[i] == '(')
            ++j;
        if (s[i] == ')')
            --j;

        if (j<0)
        return 0;
    }

    if (j!=0)
        return 0;
    else return 1;
}






int main()
{
 int m,inde;
 cin >> m;
 char s[m];
 printf("Enter all elements of your string\n");
 for (inde=1;inde<=m;++inde)
 {
  cin>>s[inde];
 }
 printf("%d",chee(s));

}
