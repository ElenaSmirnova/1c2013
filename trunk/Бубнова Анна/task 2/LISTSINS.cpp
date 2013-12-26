#include <stdio.h>
#include <alloc.h>
struct List{
  int e;
  List *n,*p;
};
#define MAX_L 80
int main(){
  List *l=NULL,**tail=&l,*pretail=NULL;
  int n=0;
  {
  printf("Чтобы закончить ввод списка, введите не число\n");
  char s[MAX_L];
  int x;
  while (fgets(s,MAX_L,stdin),sscanf(s,"%d",&x)>0){
    (*tail)=(List *)malloc(sizeof(List));
    (*tail)->e=x;
    (*tail)->n=NULL;
    (*tail)->p=pretail;
    pretail=*tail;
    tail=&((*tail)->n);
    n++;
  };
  };//это ограничение области видимости для x
  //проверку на пустоту не пишу
  List *temp;
  for (temp=l->n;(temp);temp=temp->n){
    List *x=temp;
    while ((x->p)&&(x->p->e>x->e))
/*#define moveback(x)*/ {if (x->p){
                       if (x->p->p){
                         x->p->p->n=x;
                         x->p->n=x->n;
                         if (x->n)
                           x->n->p=x->p;
                         List *_=x->p->p;
                         x->p->p=x;
                         x->n=x->p;
                         x->p=_;
                       } else {//x->p==l
                           l=x;
                           if (x->n)
                             x->n->p=x->p;
                           x->p->n=x->n;
                           x->p->p=x;
                           x->n=x->p;
                           l->p=NULL;
                         };
                     };};
  };
  //вывод списка, в прямом порядке для проверки ->n,
  int i;
  for (temp=l,i=0;(temp)&&(temp->n)&&(i<n*2);i++,temp=temp->n)
    printf("%d ",temp->e);
  printf("%d\n",temp->e);
  //и в обратном, для проверки ->p
  for (i=0;(temp)&&(temp->p)&&(i<n*2);i++,temp=temp->p)
    printf("%d ",temp->e);
  printf("%d\n",temp->e);
  //"на теле программы было обнаружено множество следов отладки"
  return 0;
};
