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

void deleteElement(tree *&t, int x)
{
	if (t == 0) return;
	else if (t->data == x)
		if (t->cnt == 1)
			if (t->right == 0) t = t->left;
			else
			{
				tree *t2;
				for (t2 = t->right; t2->left; t2 = t2->left);
				t2->left = t->left;
				t = t->right;
			}
		else t->cnt--;
	else if (t->data < x) deleteElement(t->right, x);
	else deleteElement(t->left, x);
}

int main()
{
	tree *t = 0;
	insert(t, 0);
	insert(t, 1);
	insert(t, 0);
	insert(t, 1);
	insert(t, 2);

	deleteElement(t, 0);
	go(t, write);

	return 0;
}