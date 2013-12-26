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
void ins(sp *&a, sp *b)
{
	if (a == 0 || a->dat > b->dat) b->next = a, a = b;
	else ins(a->next, b);
}

void insrt(sp *&s)
{
	sp *m = 0;
	sp *next;
	for (; s != 0; s = next)
	{
		next = s->next;
		ins(m, s);
	}
	s = m;
}
int main()
{
	sp *s = 0;
	create(s);
	insrt(s);


	for (sp *i = s; s != 0; s = s->next)
	{
		printf("%d ", s->dat); printf(" ");
	}

	getchar();
	getchar();
}
