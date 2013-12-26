#include <math.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	int n;
	cin >> n;
	bool *p = new bool[n + 1];
	for (int i = 0; i <= n; i++) p[i] = true;
	int r = 0;
	for (int i = 2; i <= n; i++)
	if (p[i])
	{
		r++;
		for (int j = i; i * j <= n; j++)
			p[i * j] = false;
	}
	if (n <= 2) printf("0");
	else cout << r-1;
}
