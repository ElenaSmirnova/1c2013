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

void clear(tree *&t) {
	if (!t)
		return;
	
	clear(t->left);
	clear(t->right);
	delete t;
}

void debug(tree *t) {
	if (!t)
		return;
	
	debug(t->left);
	printf("[%d]->{%d, %d}\n", t->value, (t->left ? t->left->value : -1), (t->right ? t->right->value : -1));
	debug(t->right);
}

void print(tree *t) {
	if (!t)
		return;
	
	print(t->left);
	printf("%d ", t->value);
	print(t->right);
}

tree *insert(tree *&t, int key) {
	if (t == NULL) {
		t = new tree(key);
	} else {
		if (t->value > key) {
			t->left = insert(t->left, key);
		} else {
			t->right = insert(t->right, key);
		}
	}

	return t;
}

void insert_subtree(tree *&t, tree *st) {
	if (t == NULL) {
		t = st;
	} else {
		if (t->value > st->value) {
			insert_subtree(t->left, st);
		} else {
			insert_subtree(t->right, st);
		}
	}
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	tree *root = NULL, *subrt = NULL;
	int x;

	cout << "Print all elements of tree. Finish the list by 'x': ";
	while (read_int(x))
		root = insert(root, x);

	cout << "Now print all elements of sub-tree. Finish the list by 'x': ";
	while (read_int(x))
		subrt = insert(subrt, x);

	insert_subtree(root, subrt);
	//debug(root);

	print(root);

	clear(root);

	getchar();
	getchar();

	return 0;
}