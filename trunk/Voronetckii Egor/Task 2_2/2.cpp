#include <cstdio>
#include <cassert>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
const ld eps = 1e-12;
const int inf = 1e9;
#define pb push_back
#define pob pop_back
#define i1 first
#define i2 second
#define mp make_pair

#define file "txt"
#define N 100500

char s[N];    

struct FSM
{
	FSM *goSlash, *goStar, *goElse;
	FSM() {};
	FSM(FSM *sl, FSM *st, FSM *e): goSlash(sl), goStar(st), goElse(e) {};
};
       
int main()
{
	freopen("code.cpp", "r", stdin);
	printf("Input file is \"code.cpp\".\n");
	int n = 0;
	while (scanf("%c", &s[n]) >= 1) n++;

	FSM *start = new FSM();
	FSM *open = new FSM();
	FSM *comment = new FSM();
	FSM *close = new FSM();
	*start = FSM(open, start, start);
	*open = FSM(open, comment, start);
	*comment = FSM(comment, close, comment);
	*close = FSM(start, close, comment);

	FSM *cur = start, *prev = start;
	for (int i = 0; i < n; i++)
	{
		prev = cur;
		if (s[i] == '/') cur = cur->goSlash;
		else if (s[i] == '*') cur = cur->goStar;
		else cur = cur->goElse;
		if (cur == comment && prev == open) printf("/*");
		else if (cur == comment) printf("%c", s[i]);
		else if (cur == close) printf("%c", '*');
		else if (cur == start && prev == close) printf("/\n");
	}

	return 0;
}