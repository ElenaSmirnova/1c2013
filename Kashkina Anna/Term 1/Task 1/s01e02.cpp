#include <iostream>
#include <cstdio>
using namespace std;

//Sort : bubble

const int maxn = 5000;
int a[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i + 1 < n; ++i)
        for (int j = 0; j + 1 < n; ++j)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
}