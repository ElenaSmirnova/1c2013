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

void dfs(tree *&t, int depth) {
	read_int(t->value);
	if (depth > 0) {
		tree *tl = new tree(0), *tr = new tree(0);
		dfs(tl, depth - 1);
		dfs(tr, depth - 1);
		t->left = tl;
		t->right = tr;
		return;
	}
}

void find_paths(tree *t, int sum, string path) {
	if (!t->left) {
		if (sum == 0)
			cout << path << '\n';
		return;
	}

	find_paths(t->left, sum + t->left->value, path + 'L');
	find_paths(t->right, sum + t->right->value, path + 'R');
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	tree *root = NULL;
	int n;
	cout << "Print the depth of tree: ";
	read_int(n);

	cout << "Now print weights of all vertexes. They are enumerated in such way:\n";
	cout << "     1     \n";
	cout << "    / \\    \n";
	cout << "   2   5   \n";
	cout << "  / \\ / \\  \n";
	cout << "  3 4 6 7  \n";
	cout << " {.......} \n";

	root = new tree(0);
	dfs(root, n);

	//print(root);

	cout << "All paths have written as strings conststing of symbols 'L' and 'R': methods of going down from root.\n";
	find_paths(root, root->value, "");

	clear(root);

	getchar();
	getchar();

	return 0;
}