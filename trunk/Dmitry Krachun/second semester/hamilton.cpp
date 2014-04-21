#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

bool matrix[100][100];
bool path[1 << 20][20]; 
int main()
{
  
  //freopen("ham.in", "r", stdin);
  //`freopen("ham.out", "w", stdout);
  cout << "Please write number of vertexes and edges" << endl;
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    matrix[x - 1][y - 1] = matrix[y - 1][x - 1] = true;
  }
  if(n == 0) {cout << "YES"; return 0;}; 
  for(int x = 1; x < n; x++)
    path[1 + (1 << x)][x] = matrix[0][x];
  path[1][0] = true;
  for(int mask = 3; mask < (1 << n); mask += 2)
    for(int ver = 1; ver < n; ver++)
    {
      if(((mask) & (1 << ver)) == 0) continue;
      for(int v = 1; v < n; v++)
        {
          if((v != ver)  && matrix[v][ver] && path[mask - (1 << ver)][v]) path[mask][ver] = true;
        } 
    }
  bool ans = false;
  for(int i = 1; i < n; i++)
    ans = ans || (path[(1 << n) - 1][i] && matrix[0][i]);
  if (ans) cout << "YES"; 
  else cout << "NO";


  return 0;
} 