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

int cnt[11];

void Count(list *l)
{
	if (l == 0) return;
	if (l->data < 0 || l->data >= 10) cnt[10]++;
	else cnt[l->data]++;
	Count(l->next);
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
	
	Count(l);
	for (int i = 0; i < 10; i++)
		printf("%d %d\n", i, cnt[i]);
	printf("other %d\n", cnt[10]);

	Delete(l);

	getchar();
	getchar();
}