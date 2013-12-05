#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 12

void swap(int* x, int* y){
 	int t=*x;
 	*x=*y;
 	*y=t;
}

void flip(int* a,int l,int x) {
	int i=0,j=l-1;
	while(i<j) {
		while(a[i]<=x) i++;
		while(a[j]>=x) j--;
		if(i<j) {
			swap(&a[i],&a[j]);
			i++,j--;
		} 	
	}
}

int A[LEN];

int main(){
	srand(time(NULL));
	for(int i=0;i<LEN;i++) {
	 	A[i]=rand();
	 	printf("%d ",A[i]);
	}	
	printf("\n");
	flip(A,LEN,A[0]);
	for(int i=0;i<LEN;i++) {
	 	printf("%d ",A[i]);
	}
	return 0;
}