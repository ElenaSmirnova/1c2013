#include <iostream>
#include <string>
using namespace std;

//Counting occurrences of substrings S1 in S

int main() {
    string s, s1;
    cin >> s >> s1;
    int res = 0;
    for (int i = 0; i < s.size(); ++i)
        if (s.substr(i, s1.size()) == s1)
            ++res;
    cout << res << endl;
}