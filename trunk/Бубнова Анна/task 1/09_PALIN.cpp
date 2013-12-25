#include <stdio.h>
#include <string.h>
#define MAX_L 80
int main(){
  char s[MAX_L];
  fgets(s,MAX_L,stdin);
  int i,j;
  for (i=0,j=strlen(s)-2;(i<j)&&(s[i]==s[j]);i++,j--);
  printf((s[i]==s[j])?"Yes\n":"No\n");
  return 0;
};