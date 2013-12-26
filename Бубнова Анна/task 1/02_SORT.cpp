#include <stdio.h>
#include <alloc.h>
int main(){
  int n=0;
  printf("Введите число элементов массива\n");
  scanf("%d",&n);
  int *a=(int *)calloc(n,sizeof(int));
  printf("И сами элементы\n");
  int i;
  for (i=0;i<n;i+=scanf("%d",&(a[i])));
#define xchg(x,y) {int _=a[(x)];a[(x)]=a[(y)];a[(y)]=_;}
  int flag=1;
  for (i=n-1;(i>0)&&(flag);i--){
    flag=0;
    for (int j=0;j<=i-1;j++)
      if (a[j]>a[j+1]){
        xchg(j,j+1);
        flag=1;
      };
  };
  for (i=0;i<n-1;i++)
    printf("%d ",a[i]);
  printf("%d\n",a[n-1]);
  free(a);
  return 0;
};