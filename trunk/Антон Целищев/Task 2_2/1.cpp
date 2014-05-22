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

char s[100];
bool dig(char c)
{
	return(c<='9') && (c>='0');
}
int stage=0;
/*

*/

bool realnum(char s[100])
{
	for(int w=0; s[w]; w++)
	{
		switch (stage)
		{
		case 0: if(!dig(s[w])) {return false; break;}
				if(dig(s[w])) stage=1;
				break;
		
		case 1: if(dig(s[w])) stage=1;
				if(s[w]=='.') stage=2;
				if(s[w]=='E') stage=4;
				if(!(dig(s[w])) && !(s[w]=='.') && !(s[w]=='E')) {return false; break;};
				break;
		
		case 2: if(dig(s[w])) stage=3;
				if(!dig(s[w])) {return false; break;};
				break;

		case 3: if(dig(s[w])) stage=3;
				if(s[w]=='E') stage=4;
				if(!(dig(s[w])) && !(s[w]=='E')) {return false; break;};
				break;
		
		case 4: if(dig(s[w])) stage=6;
				if((s[w]=='+')||(s[w]=='-')) stage=5;
				if(!(dig(s[w])) && !((s[w]=='+')||(s[w]=='-'))) {return false; break;};
				break;

		case 5: if(dig(s[w])) stage=6;
				if(!(dig(s[w]))) {return false; break;};
				break;

		case 6: if(dig(s[w])) stage=6;
				if(!(dig(s[w]))) {return false; break;};
				break;
		}
	}
	if((stage==0)||(stage==2)||(stage==4)) return false;
};
int main()
{
	scanf("%s", s);
	if(realnum(s)) printf("yes\n");
	else printf("no\n");

	getchar();
	getchar();
}