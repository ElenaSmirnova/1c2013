#include "stdafx.h"
#include "string"
#include "iostream"
using namespace std;

int main()
{
	string S, S1;
	cin >> S;

	S1 = S;
	reverse(S1.begin(), S1.end());

	if (S == S1)
		printf ("+\n");
	else
		printf ("-\n");

	return 0;
}