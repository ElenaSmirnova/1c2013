#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

struct list
{   
	list *next;
	int data;
};

list *l = 0;

void inputkey (list *&l)
{
	list *c = 0;
	for (int i = 0; i < 10; i++)
	{
		int x;
        scanf("%d", &x);
		c = new list();
        c->next = l;
        c->data = x;
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

void rev(list *&l)
{
	if (l == 0 || l->next == 0) return;
    list *k = l->next;
    rev(k);
    l->next->next = l;
    l->next = 0;
    l = k;
}

void merge(list *&l1, list *&l2, list *&l)
{
	if(l1 == 0 && l2 == 0)
		return;
	
	list *c = 0;
	c = new list();

	if(l1 == 0)
	{
		c->data = l2->data;
		c->next = l;
		l = c;
		merge(l1, l2->next, l);
	}

	if(l1 != 0 && l2 != 0)
	{
		if(l2->data <= l1->data)
		{
			c->data = l2->data;
			c->next = l;
			l = c;
			merge(l1, l2->next, l);
		}
		if(l2->data > l1->data)
		{
			c->data = l1->data;
			c->next = l;
			l = c;
			merge(l1->next, l2, l);
		}
	}

	if(l2 == 0)
	{
		c->data = l1->data;
		c->next = l;
		l = c;
		merge(l1->next, l2, l);
	}
}

int main()
{
	list *l1 = 0;
	list *l2 = 0;
	printf("Print the first sorted list\n");
	inputkey(l1);
	rev(l1);
	
	printf("Print the second sorted list\n");
	inputkey(l2);
	rev(l2);
	
	merge(l1, l2, l);
	rev(l);

	printf("\n");

	print(l);

	del(l);
	del(l1);
	del(l2);

	getchar();
	getchar();
}