#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

char Stack[1000000]; // This is stack
int n = 0;

char str[1000000];

int main()
{            
        scanf("%s", str);
        for (int i = 0; str[i]; i++)
        {
                if (str[i] == '(') str[n++] = '(';
                else if (str[i] == ')')
                        if (n == 0 || str[--n] != '(')
                        {
                                printf("false, first position is %d\n", i);
                                return 0;
                        }
        }
        if (n == 0) printf("true\n");
        else printf("false\n");

        return 0;
}

