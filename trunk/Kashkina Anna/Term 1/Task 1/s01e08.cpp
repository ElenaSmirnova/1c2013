#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//Checking whether the string is a palindome or not

int main() {
    string s, ns;
    cin >> ns;
    s = ns;
    reverse(s.begin(), s.end());
    if (s == ns) cout << "Palindrome";
    else cout << "Not palindrome";
}