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

int ElementByNumber(list *l, int n)
{
	if (n < 0) return 0;
	for (int i = 0; i < n; i++)
	{
		if (l == 0) return 0;
		l = l->next;
	}
	return l ? l->data : 0;
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
	
	int n;
	scanf("%d", &n);
	printf("%d", ElementByNumber(l, n));

	Delete(l);

	getchar();
	getchar();
}