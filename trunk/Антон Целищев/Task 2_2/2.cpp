#include <cstdio>
#include <cassert>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

char c[1000]; int i;

int main()
{
	scanf("%s", c);        
	int stage=0;
	for(int w=0; c[w]; w++)
	{
		switch (stage)
		{
			case 0: if(c[w]=='/') stage=1;
					else break;
					break;

			case 1: if(c[w]=='/') stage=1;
					if(c[w]=='*') stage=2; printf("/*");
					if(!(c[w]=='/') && !(c[w]=='*')) stage=0;             
					break;

			case 2: printf("%c", c[w]);
					if(c[w]=='*') stage=3;
					else stage=2;
					break;

			case 3: if(c[w]=='/') {printf("/\n"); stage=0;};
					if(c[w]=='*') printf("*");
					if(!(c[w]=='/') && !(c[w]=='*')) {printf("%c", c[w]); stage=2;};
					break;
		}
	};
	getchar();
	getchar();
}