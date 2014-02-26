#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algoritm>

using namespace std;

int v[100][100];
bool b[100];
int way[100];
int n; 

bool createway(const int nowplace){

	if(nowplace == n){
		way[n] = way[0];
		bool ans = true;
		for(int i=0; i<n; i++){
			ans = ans && (v[way[i]][way[i+1]] == 1);
		}
		return ans;
	}else{
		bool ans = false;
		for(int i=0; i<n; i++){
			if(!b[i]){
				way[nowplace] = i;
				b[i] = true;
				ans = ans || createway(nowplace + 1);
				b[i] = false;
			}
		}
	}
}

int main(){

	int m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a,b;
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1;
	}
	
	bool res = createway(0);
	cout << res; 
	return 0;
}