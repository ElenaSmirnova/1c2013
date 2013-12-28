#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;


void qu (int a[100], int min, int max) 
{
        int i = min;
        int j = max;
        int base = (min + max)/2;
        while (i <= j)
		{
                while(a[i] < a[base]) i++;
                while(a[j] > a[base]) j--;
                if(i<=j) 
				{
                        swap(a[i], a[j]);
                        i++;
						j--;
                }
        }
        if (min < j)
                qu (a, min, j);
        
        if (i < max)
                qu (a, i ,max);
        
}

int main()
{
	int a[100];
	int n;
	printf("Print the length of the array\n");
	scanf("%d", &n);
	printf("Print the array\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	qu(a, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	getchar();
	getchar();
}















