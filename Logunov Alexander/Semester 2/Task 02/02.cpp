#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> 
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;

enum {init, slash, comment, star};

const int jump[4][3] = {{0, 1, 0},
                        {0, 0, 2},
                        {2, 2, 3},
                        {2, 0, 3}};

int main() {

        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
        
        int id[256];
        for (int i = 0; i < 256; i++)
           id[i] = 0;
        id['/'] = 1;
        id['*'] = 2;

        cout << "Write some code on C++.\n";
        cout << "Finish the process by \"END\" without quotes.\n";

        string s, code = "";
        int state = init;

        while (true) {
                getline(cin, s);
                if (s == "END")
                        break;

                s += '\n';

                for (int i = 0; i < (int)s.size(); i++) {
                        char c = s[i];
                        switch(state) {
                                case init: {
                                        break;
                                }
                                case slash: {
                                        switch(c) {
                                                case '*': {
                                                        code += "/*";
                                                        break;
                                                }
                                        }
                                        break;
                                }
                                case comment: {
                                        code += c;
                                        break;
                                }
                                case star: {
                                code += c;
                                        switch(c) {
                                                case '/': {
                                                        code += '\n';
                                                        break;
                                                }
                                        }
                                        break;
                                }
                        }

                    state = jump[state][id[c]];
                }
        }

        cout << code;

        getchar();

        return 0;
}