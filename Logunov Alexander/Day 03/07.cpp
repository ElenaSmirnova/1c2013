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

void debug(tree *t) {
	if (!t)
		return;
	
	debug(t->left);
	printf("[%d]->{%d, %d}\n", t->value, (t->left ? t->left->value : -1), (t->right ? t->right->value : -1));
	debug(t->right);
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

tree *find(tree *t, int key) {
	if (!t)
		return NULL;

	if (t->value == key)
		return t;
	if (t->value > key)
		return find(t->left, key);
	return find(t->right, key);
}

tree *erase_subtree(tree *&t, int x) {
	tree *tx = find(t, x);
	if (tx == t) {
		clear(tx);
		return NULL;
	} else {
		(tx->parent->left == tx ? tx->parent->left : tx->parent->right) = NULL;
		clear(tx);
		return t;
	}
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	tree *root = NULL;
	int x;

	cout << "Print all elements of tree. Finish the list by 'x': ";
	while (read_int(x))
		root = insert(root, NULL, x);

	cout << "Subtree of what vertex do you want to erase? ";
	read_int(x);
	root = erase_subtree(root, x);

	debug(root);

	clear(root);

	getchar();
	getchar();

	return 0;
}