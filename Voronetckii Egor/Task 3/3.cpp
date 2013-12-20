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

void insert(tree *&t, int x)
{
	if (t == 0)
	{
		t = new tree();
		t->left = t->right = 0;
		t->data = x;
		t->cnt = 1;
	}
	else if (t->data == x) t->cnt++;
	else if (t->data < x) insert(t->right, x);
	else insert(t->left, x);
}

void insertSubtree(tree *&t, tree *nt)
{
	if (t == 0) t = nt;
	else if (t->data == nt->data)
	{
		t->cnt += nt->cnt;
		insertSubtree(t->left, nt->left);
		insertSubtree(t->right, nt->right);
	}
	else if (t->data < nt->data) insertSubtree(t->right, nt);
	else insertSubtree(t->left, nt);
}
       
int main()
{
	tree *t = 0;
	insert(t, 0);
	insert(t, 1);
	insert(t, 0);
	insert(t, 1);
	insert(t, 2);

	tree *t2 = 0;
	insert(t2, 0);
	insert(t2, 4);

	insertSubtree(t, t2);

	go(t, write);

	return 0;
}