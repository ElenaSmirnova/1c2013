#include <stdio.h>
#include <alloc.h>
struct List{
  int e;
  List *n;
};
#define MAX_L 80
int main(){
  int x;
  List *l=NULL,**tail=&l;
  printf("Чтобы закончить ввод списка, введите не число\n");
  char s[MAX_L];
  while (fgets(s,MAX_L,stdin),sscanf(s,"%d",&x)>0){
    (*tail)=(List *)malloc(sizeof(List));
    (*tail)->e=x;
    (*tail)->n=NULL;
    tail=&((*tail)->n);
  };
  List *temp;
  printf("Введите номер элемента списка, начиная с 0 :)\n");
  int n,i;
  scanf("%d",&n);
  for (temp=l,i=n;(temp)&&(i);--i,temp=temp->n);
  if (temp)
    printf("%d\n",temp->e); else
      printf("Элемента с номером %d нет.\n",n);
  for (temp=l,i=0;(temp);i++,temp=temp->n);
  printf("Список состоит из %d элементов\n",i);
  //вывод списка
/*
  for (temp=l;(temp)&&(temp->n);temp=temp->n)
    printf("%d ",temp->e);
  printf("%d\n",temp->e);
*/
  return 0;
};