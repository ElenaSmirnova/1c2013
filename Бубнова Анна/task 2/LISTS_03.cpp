#include <stdio.h>
#include <alloc.h>
struct List{
  int e;
  List *n,*p;
};
#define MAX_L 80
int main(){
  int x;
  List *l=NULL,**tail=&l,*pretail=NULL;
  printf("„тобы закончить ввод списка, введите не число\n");
  char s[MAX_L];
  while (fgets(s,MAX_L,stdin),sscanf(s,"%d",&x)>0){
    (*tail)=(List *)malloc(sizeof(List));
    (*tail)->e=x;
    (*tail)->n=NULL;
    (*tail)->p=pretail;
    pretail=*tail;
    tail=&((*tail)->n);
  };
  for (List *b=l,*e=pretail;(b!=e)&&(b->p!=e);e=e->p,b=b->n){
    List *temp;
    if (b->n!=e){
      temp=e->p;
      e->p=b->p;
      b->p=temp;
      temp=e->n;
      e->n=b->n;
      b->n=temp;
    } else {
        b->n=e->n;
        e->p=b->p;
        b->p=e;
        e->n=b;
      };
    temp=b;
    b=e;
    e=temp;
    if (e->n)
      e->n->p=e;
    if (b->p)
      b->p->n=b;
    e->p->n=e;
    b->n->p=b;
    //нет, конечно, можно помен€ть сами значени€, а смысл? :)
  };
  l=pretail;
  List *temp;
  //вывод списка
  for (temp=l;(temp)&&(temp->n);temp=temp->n)
    printf("%d ",temp->e);
  printf("%d\n",temp->e);
  return 0;
};