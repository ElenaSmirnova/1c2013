#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

int a[1000];
int c[1000];
int main()
{
	int n;
	int k = 1000;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		c[a[i]]++;
	}
	
	for (int i = 0; i < k; i++)
	{
		
		for (int j = 0; j < c[i]; j++)
			cout << i << " ";
	}
	return 0;
}
