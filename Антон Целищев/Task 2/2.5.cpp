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

int mp(list *&l)
{
	int min = l->data;
	int minpos = 0;
	int i = 0;
	while(l != 0)
	{
		if(l->data < min)
		{
			min = l->data;
			minpos = i;
		}
		i++;
		l = l->next;
	}
	return(minpos);
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

	printf("\n");
	printf("%d", mp(l));

	del(c);

	getchar();
	getchar();
}