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

int length(list *l) {
	int answer = 0;
	while (l) {
		answer++;
		l = l->next;
	}
	return answer;
}

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	int n, x;
	cout << "Print the list of integers, ending with 'x': ";
	list *head = NULL;
	while (read_int(x))
		add(head, x);

	cout << "Length of list: " << length(head) << '\n';

	getchar();
	getchar();

	return 0;
}