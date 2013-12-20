#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

char Stack[1000000];
int n = 0;

char str[1000000];
char str2[1000000];

int main()
{            
	scanf("%s", str);
	int size = 0, size2 = 0;
	for (int i = 0; str[i]; i++) size++;
	for (int i = 0; i < size / 2; i++) Stack[n++] = str[i];
	while (n) str2[size2++] = Stack[--n];
	for (int i = size / 2; i < size; i++) Stack[n++] = str[i];
	while (n) str2[size2++] = Stack[--n];
	printf("%s\n", str2);

	return 0;
}