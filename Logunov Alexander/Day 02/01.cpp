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

struct list {
	int a;
	list *next;
	list(int _a) {
		a = _a;
		next = NULL;
	}
};

int read_int(int &x) {
	char s[BUF];
	scanf("%s", s);
	if (sscanf(s, "%d", &x) <= 0) {
		cout << "Illegal format!\n";
		gets(s);
		gets(s);
		exit(0);
	} else
		return 1;		
}

void add(list *&l, int new_value) {
	if (!l) {
		l = new list(new_value);
		return;
	}

	list *tail = l;
	while (tail->next)
		tail = tail->next;

	list *elem = new list(new_value);
	tail->next = elem;
}

int find(list *l, int key) {
	for (int i = 1; l && i < key; i++) {
		l = l->next;
	}
	if (l) {
		return l->a;
	} else {
		cout << "Something went wrong! Connect the author.\n";
		return -1;
	} 
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	int n, x;
	cout << "Print number of elements in list: ";
	read_int(n);

	list *head = NULL;
	cout << "Print all elements of array: ";
	for (int i = 0; i < n; i++) {
		read_int(x);
		add(head, x);
	}

	int q;
	cout << "Print number of queries: ";
	read_int(q);

	cout << "Print all queries in turn (numeration from 1): ";
	for (int i = 0; i < q; i++) {
		read_int(x);
		if (x <= n) {
			cout << find(head, x) << '\n';
		}
		else {
			cout << "No such element.\n";
		}
	}

	getchar();
	getchar();

	return 0;
}