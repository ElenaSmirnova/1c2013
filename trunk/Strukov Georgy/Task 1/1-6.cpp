#include <stdio.h>
#define MAXN 1<<20
int n,primes;
bool notPrime[MAXN];
int main(){
	scanf("%d",&n);
 	for(int i=2;i<n;i++) {
 	 	if(!notPrime[i]) {
 	 	 	primes++;
 	 	 	for(int j=2*i;j<n;j+=i) {
 	 	 	 	notPrime[j]=true;
 	 	 	}
 	 	}
 	}
 	printf("%d",primes);
 	return 0;
}