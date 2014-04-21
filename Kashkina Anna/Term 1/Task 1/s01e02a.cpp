#include <iostream>
#include <cstdio>
using namespace std;

//Sort : counting

const int maxn = 200000;
int a[maxn], hm[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++hm[a[i]];
    }
    for (int i = 0; i < maxn; ++i)
        while (hm[i]) {
            printf("%d ", i);
            --hm[i];
        }
}