#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

void SBF(int a[100], int n)
{
	int k = 1;
	int c = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] <= c)
		{
			swap(a[k], a[i]);
			k++;
		}
	swap(a[k-1], a[0]);
}

int main()
{
	rand();
	int n;
	printf("Print the length of the array\n");
	scanf("%d", &n);

	int a[100];
	for (int i = 0; i < n; i++)
        a[i] = rand();
    for (int i = 0; i < n; i++)
		printf ("%d ", a[i]);
	printf("\n");

	SBF(a, n);

	for (int i = 0; i < n; i++)
		printf ("%d ", a[i]);

	getchar();
	getchar();
}





