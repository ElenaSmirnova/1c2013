#include <iostream>
using namespace std;

//Fibonacci : simple recursion

int fib(int n) {
    return (n > 1 ? fib(n - 1) + fib(n - 2) : n);
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
}