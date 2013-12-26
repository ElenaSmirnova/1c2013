#include <math.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	int n; int k;
	cin >> n;
	cin >> k;
	double p = n;
	while (k-1 > 0)
	{
		p *= n;
		k--;
	}
	cout << p;
}
