#include <iostream>
using namespace std;

//List : get element by number

template<class T>
struct Anode {
	T val;
	Anode<T> *next, *prev;
	Anode<T>() {}
	Anode<T>(T val) : val(val) {}
	Anode* addprev(Anode* a) {
		a->prev = prev;
		a->next = this;
		prev->next = a;
		prev = a;
		return a;
	}
	Anode* addnext(Anode* a) {
		a->prev = this;
		a->next = next;
		next->prev = a;
		next = a;
		return a;
	}
	Anode* del(Anode* a) {
		prev->next = next;
		next->prev = prev;
		return prev;
	}
};

template<class T>
struct Alist {
	Anode<T> *head, *tail;
	Alist() {
		head = new Anode<T>();
		tail = new Anode<T>();
		head->next = tail;
		head->prev = head;
		tail->next = tail;
		tail->prev = head;
	}
};

int main() {
    int numb;
	//Input list elements ending with the -1
	Alist<int> L;
	Anode<int>* link = L.head;
	while (1) {
		cin >> numb;
		if (numb == -1) break;
		link = link->addnext(new Anode<int>(numb));
	}
	link = L.head;
	int res = 0;
	link = link->next;
	while ((link->next) != link) {
		++res;
		link = link->next;
	}
	cout << res << endl;
}