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

void inputrand (list *&l)
{
	list *c = 0;
	c = new(list);
	c->next = 0;
	c->prev = 0;
	int x;
	x = rand();
	c->data = x;
	l = c;
	for (int i = 0; i < 9; i++)
	{
		int x;
        x = rand();
		c = new list();
        c->next = l;
        c->data = x;
		l->prev = c;
		c->prev = 0;
		l = c;
	}
}

void print (list *&l)
{
	if(l == 0)
		return;
	printf("%d ", l->data);
	print(l->next);
}

void del(list *&l)
{
	if (l == 0) return;
    del(l->next);
    delete l;
}

void ins(list *&l)
{
	if(l->prev == 0) 
		return;
	int y = l->data;
	if(y < l->prev->data)
	{
		int k = l->data;
		l->data = l->prev->data;
		l->prev->data = k;
		ins(l->prev);
	}
}

void inssort(list *&l)
{
	while(l->next != 0)
	{
		ins(l);
		l = l->next;
	}
	ins(l);
	while(l->prev != 0)
		l = l->prev;
}

int main()
{
	list *l = 0;
	rand();
	inputrand(l);
	print(l);
	l->prev = 0;

	list *c = 0;
	c = new list();
	c->data = 0;
	c->next = l;

	printf("\n");
	inssort(l);
	print(l);

	del(c);

	getchar();
	getchar();
}