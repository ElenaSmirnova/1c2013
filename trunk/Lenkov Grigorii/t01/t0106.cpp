#include <math.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	string s, s1;
	int k = 0;
	cin >> s;
	cin >> s1;

	for (int i = 0; i<s.size() ; i++)
	if (s.substr(i, s1.size()) == s1) k++;
		printf("%d", k);
	getchar();
	return 0;
}