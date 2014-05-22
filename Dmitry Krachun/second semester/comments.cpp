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
                        
enum {code, begin, comment, end};

           
int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int state = code;                         
    char c;
    while (scanf("%c", &c) >= 1)
    	switch (state)
       	{
       		case code:
       		switch (c)
       		{
       			case '*': break;
        		case '/': state = begin; break;
        		default: break;
       		}
       		break;
       		
       		case begin:
       		switch (c)
       		{
       			case '*': state = comment; printf("/*"); break;
        		case '/': break;
        		default: state = code; break;
       		}  
       		break;
        	
        	case comment:
     		switch (c)
       		{
       			case '*': state = end; break;
        		case '/': printf("/"); break;
       			default: printf("%c", c); break;
       		}  
       		break;
            
            case end:
       		switch (c)
       		{
       			case '*': printf("*"); break;
        		case '/': printf("*/\n"); state = code; break;
        		default: state = comment; printf("%c", c); break;
       		} 
            break;                         
    	}
	return 0;
}