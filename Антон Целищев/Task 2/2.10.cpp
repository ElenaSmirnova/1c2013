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

void rev(list *&l)
{
	if (l == 0 || l->next == 0) return;
    list *k = l->next;
    rev(k);
    l->next->next = l;
    l->next = 0;
    l = k;
}

void ins(list *&l, int e, int f)
{
	if(l == 0) return;
	if(l->data == e)
	{
		list *c = 0;
		c = new list();
		c->next = l->next;
		c->data = f;
		l->next = c;
		ins(l->next->next, e, f);
	}
	else
		ins(l->next, e, f);
}

int main()
{
	int e, f;
	list *l = 0;
	printf("Print the list\n");
	inputkey(l);
	rev(l);

	printf("Print the number after which you want to insert something\n");
	scanf("%d", &e);

	printf("Print the number you want to insert\n");
	scanf("%d", &f);

	ins(l, e, f);
	print(l);
	del(l);

	getchar();
	getchar();
}