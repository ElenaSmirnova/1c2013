#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_SZ 10
int main(){
  srand(time(NULL));
  int a[ARR_SZ];
  int i;
  for (i=0;i<ARR_SZ;i++){
    a[i]=rand();
  };
  for (i=0;i<ARR_SZ-1;i++)
    printf("%6d ",a[i]);
  printf("%6d\n",a[ARR_SZ-1]);
  int x=a[0];
  for (int l=0,r=ARR_SZ-1;l<r;){
    while (a[l]<x) l++;
    while (a[r]>x) r--;
    int temp=a[l];a[l]=a[r];a[r]=temp;
    if (a[l]>x)
      l++;
    if (a[r]<x)
      r--;
  };
  for (i=0;i<ARR_SZ-1;i++)
    printf("%6d ",a[i]);
  printf("%6d\n",a[ARR_SZ-1]);
  return 0;
};