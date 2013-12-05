#include <stdio.h>
#include <string.h>
#define MAXL 20000
char S[MAXL];
bool balance(char *s){
 	int len=strlen(s);
 	int bal=0;
 	for(int i=0;i<len;i++) {
 	 	bal+=(s[i]=='('?1:-1);
 	 	if(bal<0) return false;
 	}
 	if(bal==0) return true;
 	return false;
}
int main(){
 	scanf("%s",S);
 	printf(balance(S)?"True":"False");	
 	return 0;
}