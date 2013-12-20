#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

struct tree
{
	tree *left, *right;
	int data, cnt; // cnt is number of copies of data
};

void write(tree *t)
{
	printf("%d(%d) ", t->data, t->cnt);
}

void go(tree *t, void f(tree *))
{
	if (t)
	{
		go(t->left, f);
		f(t);
		go(t->right, f);
	}
}
       
int main()
{
	tree a, b, c;
	a.data = 1, b.data = 2, c.data = 3;
	a.cnt = 2, b.cnt = 1, c.cnt = 1;
	a.left = 0, a.right = &b;
	b.left = 0, b.right = &c;
	c.left = 0, c.right = 0;

	go(&a, write);

	return 0;
}