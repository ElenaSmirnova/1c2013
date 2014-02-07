#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

char Stack[100];
int n = 0;
int length  = 0;
int k = 0;

char s1[100];
char s2[100];

int main()
{   
	printf("Print a word\n");
	scanf("%s", s1);

    for (int i = 0; s1[i]; i++) 
		length++;

    for (int i = 0; i < length / 2; i++) 
		Stack[n++] = s1[i];

    while (n > 0) 
		s2[k++] = Stack[--n];

    for (int i = length / 2; i < length; i++) 
		Stack[n++] = s1[i];

    while (n > 0) 
		s2[k++] = Stack[--n];

    printf("%s", s2);

    getchar();
	getchar();
}