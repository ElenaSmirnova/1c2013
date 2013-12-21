#include <iostream>
using namespace std;

//Fibonacci : iterative

const int maxn = 200000;
int fib[maxn];

int main() {
    int n;
    fib[0] = 0;
    fib[1] = 1;
    cin >> n;
    for (int i = 2; i <= n; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    cout << fib[n] << endl;
}