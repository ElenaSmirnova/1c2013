#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

struct tree
{
	tree *left, *right;
	tree *root;
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

void insert(tree *root, tree *&t, int x)
{
  if (t == 0)
  {
    t = new tree();
    t->left = t->right = 0;
    t->data = x;
    t->cnt = 1;
	if (root) t->root = root;
	else t->root = t;
  }
  else if (t->data == x) t->cnt++;
  else if (t->data < x) insert(root, t->right, x);
  else insert(root, t->left, x);
}

int root(tree *&t)
{
  return t == NULL ? -1000000000 : t->root->data;
}
       
int main()
{
  tree *t = 0;
  insert(t, t, 0);
  insert(t, t, 1);
  insert(t, t, 0);
  insert(t, t, 1);
  insert(t, t, 2);
  printf("%d\n", root(t));

  return 0;
}