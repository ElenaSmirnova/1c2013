#pragma comment(linker, "/STACK:67108864")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> 
#include <sstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

const int BUF = 256;

struct tree {
    int value;
    tree *left, *right;
    tree(int _value) {
        value = _value;
        left = right = NULL;
    }
};

int read_int(int &x) {
    char s[BUF];
    scanf("%s", s);
    if (s[0] == 'x')
        return 0;
    if (sscanf(s, "%d", &x) <= 0) {
        cout << "Illegal format!\n";
        gets(s);
        gets(s);
        exit(0);
    } else      
        return 1;
}

void print(tree *t) {
    if (!t)
        return;
    
	print(t->left);
    printf("%d ", t->value);
    print(t->right);
}

int main() {
    
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    tree *root = NULL;

	root = new tree(2);
	root->left = new tree(1);
	root->right = new tree(4);
	root->right->left = new tree(3);
	
    print(root);

    getchar();

    return 0;
}