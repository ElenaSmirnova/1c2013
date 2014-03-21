#include <stdio.h>
#define MAXN 1000
#define INF (int)1e9

int edge[MAXN][MAXN];
int distance[MAXN];
bool visited[MAXN];
int n,m,s;

int main(){
 	printf("Enter amount of vertices: ");
 	scanf("%d",&n);
 	printf("Enter amount of edges: ");
 	scanf("%d",&m);
 	printf("Enter number of vertex from which distances will be counted: ");
 	scanf("%d",&s);
 	s--;
 	printf("Enter edges in format: first vertex, second vertex, edge length.\n");
 	for(int i=0;i<m;i++) {
 	 	int a,b,c;
 	 	scanf("%d %d %d",&a,&b,&c);
 	 	a--;
 	 	b--;
 	 	edge[a][b]=edge[b][a]=c;
 	}
 	for(int i=0;i<n;i++) {
 	 	distance[i]=(i==s?0:INF);
 	}
 	visited[s]=1;
 	for(int i=1;i<n;i++) {
 		int minDistance=INF;
 		int vv;
 		for(int v=0;v<n;v++) {
 			for(int w=0;w<n || v==w;w++) {
 				if(edge[v][w] && visited[v] && !visited[w] && edge[v][w]+distance[v]<minDistance) {
 					vv=w;
 					minDistance=edge[v][w]+distance[v];
 				}		
 			}
 	 	}	
 	 	if(minDistance<INF) {
 	 		visited[vv]=1;
 	 		distance[vv]=minDistance;
 		}
 	}
 	for(int i=0;i<n || i==s;i++) {
 		if(distance[i]<INF) {
 			printf("Distance between vertex %d and vertex %d is %d.\n",s+1,i+1,distance[i]);	
 		} else {
 		 	printf("Vertex %d is unreachable from vertex %d.\n",i+1,s+1);
 		}
   	}
 	return 0;
}