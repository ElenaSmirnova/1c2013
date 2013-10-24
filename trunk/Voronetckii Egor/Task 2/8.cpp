#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

struct list
{
	list *next;
	int data;
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

void Delete(list *l)
{
	if (l == 0) return;
	Delete(l->next);
	delete l;
}

void Merge(list *&l, list *a, list *b)
{
	if (a == 0) l = b;
	else if (b == 0) l = a;
	else if (a->data < b->data)
	{
		l = a;
		Merge(l->next, a->next, b);
	}
	else
	{
		l = b;
		Merge(l->next, a, b->next);
	}
}

int main()
{
	list *l = 0;
	list *m = 0;
	// last element is -1
	input(l);
	input(m);

	Merge(l, l, m);

	for (list *i = l; i; i = i->next)
		printf("%d ", i->data);

	Delete(l);

	getchar();
	getchar();
}