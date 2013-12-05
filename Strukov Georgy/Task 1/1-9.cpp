#include <stdio.h>
#define MAXN 10000

void swap(int* x, int *y) {
 	int t=*x;
 	*x=*y;
 	*y=t;
}

void qSort(int* a, int l, int r) {
 	int i=l;
 	int j=r;
 	int x=a[(l+r)/2];
 	while(i<=j) {
 		while(a[i]<x) i++;
	 	while(a[j]>x) j--;
	 	if(i<=j) {
	 	 	swap(&a[i],&a[j]);
	 	 	i++,j--;
	 	}
	}
	if(l<j){
		qSort(a,l,j);
	}
	if(i<r){
	 	qSort(a,i,r);
	}
}

int n,A[MAXN];

int main(){
 	scanf("%d",&n);
 	for(int i=0;i<n;i++) {
 		scanf("%d",&A[i]);
 	}
 	qSort(A,0,n-1);
 	for(int i=0;i<n;i++) {
 		printf("%d ",A[i]);
 	}
 	return 0;
}