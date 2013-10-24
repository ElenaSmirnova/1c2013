#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

struct list
{
	list *next;
	list *prev;
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
		l->prev = 0;
		input(l->next);
		if (l->next) l->next->prev = l;
	}
}

void Insert(list *&m, list *e)
{
	if (m == 0 || m->data > e->data) e->next = m, m = e;
	else Insert(m->next, e);
}

void InsertSort(list *&l)
{
	list *m = 0;
	list *next;
	for (; l != 0; l = next)
	{
		next = l->next;
		Insert(m, l);
	}
	l = m;
}

void Delete(list *l)
{
	if (l == 0) return;
	Delete(l->next);
	delete l;
}

int main()
{
	list *l = 0;
	// last element is -1
	input(l);

	InsertSort(l);
	for (list *i = l; i; i = i->next)
		printf("%d ", i->data);

	Delete(l);

	getchar();
	getchar();
}