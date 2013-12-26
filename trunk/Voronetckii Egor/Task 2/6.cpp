#include <cstdio>
#include <cmath>
#include <ctime>
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

int *cnt;

void Count(list *l)
{
        if (l == 0) return;
        cnt[l->data]++;
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
        cnt = new int[(int)1e6];
        cnt += (int)5e5;
        for (int i = -5e5; i < 5e5; i++) cnt[i] = 0;
        printf("Input elements from -5e5 to 5e5 - 1 without -1, last element is -1\n");
        list *l = 0;
        input(l);
       
        Count(l);
        for (int i = -5e5; i < 5e5; i++)
                if (cnt[i]) printf("%d was %d times\n", i, cnt[i]);

        Delete(l);
        delete[] (cnt - (int)5e5);

        getchar();
        getchar();
}
