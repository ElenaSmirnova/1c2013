#include <stdio.h>
#define MAX_L 80
int main(){
  char s[MAX_L];
  fgets(s,MAX_L,stdin);

  int st[MAX_L],sp=0;
#define push(x) {st[sp++]=(x);}
#define pop() (st[--sp])
#define empty() (sp==0)
  for (int i=0;s[i];i++)
    if (s[i]=='('){
      push(i);
    } else
        if (s[i]==')')
          if (empty()){
            printf("Wrong\n");
            return 0;
          } else {
              pop();
            };
  printf((empty())?"Right\n":"Wrong\n");
  return 0;
};