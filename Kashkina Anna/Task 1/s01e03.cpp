#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

//Dividing random array in O(n)

const int maxn = 200000, MAX = 10000;
int a[maxn];

int main() {
    srand(time(NULL));
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % MAX;
        cout << a[i] << " ";
    }
    cout << endl;
    int l = 0, r = n - 1, x = a[0];
    while (l < r) {
        if (a[l] > a[r]) swap(a[l], a[r]);
        if (a[l] == x) --r;
        else ++l;
    }
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
}