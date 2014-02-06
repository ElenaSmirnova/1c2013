#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

char str[100];
int n;

void write(int i, int sum)
{
	if(sum > n - i || sum < i - n)
		return;

	if(i == n)
	{
		printf("%s\n", str);
		return;
	}

	str[i] = 'L';
	write(i + 1, sum - 1);

	str[i] = 'R';
	write(i + 1, sum + 1);
}

int main()
{          
	printf("Print the number of levels (it must be even)\n");
	scanf("%d", &n);
    write(0, 0); 

	getchar();
	getchar();
}













