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

int Lenght(list *l)
{
	int size = 0;
	while (l != 0) l = l->next, size++;
	return size;
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
	// last element is before -1
	input(l);
	
	printf("%d", Lenght(l));

	Delete(l);

	getchar();
	getchar();
}