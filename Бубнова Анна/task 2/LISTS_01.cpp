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
  printf("����� ��������� ���� ������, ������� �� �����\n");
  char s[MAX_L];
  while (fgets(s,MAX_L,stdin),sscanf(s,"%d",&x)>0){
    (*tail)=(List *)malloc(sizeof(List));
    (*tail)->e=x;
    (*tail)->n=NULL;
    tail=&((*tail)->n);
  };
  List *temp;
  printf("������� ����� �������� ������, ������� � 0 :)\n");
  int n,i;
  scanf("%d",&n);
  for (temp=l,i=n;(temp)&&(i);--i,temp=temp->n);
  if (temp)
    printf("%d\n",temp->e); else
      printf("�������� � ������� %d ���.\n",n);
  for (temp=l,i=0;(temp);i++,temp=temp->n);
  printf("������ ������� �� %d ���������\n",i);
  //����� ������
/*
  for (temp=l;(temp)&&(temp->n);temp=temp->n)
    printf("%d ",temp->e);
  printf("%d\n",temp->e);
*/
  return 0;
};