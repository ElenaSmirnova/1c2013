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
#include <vector>

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

set<list*> used;

void erase(list *&l) {
	used.erase(l);
	if (l->next != NULL && used.find(l) != used.end())
		erase(l->next);
	delete l;
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

int length(list *l) {
    int answer = 0;
    while (l) {
        answer++;
        l = l->next;
    }
    return answer;
}

bool find_cycle(list *l) {
	if (used.find(l) != used.end())
		return 1;
	used.insert(l);

	if (l->next == NULL)
		return 0;
	
	return find_cycle(l->next);
}

int main() {
    
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    int x;
	cout << "Print queries to list in such format:\n";
	cout << "\"1 i\": add new element with key i in set;\n";
	cout << "\"2 j\": connect j-th element in set with last element in list (numeration from 1).\n";
	cout << "Generation finishing by 'x' symbol.\n";

    list *head = new list(-1); //fictive element
	list *tail = head;
	vector<list*> elements;
	elements.clear();
    while (read_int(x)) {
        if (x == 1) {
			read_int(x);
			elements.push_back(new list(x));
		} else {
			read_int(x);
			x--;
			tail->next = elements[x];
			tail = tail->next;
		}
	}

	used.clear();
	if (find_cycle(head))
		cout << "Cycle has found!\n";
	else
		cout << "Cycle has not found.\n";

	erase(head);
	elements.clear();

    getchar();
    getchar();

    return 0;
}