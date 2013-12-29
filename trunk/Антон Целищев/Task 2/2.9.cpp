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

void delpositive(list *&l)
{
	if(l == 0) return;
	if(l->data > 0)
	{
		l = l->next;
		delpositive(l);
	}
	if(l->data <= 0)
		delpositive(l->next);
}

int main()
{
	list *l = 0;
	printf("Print the list\n");
	inputkey(l);
	rev(l);

	delpositive(l);

	printf("\n");
	print(l);

	del(l);

	getchar();
	getchar();
}