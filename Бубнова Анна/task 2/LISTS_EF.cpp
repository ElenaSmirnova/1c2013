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
  printf("������� E, F\n");
  int e,f;
  scanf("%d %d",&e,&f);
  for (temp=l;(temp);temp=temp->n)
    if (temp->e==e){
      List *x=(List *)malloc(sizeof(List));//��, ��� ���������
      //��, new List(f,temp->n) ���� �� �������� ���� �������� :)
      x->e=f;
      x->n=temp->n;
      temp->n=x;
      temp=temp->n;//��������� ����������� �������, � �� ���� ��, �������� :)
    };
  //����� ������
  for (temp=l;(temp)&&(temp->n);temp=temp->n)
    printf("%d ",temp->e);
  printf("%d\n",temp->e);
  return 0;
};