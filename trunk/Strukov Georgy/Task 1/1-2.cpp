#include <stdio.h>
#define MAXL 10000
#define MAXN 1000

int A[MAXL],B[MAXL],n;

void swap(int* x, int* y){
 	int t = *x;
 	*x = *y;
 	*y = t;
}

void bubbleSort(int* a, int l) {
	for(int i=0;i<l;i++) {
	 	for(int j=1;j<l;j++) {
	 	 	if(a[j]<a[j-1]) {
	 	 	    swap(&a[j],&a[j-1]);
	 	 	}	
	 	}
	}
}

bool countSort(int* a, int l){
    int c[MAXN+1] = {0};
    for(int i=0;i<l;i++) {
    	if ((a[i]>=0) && (a[i]<=MAXN)) {
    		c[a[i]]++;
    	} else {
    		return 0;
    	}	
    }
    int t=0;
    for(int i=0;i<=MAXN;i++) {
     	while(c[i]>0) {
     	 	a[t]=i;
     	 	t++;
     	 	c[i]--;
     	}
    }
    return 1;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&A[i]);
		B[i]=A[i];
	}
	bubbleSort(A,n);
	for(int i=0;i<n;i++) {
	 	printf("%d ",A[i]);
	}
	printf("\n");
	if(countSort(B,n)) {
		for(int i=0;i<n;i++) {
	 		printf("%d ",B[i]);
		}
		printf("\n");
	} else {
	 	printf("Elements in array are out of range\n");
	}
	return 0;
}
