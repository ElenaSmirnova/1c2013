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
	tree *left, *right, *parent;
	tree(int _value) {
		value = _value;
		left = right = parent = NULL;
	}
	tree(int _value, tree *_parent) {
		value = _value;
		left = right = NULL;
		parent = _parent;
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

void clear(tree *&t) {
	if (!t)
		return;
	
	clear(t->left);
	clear(t->right);
	delete t;
}

void print(tree *t) {
	if (!t)
		return;
	
	print(t->left);
	printf("%d ", t->value);
	print(t->right);
}

tree *insert(tree *&t, tree *par, int key) {
	if (t == NULL) {
		t = new tree(key, par);
	} else {
		if (t->value > key) {
			t->left = insert(t->left, t, key);
		} else {
			t->right = insert(t->right, t, key);
		}
	}

	return t;
}

tree *root(tree *t) {
	if (!t->parent)
		return t;
	return root(t->parent);
}

void root_debug(tree *t) {
	if (!t)
		return;
	
	root_debug(t->left);

	printf("[%d]->{%d, %d}\n", t->value, (t->left ? t->left->value : -1), (t->right ? t->right->value : -1));
	tree *rt = root(t);
	printf("Root: %d\n", rt->value);

	root_debug(t->right);
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	tree *root = NULL;
	int x;

	cout << "Print all elements of tree. Finish the list by 'x': ";
	while (read_int(x))
		root = insert(root, NULL, x);

	root_debug(root);

	clear(root);

	getchar();
	getchar();

	return 0;
}