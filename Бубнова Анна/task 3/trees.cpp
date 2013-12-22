#include <stdio.h>
#include <alloc.h>
#include <string.h>
struct Tree{
  int e;
  Tree *l,*r;
};
//симметричный обход
void walk(Tree *t){
  if (t->l)
    walk(t->l);
  //тут что-то можно сделать с элементом
  if (t->r)
    walk(t->r);
};
//вставка элемента
Tree* add(Tree *&pos, int e){
  if (!pos){
    pos=(Tree *)malloc(sizeof(Tree));//делаем новый листик
    pos->r=pos->l=NULL;
    pos->e=e;
    return pos;
  };
  int r=pos->e;//сохранили предыдущий элемент
  pos->e=e;
  if (r>e)
    add(pos->r,r); else
      add(pos->l,r);
  return pos;
};
//добавление элемента листиком
Tree* addNode(Tree *&pos, int e){
  if (!pos){
    pos=(Tree *)malloc(sizeof(Tree));//делаем новый листик
    pos->r=pos->l=NULL;
    pos->e=e;
    return pos;
  };
  if (e>pos->e)
    addNode(pos->r,e); else
      addNode(pos->l,e);
  return pos;
};

/* удаление элемента
есть три случая
 1 - Удаляемый узел не имеет потомков, тогда его можно просто удалить.
 2 - Удаляемый узел имеет одного потомка, тогда на его место надо поставить потомка.
 3 - У удаляемого узла два потомка, в таком случае на место удаляемого узла
 необходимо поставить минимум из правого поддерева. То есть один раз пройти
 вправо, и до конца влево :)
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
//как и выше, считаем, что в левом поддереве всё меньше корня, в правом больше
Tree *search(Tree *t,int e){
  if (!t)
    return NULL;
  if (t->e==e)
    return t;
  if (e>t->e)
    return search(t->r,e); else
      return search(t->l,e);
};
//удаление поддерева
void deltree(Tree *&t){
  if (t->l)
    deltree(t->l);
  if (t->r)
    deltree(t->r);
  free(t);
  t=NULL;
}; 

//для следующих задач используем дерево со ссылкой на предка
//хотя на практике это не используется
//без этого алгоритмы ниже были бы неэффективны [перебор дерева]
struct RTree{
  int e;
  RTree *l,*r,*u;
};
//нахождение корня [без ссылки наверх задание не имеет смысла,
//приходилось бы передавать корень дерева в любом случае]
RTree *root(RTree *e){
  if (e->u)
    return root(e->u); else
      return e;
};
//наименьший предок 2 вершин, для этого найдём список вершин до корня
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
//непосредственно поиск общего предка
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
  //res нашли
  //ну и убьём концы списков тоже
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
//вывод дерева, для тестирования
int outtree(char *s[], int width, Tree *t,int level, int begin){
  if (!t)
    return 0;
  char *s_=s[level]+begin;//посчитали указатель на строку-результат
  char temp[10];
  sprintf(temp,"%d",t->e);//напечтали корень в строку
  int w=strlen(temp),l=width/2-w/2;//l - с какого символа в строке-результате будет корень
  strncpy(s_+l,temp,w);//записали в результирующую строку корень
  //оформим веточки дерева
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
  //печатаем поддеревья
  int dl=outtree(s,width/2,t->l,level+1,begin);
  int dr=outtree(s,width/2,t->r,level+1,begin+width/2);
  return ((dl>dr)?dl:dr)+1;
};
//и вывод на экран
void megaout(Tree *t,int width){
  char s_[10][80],*s[10];
  {
  //забьём строчки пробелами
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
  printf("Жило-было дерево, вот такое:\n");megaout(root,64);
  add(search(root,4),5);
  printf("И решили у него 4 заменить на 5\n");megaout(root,64);
  Tree *t=search(root,10);
  add(t->r,11);
  printf("и правым потомком от 10 добавить 11\n");megaout(root,64);
  del(root);
  printf("а потом удалить корень\n");megaout(root,64);
  deltree(root->l);
  printf("и левое поддерево\n");megaout(root,64);
  deltree(root);
//  printf("%d\n",search(root,12)-root);
  return 0;
};