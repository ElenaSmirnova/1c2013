#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

int main()
{
	int j;
	int i;
	int n;
	printf("input number of elements");
	cin >> n;
	int *a = new int[n];
	for (i = 0; i < n; i++)
	{
		printf("input next element");
		cin >> a[i];
	}
	for (i = n - 1; i >= 0; i--)
	{
		for (j = n - 2; j >= 0; j--)
		{
			if (a[j]>a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		printf(" ");
	};
	cin >> n;
}