#include "stdafx.h"
#include "stdlib.h"

const int maxn=10;							// max number of elements in the string

bool ans(char *s)
{
	int count = 0;
	for (int i = 0; i < maxn; i++)
	{
		if (s[i] == '(')
			count++;
		if (s[i] == ')')
			count--;
		if (count < 0)
			return false;
	}
	if (count == 0) return true;
	if (count != 0) return false;
}

int main()
{
    char s[maxn];

    scanf_s ("%s", &s);

    if (ans(s) == true)
    	printf ("good\n");
  	if (ans(s) == false)
  		printf ("bad\n");
	
	return 0;
}