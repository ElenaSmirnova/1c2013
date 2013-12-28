#include <math.h>
#include <time.h>
#include <iostream>
#include <string.h>
using namespace std;

bool balance (char *s)
{
	int l = strlen(s);
	int b = 0;
	for (int i = 0; i < l; i++)
	{
		if (s[i] == '(') b++;
		if (s[i] == ')') b--;
		if (b < 0) return false;
	}
	return (b == 0);
}

int main()
{
	char s[100];
	printf("Print the array of brackets\n");
	scanf("%s", s);
	if (balance(s))
		printf("Right");
	else
		printf("Wrong");

	getchar();
	getchar();
}








