#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int n;
char str[1000];
int leftCnt = 0;
void write(int i)
{
	if (leftCnt * 2 > n || (i - leftCnt) * 2 > n) return;
	if (i == n)
	{
		printf("%s\n", str);
	}
	else
	{                
		str[i] = 'A';
		leftCnt++;
		write(i + 1);
		leftCnt--;
		str[i] = 'B';
		write(i + 1);
	}
}

int main()
{            
	scanf("%d", &n);
	write(0); // L - left child, R - right child

	return 0;
}