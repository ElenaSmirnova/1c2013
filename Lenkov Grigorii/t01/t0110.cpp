#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;



void qs(int* s, int first, int last)
{
	int i = first, j = last, x = s[(first + last) / 2];

	do {
		while (s[i] < x) i++;
		while (s[j] > x) j--;

		if (i <= j) {
			if (i < j) swap(s[i], s[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		qs(s, i, last);
	if (first < j)
		qs(s, first, j);
}
int main()
{
	
	int n;
	int *a;
	cin>>n;
	a = new int[n];
	for (int i = 0; i < n; i++) cin>>a[i];
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
		printf(" ");
	}
	printf("                                  ");
	qs(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
		printf(" ");
	} getchar(); getchar();
}
