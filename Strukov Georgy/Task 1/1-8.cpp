#include <stdio.h>
#include <string.h>
#define MAXL 20000
char S[MAXL];

bool isPalindrome(char* s){
 	int i=0;
 	int j=strlen(s)-1;
 	while(s[i]==s[j]) {
 	    i++,j--;
 	    if(i>j) return true;
 	}	
 	return false;
}

int main(){
	scanf("%s",S);
	printf(isPalindrome(S)?"True":"False");
	return 0;
}