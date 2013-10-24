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
	if (x != 1)
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

void DeletePos(list *&l)
{
	if (l == 0) return;
	if (l->data > 0) l = l->next, DeletePos(l);
	else DeletePos(l->next);
}

int main()
{
	list *l = 0;
	// last element is 1
	input(l);

	DeletePos(l);

	for (list *i = l; i; i = i->next)
		printf("%d ", i->data);

	Delete(l);

	getchar();
	getchar();
}