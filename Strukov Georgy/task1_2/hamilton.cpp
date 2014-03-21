#include <stdio.h>
#define MAXN (int)1e3

int n,m;
bool edge[MAXN][MAXN];
bool exists;
bool visited[MAXN];

void dfs(int v, int depth) {
 	visited[v]=1;
 	for(int w=0;w<n;w++) {
 	    if(edge[v][w]) {
 	     	if(w==0 && depth==n) {
 	     	    exists=1;
 	     	} else {
 	     	 	if(!visited[w]) {
 	     	 	 	dfs(w,depth+1);
 	     	 	}
 	     	}
 	    }
 	}	
 	visited[v]=0;
}

int main(){
 	printf("Enter amount of vetrices: ");
 	scanf("%d",&n);
 	printf("Enter amount of edges: ");
 	scanf("%d",&m);
 	printf("Enter edges:\n");
 	for(int i=0;i<m;i++) {
 		int a,b;
 		scanf("%d %d",&a,&b);
 		a--,b--;
 		edge[a][b]=edge[b][a]=1; 	
 	}
 	dfs(0,1);
 	printf(exists?"Yes":"No");
 	return 0;
}