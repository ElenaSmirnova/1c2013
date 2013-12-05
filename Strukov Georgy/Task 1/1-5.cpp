#include <stdio.h>
#include <string.h>
#define MAXL 100000

int substr(char*s, char*t){
 	int n=strlen(s);
 	int m=strlen(t);
 	int pf[2*MAXL];
 	pf[1]=0;
 	char S[2*MAXL];
 	for(int i=0;i<=m+n;i++) {
 		if(i<m) {
 			S[i]=t[i];
 		} else if(i==m) {
 			S[i]=1;
 		} else {
 		 	S[i]=s[i-m-1];
 		}
 	}
 	int p=0;
 	int ans=0;
 	for(int i=1;i<=m+n;i++) {
 	 	while((p>0)&&(S[p]!=S[i])){
 	 		p=pf[p-1];
 	 	}
 	 	if(S[p]==S[i]) {
 	 	 	p++;
 	 	}
 	 	pf[i]=p;
 	 	if(p==m) ans++;
 	}
 	return ans;
}

char S1[MAXL],S2[MAXL];

int main(){
 	scanf("%s",S1);
 	scanf("%s",S2);
 	printf("%d",substr(S1,S2));
 	return 0;
}
