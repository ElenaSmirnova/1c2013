#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

bool x(char *l)
{
	
	int j=0;
	for (int i = 0; l[i]; i++)
	{
		if (l[i] == '(') j++;
		else if (l[i] == ')') j--;
		else return false;
		if (j < 0) return false;

	}
	return j == 0;
}char k[9001];
int main()
{
	
	cin >> k;
	if (x(k)) printf("1");
	else printf("0");
	
}