#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

struct tree
{
	tree *left;
	tree *right;
    int data, cnt;
};

void del(tree *&t)
{
	if((t == 0) || (t->data < 0))
		return;
	del(t->left);
	del(t->right);
	delete(t);
}

void printsymm(tree *&t)
{
	if((t == 0) || (t->data < 0)) return;
	printsymm(t->left);
	printf("%d:%d ", t->data, t->cnt);
	printsymm(t->right);
}

void ins(tree *&t, int x)
{
	if(t == 0)
	{
		t = new tree();
		t->left = 0;
		t->right = 0;
		t->data = x;
		t->cnt = 1;
		return;
	}

	if(t->data == x)
	{
		t->cnt++;
		return;
	}

	if(t->data > x)
	{
		ins(t->left, x);
		return;
	}

	if(t->data < x)
	{
		ins(t->right, x);
		return;
	}

}

void inssubtr(tree *&t, tree *&t1)
{
	if(t == 0)
	{
		t = t1;
		return;
	}

	if(t1 == 0)
		return;

	if(t->data == t1->data)
	{
		t->cnt = t->cnt + t1->cnt;
		inssubtr(t->left, t1->left);
		inssubtr(t->right, t1->right);
		return;
	}

	if(t->data < t1->data)
	{
		inssubtr(t->right, t1);
		return;
	}

	if(t->data > t1->data)
	{
		inssubtr(t->left, t1);
		return;
	}
}

int root(tree *&t, int n)
{
	if(t->data == n)
	{
		return n;
	}

	if(t->data < n)
	{
		if(t->right->data == n)
			return(t->data);
		return(root(t->right, n));
	}

	if(t->data > n)
	{
		if(t->left->data == n)
			return(t->data);
		return(root(t->left, n));
	}
}

int mincomroot(tree *&t, int x, int y)
{
	if(t->data == x)
		return(x);

	if(t->data == y)
		return(y);

	if(t->data > x && t->data < y)
		return(t->data);

	if(t->data > y)
		return(mincomroot(t->left, x, y));

	if(t->data < x)
		return(mincomroot(t->right, x, y));
}

int findelement(tree *&t, int x)
{
	if(t->data == x)
		return t->cnt;

	if(t->data < x)
		return(findelement(t->right, x));

	if(t->data > x)
		return(findelement(t->left, x));
}

void delsubtr(tree *&t, int x)
{
	if(t->data == x)
	{
		del (t);
		return;
	}

	if(t->data < x)
	{
		delsubtr(t->right, x);
		return;
	}

	if(t->data > x)
	{
		delsubtr(t->left, x);
		return;
	}
}

void delel(tree *&t, int x)
{
	if(t->data < x)
	{
		delel(t->right, x);
		return;
	}

	if(t->data > x)
	{
		delel(t->left, x);
		return;
	}

	if(t->data ==x)
	{
		if(t->cnt > 1)
		{
			t->cnt--;
			return;
		}

		if(t->cnt == 1)
		{
			tree *w = t;
			t = t->right;
			inssubtr(t, w->left);
			delete(w);
		}
	}
}

int main()
{
	tree *t = 0;
	ins(t, 8);
	ins(t, 4);
	ins(t, 0);
	ins(t, 6);
	ins(t, 5);
	ins(t, 5);
	ins(t, 7);
	ins(t, 10);
	ins(t, 14);
	ins(t, 13);

	printf("this is the original tree\n");
	printsymm(t);
	printf("\n");

	tree *t1 = 0;
	ins(t1, 14);
	ins(t1, 18);
	ins(t1, 15);
	ins(t1, 19);

	printf("this is the tree we are going to insert\n");
	printsymm(t1);
	printf("\n");

	printf("this is what we have now\n");
	inssubtr(t, t1);
	printsymm(t);
	printf("\n");

	printf("now we'll find the root of 18\n");
	printf("%d", root(t, 18));
	printf("\n");

	printf("now we'll find the common root of 13 and 19\n");
	printf("%d", mincomroot(t, 13, 19));
	printf("\n");

	printf("now we'll find the cnt of 5\n");
	printf("%d", findelement(t, 5));
	printf("\n");

	printf("now we'll delete the subtree with root 14\n");
	delsubtr(t, 14);
	printf("so this is what we have now\n");
	printsymm(t);
	printf("\n");

	printf("now we'll delete 6\n");
	delel(t, 6);
	printf("finally, that's what we have\n");
	printsymm(t);

	del(t1);
	del(t);

	getchar();
	getchar();
}