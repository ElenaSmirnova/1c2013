#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

bool matrix[1000][1000];
bool was[1000];
int n;
int a[2000000];
int print[200];                    

void dfs(int x)
{
  if (was[x]) return;
  for(int i = 0; i < n; i++)
  {
    if(matrix[x][i] && (i != x)) 
    {
      was[i] = true;
      dfs(i);
    }
  }
}
int main()
{
  
freopen("graph.in", "r", stdin);
freopen("graph.out", "w", stdout);
  cout << "write number of vertices and edges" << endl;
  int m;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
  {
    int x, y; 
    cin >> x >> y;
    matrix[x - 1][y - 1] = matrix[y - 1][x - 1] = true;
  }
  int ans = 0;
 for(int i = 0; i < n; i++)
 {
   if(!was[i]) ans++;
   dfs(i);
 };  
cout << ans << endl;
 return 0;
} 