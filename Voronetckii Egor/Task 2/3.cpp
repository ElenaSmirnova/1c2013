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

void Reverse(list *&l)
{
	if (l == 0 || l->next == 0) return;
	list *end = l->next;
	Reverse(end);
	l->next->next = l;
	l->next = 0;
	l = end;
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
	
	Reverse(l);
	for (list *i = l; i != 0; i = i->next)
		printf("%d ", i->data);

	Delete(l);

	getchar();
	getchar();
}