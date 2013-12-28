#include <math.h>
#include <time.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool Pal(string s)
{
	int l = s.size();
	for (int i = 0; 2 * i < l; i ++)
		if(s[i] != s[l - i - 1]) return(false);
	return (true);
}

int main()
{
	string s;
	printf("Print the string\n");
	cin >> s;
	if (Pal(s)) 
		printf("YES");
	else 
		printf("NO");

	getchar();
	getchar();
}









