#include <stdio.h>
#include <time.h>
long int f(int x){
  if (x<=1)
    return x; else
      return f(x-1)+f(x-2);
};
int main(){
  int n;
  scanf("%d",&n);
  clock_t time_[3]={clock(),0,0};
  long int fn=f(n);
  time_[1]=clock();
  long int fm[3]={0,1,1};
  for (int i=2;i<=n;i++){
    fm[i%3]=fm[(i-1)%3]+fm[(i-2)%3];
  };
  time_[2]=clock();
  printf("Recursive f(%d)=%ld, %.3fs\n",n,fn,(double)(time_[1]-time_[0])/CLK_TCK);
  printf("Strict    f(%d)=%ld, %.3fs\n",n,fm[n%3],(double)(time_[2]-time_[1])/CLK_TCK);
  return 0;
};