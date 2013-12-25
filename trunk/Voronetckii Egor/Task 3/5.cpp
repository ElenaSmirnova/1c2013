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

tree *lca(tree *t, int x, int y)
{
        if (x > y) swap(x, y);
        if (t == 0) return 0;
        else if (t->data < x) return lca(t->right, x, y);
        else if (t->data > y) return lca(t->left, x, y);
        else return t;
}
       
int main()
{
        tree *t = 0;
        insert(t, 0);
        insert(t, 1);
        insert(t, 0);
        insert(t, 1);
        insert(t, 2);

        printf("%d\n", lca(t, 1, 2)->data);

        return 0;
}
