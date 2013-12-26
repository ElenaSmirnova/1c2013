#include <stdio.h>
#include <alloc.h>
#include <time.h>
#include <stdlib.h>
struct List{
  int e;
  List *n;
};
List *cycleBegin(List *l){
  for (List *temp=l;(temp)&&(temp->n);temp=temp->n){
    List *x;
    for (x=l;(temp!=x)&&(temp->n!=x);x=x->n);
      if (temp->n==x)
        return x;
  };
  return NULL;
};
#define MAX_L 10
int main(){
  List l[MAX_L];
  srand(time(NULL));
  for (int i=0;i<MAX_L;i++){
    l[i].e=rand();
    l[i].n=&(l[i+1]);
  };
  l[MAX_L-1].n=NULL;
  if (rand()%2)
    l[MAX_L-1].n=&(l[rand()%MAX_L]);
  List *x=cycleBegin(l);
  if (!x)
    printf("No cycle\n"); else
      printf("Cycle begins with %d\n",x->e);
  i=0;
  for (List *temp=l;(temp)&&(temp->n)&&(i<=MAX_L*5/2);temp=temp->n,i++)
    printf("%d ",temp->e);
  printf("%d\n",temp->e);
  return 0;
};