#include <stdio.h>
#define ll long long
ll a,n;
/*
int power(int x, int y) {
 	return (y?power(x,y-1)*x:1);
}
*/
ll power(ll x, ll y){
 	ll t=x;
 	ll res=1;
 	while(y>0) {
 		if(y&1) {
 			res*=t;
 		}
 		t*=t;
 		y/=2;	
 	}
 	return res;
}
int main(){
 	scanf("%I64d %I64d",&a,&n);
 	printf("%I64d",power(a,n));
 	return 0;
}