#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

struct list
{
	list *next;
	int data;
	bool was;
};

void input(list *&l)
{
	int x;
	scanf("%d", &x);
	if (x != -1)
	{
		l = new list();
		l->next = 0;
		l->data = x;
		input(l->next);
	}
}

bool CycleTest(list *l)
{
	if (l == 0) return false;
	if (l->was) return true;
	l->was = true;
	return CycleTest(l->next);
}

list a[1000000];

int main()
{
	// last element is -1, inputing pairs (data, position if next element in input order)
	int n;
	for (n = 0; ; n++)
	{
		int x, y;
		scanf("%d", &x);
		if (x == -1) break;
		scanf("%d", &y);
		a[n].data = x, a[n].next = a + y, a[n].was = false;
	}
	for (int i = 0; i < n; i++)
		if (a[i].next < a || a[i].next >= a + n)
			a[i].next = 0;

	if (CycleTest(a))
		printf("yes\n");
	else
		printf("no\n");

	getchar();
	getchar();
}