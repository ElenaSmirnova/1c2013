#include <math.h>
#include <time.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int subs (string s1, string s)
{
	int res = 0;
	for (int i = 0; i < s.size() - s1.size() + 1; i++)
		if (s.substr(i, s1.size()) == s1)
			res++;
    return res;
}

int main()
{
	string s1, s;
	printf("Print the pattern\n");
	cin >> s1;
	printf("Print the string\n");
	cin >> s;

	printf("%d", subs(s1, s));

	getchar();
	getchar();
}








