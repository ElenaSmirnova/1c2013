#include <iostream>
#include <string>
using namespace std;

//Printing prime numbers <= n

const int maxn = 200000;
int notprime[maxn];

int main() {
    int n;
    cin >> n;
    notprime[1] = 1;
    for (int i = 2; i <= n; ++i)
        if (!notprime[i]) {
            printf("%d ", i);
            for (int j = 2 * i; j <= n; j += i)
                notprime[j] = 1;
        }
}