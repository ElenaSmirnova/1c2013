#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;



int main()
{
	int *a;
	int n;
	rand();
	cin>>n;
	
	a = new int[n];

	for (int i = 0; i < n; i++)
		a[i] = rand();
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	int b = 0;
	int i = 0, j = n - 1;
	while (true)
	{
		while (a[i] < a[b] && i < n) i++;
		while (a[j] > a[b] && j >= 0) j--;
		if (i < j)
		{
			swap(a[i], a[j]);
			if (b == i) b = j;
			else if (b == j) b = i;
		}
		else break;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	cin >> n;
}