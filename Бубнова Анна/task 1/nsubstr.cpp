#include <stdio.h>
#include <string.h>
#define MAX_L 80
int main(){
  char s[MAX_L],s1[MAX_L];
  fgets(s,MAX_L,stdin);
  fgets(s1,MAX_L,stdin);
  //разборки с Кнуто-Моррисо-Праттом (, хотя исходник лежит тут
  //http://algolist.manual.ru/search/esearch/kmp.php
  int l=strlen(s),l1=strlen(s1),n=0;
  if (s1[l1-1]=='\n')
    s1[l1--]=0;
  for (int i=0;i<l-l1;i++){
    int flag=1;
    for (int j=0;j<l1;j++)
      if (s[i+j]!=s1[j]){
        flag=0;
        break;
      };
    n+=flag;
  };
  printf("%d\n",n);
  return 0;
};