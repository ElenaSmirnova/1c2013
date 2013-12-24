#include <iostream>
using namespace std;

//Fibonacci : iterative, modulo 2^64

const int maxn = 200000;
unsigned long long fib[maxn];

int check(int n) {
    if (n >= 0 && n < maxn) return 1;
    cout << "Ivalid input\n";
    exit(0);
}

int main() {
    int n;
    fib[0] = 0;
    fib[1] = 1;
    cin >> n;
    check(n);
    for (int i = 2; i <= n; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    cout << fib[n] << endl;
}