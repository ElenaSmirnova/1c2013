#include <stdio.h>
#include <math.h>
#define MAX_L 80
int main(){
  char s[MAX_L];
  fgets(s,MAX_L,stdin);
  double a,res;
  int n;
  sscanf(s,"%lf %d",&a,&n);
  double res_expln=(a==0)?0:((a<0)?(-1):1)*exp(log(fabs(a))*n);
  for (res=1.0;n;(a*=a),(n>>=1))
    if (n&1)
      res*=a;
  printf("%lf %lf\n",res,res_expln);
  return 0;
};