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
#include <map>

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

void print(list *l) {
	if (!l)
		return;
	
	printf("%d ", l->a);
	print(l->next);
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

list *merge(list *l1, list *l2) {
	if (!l1 && !l2)
		return NULL;

	list *head = NULL, *tail = NULL;
	if (l1 && (!l2 || l1->a < l2->a)) {
		head = l1;
		l1 = l1->next;
	} else {
		head = l2;
		l2 = l2->next;
	}
	head->next = NULL;
	tail = head;

	while (l1 || l2) {
		if (l1 && (!l2 || l1->a < l2->a)) {
			tail->next = l1;
			tail = l1;
			l1 = l1->next;
		} else {
			tail->next = l2;
			tail = l2;
			l2 = l2->next;
		}
	}

	tail->next = NULL;
	return head;
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	int n, x;
	cout << "Print first list of integers, ending with 'x': ";
	list *head1 = NULL, *head2 = NULL;
	while (read_int(x))
		add(head1, x);
	cout << "Print second list of integers, ending with 'x': ";
	while (read_int(x))
		add(head2, x);

	list *answer = merge(head1, head2);
	cout << "Sorted list:\n";
	print(answer);

	getchar();
	getchar();

	return 0;
}