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

void rev(list *&l)
{
	if (l == 0 || l->next == 0) return;
    list *k = l->next;
    rev(k);
    l->next->next = l;
    l->next = 0;
    l = k;
}

int main()
{
	list *l = 0;
	rand();
	inputrand(l);
	print(l);

	rev(l);

	printf("\n");
	print(l);
	del(l);

	getchar();
	getchar();
}