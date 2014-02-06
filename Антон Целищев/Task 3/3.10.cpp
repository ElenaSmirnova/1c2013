#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

char stack[100];
char s[100];

int n = 0;
int i = 0;
bool q = true;

bool empty(char stack[100])
{
	return(n == 0);
}

int main()
{
	printf("Print the array of brackets\n");
	scanf("%s", s);

	for (int i = 0; s[i]; i++)
	{
		if(s[i] == '(')
		{
			stack[n] = '(';
			n++;
		}
		if(s[i] == ')')
		{
			if(empty(stack))
			{
				printf("%d\n", i);
				q = false;
				break;
			}
			n--;
		}
	}
	if(q)
	{
		if(empty(stack))
			printf("it's ok");
		else 
			printf("too many opening brackets");
	}
	getchar();
	getchar();
}