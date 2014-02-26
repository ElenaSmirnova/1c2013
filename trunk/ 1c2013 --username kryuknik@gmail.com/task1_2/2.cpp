#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>

int b[100];
int v[100][100];
int n,m;

using namespace std;

void dfs(int i){
	b[i] = 1;
	for(int j=0; j<n; j++){
		if((b[j] == 0)&&(v[i,j] == 1)){
			dfs(j);
		}
	}
}

int main(){

	freopen("1.in",r,stdin);
	freopen("1.out",w,stdout);
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a,b;
		cin >> a >> b;
		v[a,b] = 1;
		v[b,a] = 1;
	}
	for(int i=0; i<n; i++){
		b[i] = 0;	
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		if(b[i] == 0){
			ans++;
			dfs(i);
		}
	}
	cout << ans;
	return 0;
}