#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>

char str[1000];
int main()
{
	int state = 0;
	/*
		0 -- begin
		1 -- digits
		2 -- point
		3 -- digits after point
		4 -- exp
		5 -- plus/minus
		6 -- digits after exp
		7 -- end
		8 -- error
	*/
	scanf("%s", str);
	int n = 0;
	for (n = 0; str[n]; n++)
		if (str[n] < '0' || str[n] > '9')
			if (str[n] != 'E' && str[n] != '.' && str[n] != '+' && str[n] != '-')
			{
				state = 8;
				break;
            }
	
	if (state == 0) for (int i = 0; i <= n; i++)
		switch (state)
		{
			case 0: switch (str[i])
			{
				case 0: case '+': case '-': case 'E': case '.': state = 8; break;
				default: state = 1; break;
			} break;
			case 1: switch (str[i])
			{
				case 0: state = 7; break;
				case '+': case '-': state = 8; break;
				case '.': state = 2; break;
				case 'E': state = 4; break;
				default: break;
			} break; 
			case 2: switch (str[i])
			{
				case 0: case '+': case '-': case 'E': case '.': state = 8; break;
				default: state = 3; break;
			} break;  
			case 3: switch (str[i])
			{
				case 0: state = 7; break;
				case '+': case '-': case '.': state = 8; break;
				case 'E': state = 4; break;
				default: break;
			} break;
			case 4: switch (str[i])
			{
				case 0: case 'E': case '.': state = 8; break;
				case '+': case '-': state = 5; break;
				default: state = 6; break;				
			} break;	
			case 5: switch (str[i])
			{
				case 0: case 'E': case '.': case '-': case '+': state = 8; break;
				default: state = 6;
			} break;
			case 6: switch (str[i])
			{
				case 0: state = 7; break;
				case 'E': case '.': case '+': case '-': state = 8; break;
				default: break;
			}
			case 7: break;
			case 8: break;
		}                                 
	if (state == 7) printf("yes\n");
	else printf("no\n");

	getchar();
	getchar();

	return 0;
}