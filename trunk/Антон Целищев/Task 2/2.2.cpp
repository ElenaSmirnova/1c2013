#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

struct list
{   
	list *next;
	int data;
};

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

int leng(list *&l)
{
	int k = 0;
	while(l != 0)
	{
		k = k + 1;
		l = l->next;
	}
	return(k);
}

int main()
{
	list *l = 0;
	printf("Print the list (reversed)\n");
	inputkey(l);
	print(l);

	list *c = 0;
	c = new list();
	c->data = 0;
	c->next = l;

	printf("\n");
	printf("%d", leng(l));
	del(c);

	getchar();
	getchar();
}