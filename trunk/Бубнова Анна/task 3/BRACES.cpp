#include <stdio.h>
int main(){
  char s[1000];
  fgets(s,1000,stdin);
  struct {
    char ch;
    int num;
  } stack[1000],e;
  int sp=0;
#define push(x) {stack[sp].ch=*(x);stack[sp++].num=((x)-s);}
#define pop(x,n) {x=(sp==0)?0:stack[--sp].ch;\
                  n=(sp==0)?0:stack[sp].num;}
  for (char *c=s;*c;c++){
    switch (*c){
      case '(':
      case '{':
      case '[':
      case '<':
        push(c);
        break;
      case ')':
      case '}':
      case ']':
      case '>':{
        char x;
        int n;
        pop(x,n);
        if ((!x)||
            ((x=='(')&&(*c!=')'))||
            ((x=='{')&&(*c!='}'))||
            ((x=='[')&&(*c!=']'))||
            ((x=='<')&&(*c!='>'))){
          printf("%d\n",c-s);
          return 0;
        };
      };
    };
  };
  char x;
  int n;
  pop(x,n);
  if (!x)
    printf("Right\n"); else
      printf("%d\n",n);
  return 0;
};