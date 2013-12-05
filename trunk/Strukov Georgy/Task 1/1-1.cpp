#include <stdio.h>
#define ll long long
int n;
/*
ll fib(int x){
	return (x<2)?1:fib(x-1)+fib(x-2);
}
*/
ll fib(int x) {
 	int f1=1;
 	int f2=1;
 	int f3;
 	if(x<2) {
 		return f1;
 	}
 	while(x>=2) {
 	 	f3=f1+f2;
 	 	f1=f2;
 	 	f2=f3;
 	 	x--;
 	}
 	return f3;
}
int main(){
	scanf("%d",&n);
	printf("%I64d",fib(n));
	return 0;
}