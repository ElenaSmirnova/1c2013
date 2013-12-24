#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Checking bracket sequence
vector<char> stack;

void fail() {
    cout << "Incorrect";
    exit(0);
}

void ok() {
    cout << "Correct";
}

int main() {
    string s;
    cin >> s;
    stack.push_back('*');
    for (int i = 0; i < s.size(); ++i)
        if (string("[({<>})]").find(s[i]) == string::npos) continue;
        else if (string("[({<").find(s[i]) != string::npos)
            stack.push_back(s[i]);
        else if (abs(s[i] - stack.back()) < 3)
            stack.pop_back();
        else fail();
    if (stack.size() > 1) fail();
    ok();
}