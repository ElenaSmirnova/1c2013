#include <stdio.h>
#define MAX_L 8192L
int main(){
  unsigned int erat[MAX_L];
  long int i,n;
  scanf("%ld",&n);
  if (n>MAX_L*16){
    printf("Sorry, %ld is the maximum, increase MAX_L\n",MAX_L*16);
    n=MAX_L*16-1;
  };
  for (i=0;i<=n/16;i++)
    erat[i]=0xffff;
#define isset(x) (erat[(x)/16]&(1<<((x)%16)))
#define reset(x) {erat[(x)/16]&=~(1<<((x)%16));}
  reset(0);
  reset(1);
  for (long int p=1;p<=n;p++){
    long int x=p/16;
    for (;(x<=n/16)&&!erat[x];x++);
    for (p=x*16;(p<=n)&&!isset(p);p++);
    if (p>n)
      break;
    //p is a prime
    printf("%ld ",p);
    for (x=p;x<=n;x+=p)
      reset(x);
  };
  printf("\n");
  return 0;
};