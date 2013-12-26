#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;

struct sp
{
	sp *next;
	int dat;
};

void create(sp *&s)
{
	int x;
	cin>>x;
	if (x != 0)
	{
		s = new sp();
		s->next = 0;
		s->dat = x;
		create(s->next);
	}
}

void del(sp *s)
{
	if (s == 0) return;
	del(s->next);
	delete s;
}
int *k;
int main()
{
	k = new int[10000];
	for (int i = 0; i < 10000; i++) k[i] = 0;
	printf("input positive numbers < 1e4");
	sp *s = 0;
	create(s);
	for (sp*i = s; s != 0; s = s->next) (k[s->dat])++;
	for (int i = 0; i < 10000; i++)
	{
		if (k[i] != 0) { printf("%d", i);
		printf(" "); printf("%d", k[i]); printf("																	");
		}
	}
	del(s);

	getchar();
	getchar();
}
