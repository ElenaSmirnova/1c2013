#include "stdafx.h"
#include "string"
#include "iostream"
using namespace std;

int main()
{
	string S, S1;
	cin >> S;
	cin >> S1;	
	int ans = 0;
	for (int i = 0; i < S.size(); i++)
        if (S.substr(i, S1.size()) == S1)
            ans++;
    printf ("%d\n", ans);
	return 0;
}