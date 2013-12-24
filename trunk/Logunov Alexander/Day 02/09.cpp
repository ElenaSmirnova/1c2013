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

void erase(list *&l) {
	if (l->next != NULL)
		erase(l->next);
	delete l;
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

list *erase_neg(list *l) {
	list *cur = l;
	while (cur && cur->a > 0) {
		cur = cur->next;
	}
	if (!cur)
		return NULL;

	list *head = cur, *nxt = head;
	cur = cur->next;
	while (cur) {
		if (cur->a <= 0) {
			delete nxt->next;
			nxt->next = cur;
			nxt = cur;
		}
		cur = cur->next;
	}

	return head;
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	int n, x;
	cout << "Print the list of integers, ending with 'x': ";

	list *head = NULL;
	while (read_int(x))
		add(head, x);

	head = erase_neg(head);
	print(head);
	cout << '\n';

	erase(head);

	getchar();
	getchar();

	return 0;
}