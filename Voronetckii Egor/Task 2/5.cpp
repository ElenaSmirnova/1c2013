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

struct el
{
	int pos;
	int x;
	el(int p, int a): pos(p), x(a) {}
};

el MinPos(list *l)
{
	if (l == 0) return el(-1, 0);
	el res = MinPos(l->next);
	if (res.pos == -1 || res.x > l->data)
		return el(0, l->data);
	else
		return el(res.pos + 1, res.x);
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
	
	printf("%d", MinPos(l).pos);

	Delete(l);

	getchar();
	getchar();
}