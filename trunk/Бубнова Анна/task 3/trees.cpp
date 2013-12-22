#include <stdio.h>
#include <alloc.h>
#include <string.h>
struct Tree{
  int e;
  Tree *l,*r;
};
//������������ �����
void walk(Tree *t){
  if (t->l)
    walk(t->l);
  //��� ���-�� ����� ������� � ���������
  if (t->r)
    walk(t->r);
};
//������� ��������
Tree* add(Tree *&pos, int e){
  if (!pos){
    pos=(Tree *)malloc(sizeof(Tree));//������ ����� ������
    pos->r=pos->l=NULL;
    pos->e=e;
    return pos;
  };
  int r=pos->e;//��������� ���������� �������
  pos->e=e;
  if (r>e)
    add(pos->r,r); else
      add(pos->l,r);
  return pos;
};
//���������� �������� ��������
Tree* addNode(Tree *&pos, int e){
  if (!pos){
    pos=(Tree *)malloc(sizeof(Tree));//������ ����� ������
    pos->r=pos->l=NULL;
    pos->e=e;
    return pos;
  };
  if (e>pos->e)
    addNode(pos->r,e); else
      addNode(pos->l,e);
  return pos;
};

/* �������� ��������
���� ��� ������
 1 - ��������� ���� �� ����� ��������, ����� ��� ����� ������ �������.
 2 - ��������� ���� ����� ������ �������, ����� �� ��� ����� ���� ��������� �������.
 3 - � ���������� ���� ��� �������, � ����� ������ �� ����� ���������� ����
 ���������� ��������� ������� �� ������� ���������. �� ���� ���� ��� ������
 ������, � �� ����� ����� :)
*/
void del(Tree *&e){
  switch ((!(e->r))+(!(e->l))){
    case 2:{
      free(e);
      e=NULL;
      return;
    };
    case 1:{
      Tree *temp=e;
      if (!(e->r))
        e=e->l; else
          e=e->r;
      free(temp);
      return;
    };
    case 0:{
      Tree *temp=e->r,*oldtemp=e;
      while (temp->l){
        oldtemp=temp;
        temp=temp->l;
      };
      e->e=temp->e;
      if (oldtemp==e)
        del(e->r); else
          del(oldtemp->l);
      return;
    };
  };
};
//��� � ����, �������, ��� � ����� ��������� �� ������ �����, � ������ ������
Tree *search(Tree *t,int e){
  if (!t)
    return NULL;
  if (t->e==e)
    return t;
  if (e>t->e)
    return search(t->r,e); else
      return search(t->l,e);
};
//�������� ���������
void deltree(Tree *&t){
  if (t->l)
    deltree(t->l);
  if (t->r)
    deltree(t->r);
  free(t);
  t=NULL;
}; 

//��� ��������� ����� ���������� ������ �� ������� �� ������
//���� �� �������� ��� �� ������������
//��� ����� ��������� ���� ���� �� ������������ [������� ������]
struct RTree{
  int e;
  RTree *l,*r,*u;
};
//���������� ����� [��� ������ ������ ������� �� ����� ������,
//����������� �� ���������� ������ ������ � ����� ������]
RTree *root(RTree *e){
  if (e->u)
    return root(e->u); else
      return e;
};
//���������� ������ 2 ������, ��� ����� ����� ������ ������ �� �����
struct List{
  RTree *e;
  List *n;
};
List *up(RTree *e,List *l=NULL){
  if (!e->u){
    return l;
  };
  List *res=(List *)malloc(sizeof(List));
  res->n=up(e->u,res);
  res->e=e;
 
  return res;
};
//��������������� ����� ������ ������
RTree *ancestor(RTree *e1, RTree *e2){
  List *l1=up(e1),*l2=up(e2);
  RTree *res;
  while (l1->e==l2->e){
    res=l1->e;
    List *_=l1;
    l1=l1->n;
    free(_);
    _=l2;
    l2=l2->n;
    free(_);
  };
  //res �����
  //�� � ����� ����� ������� ����
  while (l1->e!=e1){
    List *_=l1;
    l1=l1->n;
    free(_);
  };
  free(l1);
  while (l2->e!=e2){
    List *_=l2;
    l2=l2->n;
    free(_);
  };
  free(l2);
  return res;
};
//����� ������, ��� ������������
int outtree(char *s[], int width, Tree *t,int level, int begin){
  if (!t)
    return 0;
  char *s_=s[level]+begin;//��������� ��������� �� ������-���������
  char temp[10];
  sprintf(temp,"%d",t->e);//��������� ������ � ������
  int w=strlen(temp),l=width/2-w/2;//l - � ������ ������� � ������-���������� ����� ������
  strncpy(s_+l,temp,w);//�������� � �������������� ������ ������
  //������� ������� ������
  int i;
  if (t->r){
    for (i=l+w;i<width/2+width/4;i++)
      s_[i]='-';
    s_[i]='\\';
  };
//    s_[i+1]=0;
  if (t->l){
    for (i=width/4+1;i<l;i++)
      s_[i]='-';
    s_[width/4]='/';
  };
  //�������� ����������
  int dl=outtree(s,width/2,t->l,level+1,begin);
  int dr=outtree(s,width/2,t->r,level+1,begin+width/2);
  return ((dl>dr)?dl:dr)+1;
};
//� ����� �� �����
void megaout(Tree *t,int width){
  char s_[10][80],*s[10];
  {
  //������ ������� ���������
  for (int j=0;j<10;j++){
    s[j]=s_[j];
    for (int i=0;i<79;i++)
      s[j][i]=' ';
    s[j][i]=0;
  };
  };
  int depth=outtree(s,width,t,0,0);
  for (int j=0;j<depth;j++)
    puts(s[j]);
};

int main(){
//  Tree root[7]={{8,root+1,root+2},{4,root+3,root+4},{12,root+5,root+6},
//                {2,0,0},{6,0,0},{10,0,0},{14,0,0}};
  Tree *root=NULL;
  addNode(root,8);
  addNode(root,4);
  addNode(root,12);
  addNode(root,2);
  addNode(root,6);
  addNode(root,10);
  addNode(root,14);
  printf("����-���� ������, ��� �����:\n");megaout(root,64);
  add(search(root,4),5);
  printf("� ������ � ���� 4 �������� �� 5\n");megaout(root,64);
  Tree *t=search(root,10);
  add(t->r,11);
  printf("� ������ �������� �� 10 �������� 11\n");megaout(root,64);
  del(root);
  printf("� ����� ������� ������\n");megaout(root,64);
  deltree(root->l);
  printf("� ����� ���������\n");megaout(root,64);
  deltree(root);
//  printf("%d\n",search(root,12)-root);
  return 0;
};