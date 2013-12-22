#include <iostream>
#include <string>
using namespace std;

//Computing integer power of the number

const int maxn = 200000;
int notprime[maxn];

double power(double a, int n) {
    if (n == 0) return 1.0;
    if (n == 2) return a * a;
    return (n & 1 ? power(a, n - 1) * a : power(power(a, n / 2), 2));
}

int main() {
    double a;
    int n;
    cin >> a >> n;
    if (n < 0) n *= -1, a = 1.0 / a;
    cout.precision(10);
    cout << power(a, n) << endl;
}