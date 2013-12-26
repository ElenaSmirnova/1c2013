#include <math.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	char l[9001];
	cin >> l;
	int r = 0;
	int k = 1;
	for (int r = 0; l[r]; r++);
	
		for (int i = 0; i + i < r-1; i++)
		{
			if (l[i] != l[r - i - 1]) k=0 ;
			
		}
	
	cout << k;
}
