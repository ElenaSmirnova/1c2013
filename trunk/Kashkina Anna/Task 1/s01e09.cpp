#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

//Sort : quick, recursive

const int maxn = 200000;
int a[maxn];

inline int bigrand() {
	return abs(rand() * RAND_MAX + rand());
}

void qsort(int a[], int l, int r) {
    if (!(l < r)) return;
    int i = l, j = r;
    swap(a[bigrand() % (r - l + 1) + l], a[l]);
    int x = a[l];
    while (i < j) {
        if (a[i] > a[j]) swap(a[i], a[j]);
        if (a[i] == x) --j;
        else ++i;
    }
    qsort(a, l, i - 1);
    qsort(a, i + 1, r);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    qsort(a, 0, n - 1);
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
}