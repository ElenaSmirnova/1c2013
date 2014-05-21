#include <cstdio>
#include <cassert>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
const ld eps = 1e-12;
const int inf = 1e9;
#define pb push_back
#define pob pop_back
#define i1 first
#define i2 second
#define mp make_pair

#define file "txt"
#define N 100500
           
int main()
{
    freopen("code.cpp", "r", stdin);
    printf("Input file is \"code.cpp\".\n");

    int state = 0;
    /*
    0 -- code
    1 -- begin
    2 -- comment
    3 -- end
    */
    char c;
    while (scanf("%c", &c) >= 1)
    	switch (state)
       	{
       		case 0:
       		switch (c)
       		{
       			case '*': break;
        		case '/': state = 1; break;
        		default: break;
       		}
       		break;
       		
       		case 1:
       		switch (c)
       		{
       			case '*': state = 2; printf("/*"); break;
        		case '/': break;
        		default: state = 0; break;
       		}  
       		break;
        	
        	case 2:
     		switch (c)
       		{
       			case '*': state = 3; break;
        		case '/': printf("/"); break;
       			default: printf("%c", c); break;
       		}  
       		break;
            
            case 3:
       		switch (c)
       		{
       			case '*': printf("*"); break;
        		case '/': printf("*/\n"); state = 0; break;
        		default: state = 2; printf("%c", c); break;
       		} 
            break;                         
    	}
	return 0;
}