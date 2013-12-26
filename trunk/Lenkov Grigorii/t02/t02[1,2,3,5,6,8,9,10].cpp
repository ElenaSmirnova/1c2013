#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;
//функции для задач обозначены как t02xx, xx - номер задачи, ввод списка кончается на 0
struct sp{
	int dat;
	sp *next;
	bool fhtagn;
};
void create(sp *&s)
{
	int x;
	cin >> x;
	if (x != 0)
	{
		s = new sp();
		s->next = 0;
		s->dat = x;
		create(s->next);
	}
}
//void del(sp *s)
//{
//	if (s == 0) return; del(s->next); del(s);
//}


//int t0201(sp *s, int n)
//{
//	if (n < 0) return 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (s == 0) return 0;
//		s = s->next;
//	}
//	return s ? s->dat :0;
//}


//int t0202(sp *s)
//{
//	int r = 0;
//	while (s != 0)
//	{
//		r++, s = s->next;
//	}return r;
//}


//void t0203(sp *&s)
//{
//	if (s == 0 || s->next == 0) return;
//	sp *end = s->next;
//	t0203(end);
//	s->next->next = s;
//	s->next = 0;
//	s = end;
//}


//void t0209(sp *&s)
//{
//	if (s == 0) return;
//	if (s->dat > 0) s = s->next, t0209(s);
//	else t0209(s->next);
//}


//void t0210(sp *s, int x, int y)
//{
//	if (s == 0) return;
//	if (s->dat == x)
//	{
//		sp *n = new sp();
//		n->next = s->next;
//		n->dat = y;
//		s->next = n;
//		t0210(s->next, x, y);
//	}
//	else
//		t0210(s->next, x, y);
//}


//void t0208(sp* &s, sp* a, sp* b)
//{
//	if (a == 0) s = b;
//	else if (b == 0) s = a;
//	else if (b->dat > a->dat) { s = a; t0208(s->next, a->next, b); }
//	else { s = b; t0208(s->next, a, b->next); }
//}


//int t0205(sp* s)
//{
	
//	if (s == 0) printf("0");
//	int pos = 0;
//	int posmin = 0;
//	int min = s->dat;
//	for (sp* i=s; s!=0; s=s->next)
//	{
//		pos++;
//		if (s->dat < min) posmin = pos;
//	}return posmin;
//}


int main()
{
	//sp *m = 0;
	sp *s = 0;
	create(s);
	//t0206 begins
	//int *a = new int[1000000];
	//for (sp *i = s; s != 0; s = s->next) (a[s->dat])++;
	//for (int i = 0; i < 1000000; i++)
	//if (a[i]>0) { printf("%d", i); printf(" "); printf("%d", a[i]); };
	//t0206 ends
	//create(m);
	//t0208(s, s, m);
	//t0210(s, -5, 5);
	//t0209(s);
	//int n;
	//cin>>n;
	//printf("%d", t0201(s, n));
	//printf("                     ");
	//printf("%d", t0202(s));
	//printf("                     ");
	//t0203(s);
	//printf("%d", t0205(s));
	//printf("                     ");
	for (sp *i = s; s != 0; s = s->next) {
		printf("%d", s->dat); printf(" ");
	}
	
	//del(s);

	getchar();
	getchar();
}
