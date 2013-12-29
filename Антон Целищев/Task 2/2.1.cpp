#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

struct list
{   
	list *next;
	int data;
};

void inputrand (list *&l)
{
	list *c = 0;
	for (int i = 0; i < 10; i++)
	{
		int x;
        x = rand();
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

int EBN (list *&l, int n)
{
	for (int i = 0; i < n; i++)
		l = l->next;
	return (l->data);
}

int main()
{
	list *l = 0;
	rand();
	inputrand(l);
	print(l);

	list *c = 0;
	c = new list();
	c->data = 0;
	c->next = l;

	int n;
	printf("\n");
	printf("Print the number\n");
	scanf("%d", &n);

	printf("%d", EBN(l, n));

	del(c);
	getchar();
	getchar();
}