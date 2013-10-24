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

void Insert(list *l, int x, int y)
{
	if (l == 0) return;
	if (l->data == x)
	{
		Insert(l->next, x, y);
		list *n = new list();
		n->next = l->next;
		n->data = y;
		l->next = n;
	}
	else
		Insert(l->next, x, y);
}

int main()
{
	list *l = 0;
	// last element is 1
	input(l);

	int x, y;
	scanf("%d%d", &x, &y);

	Insert(l, x, y);

	for (list *i = l; i; i = i->next)
		printf("%d ", i->data);

	Delete(l);

	getchar();
	getchar();
}