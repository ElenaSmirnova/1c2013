#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;

struct sp
{
	sp *next;
	int dat;
	bool fhtagn;
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
bool ct(sp *s)
{
	if (s == 0) return false;
	if (s->fhtagn) return true;
	s->fhtagn = true;
	return ct(s->next);
}

sp a[1000000];

int main()
{

	int n;
	for (n = 0;; n++)
	{
		int x, y;
		cin>>x;
		if (x == 0) break;
		cin>>y;
		a[n].dat = x, a[n].next = a + y, a[n].fhtagn = false;
	}
	for (int i = 0; i < n; i++)
	if (a[i].next < a || a[i].next >= a + n)
		a[i].next = 0;

	if (ct(a))
		printf("yes\n");
	else
		printf("no\n");

}
