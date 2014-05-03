#include <stdio.h>
char s[200];
int is_digit(char c){
	return (c<='9')&&(c>='0');
}
int main(){
	gets(s);
	int is_real=1;
	int len=0;
	for(;s[len];++len);
	int pos=0;
	while(pos<len && is_digit(s[pos])) pos++;
	if(pos==0) {
		is_real = 0;
	} else {
		if(s[pos]=='.') {
			pos++;
			while(pos<len && is_digit(s[pos])) pos++;
			if(s[pos-1]=='.') is_real=0;
		}
		if(s[pos]=='E') {
			pos++;
			if(s[pos]=='-'||s[pos]=='+') pos++;
			while(is_digit(s[pos])) pos++;
			if(!is_digit(s[pos-1])) is_real=0;
		}
	}
	if(pos!=len) is_real=0;
	printf("%s is%s a real number\n",s,is_real?"":" not");
	return 0;
}