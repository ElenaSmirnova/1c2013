#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
long long  matrix[100][100];
long long  A[100][100];
long long  B[100][100];
int main()
{
  
  //freopen("dijekstra.in", "r", stdin);
  //freopen("dijekstra.out", "w", stdout);
  cout << "write number of vertices and edges" << endl;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j =0; j < n; j++)
      matrix[i][j] = 1e18;
  for(int i = 0; i < n; i++)
    matrix[i][i] = 0;
  
  for(int i = 0; i < m; i++)
  {
    int x, y, d; 
    cin >> x >> y >> d;
    matrix[x - 1][y - 1] = matrix[y - 1][x - 1] = d;
  }
  cerr << "HERE";
  for (int i = 0; i < n; i++)
    for (int j =0; j < n; j++)
      A[i][j] = matrix[i][j];
  for(int s = 0; s < 20; s++)
  {
   for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      {
        B[i][j] = 1e18;
        for (int k = 0; k < n; k++)
          B[i][j] = min(B[i][j], A[i][k] + A[k][j]);
      } 
   //B=A^2;
   for (int i = 0; i < n; i++)
    for (int j =0; j < n; j++)
      A[i][j] = B[i][j];
  }                   
  for(int i = 1; i < n; i++)
  cout << i + 1 << ":" << A[0][i] << endl; 
 return 0;
} 