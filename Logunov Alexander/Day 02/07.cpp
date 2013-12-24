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
#include <set>

using namespace std;

const int BUF = 256;

struct list {
	int a;
	list *next, *prev;
	list(int _a) {
		a = _a;
		prev = next = NULL;
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
		elem->prev = tail;
}

int length(list *l) {
	int answer = 0;
	while (l) {
		answer++;
		l = l->next;
	}
	return answer;
}

void sort(list *l) {
	if (!l)
		return;

	list *head = l, *cur = l->prev, *prv = l->prev, *nxt = l->next;
	if (prv)
		prv->next = nxt;
	if (nxt)
		nxt->prev = prv;

	while (cur && cur->a >= l->a) {
		cur = cur->prev;
	}
		
	if (!cur) {
		cur = l;
		while (cur->prev) {
			cur = cur->prev;
		}
		l->prev = NULL;
		l->next = cur;
		cur->prev = l;
		head = l;
	} else {
		nxt = cur->next;
		cur->next = l;
		l->next = nxt;
		l->prev = cur;
		if (nxt)
			nxt->prev = l;
	}

	sort(nxt);
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	int n, x;
	cout << "Print the list of integers, ending with 'x': ";

	list *head = NULL;
	while (read_int(x))
		add(head, x);

	sort(head->next);
	while (head->prev)
		head = head->prev;
	print(head);
	
	erase(head);

	getchar();
	getchar();

	return 0;
}