#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;

//List : removing positive elements

struct Anode {
        Anode* next, *prev;
        int val, check, id;
        void init() {
                next = prev = this;
        }
        Anode(int id) : id(id) {init();}
        Anode(int id, int val) : id(id), val(val) {init();}
        void upd() {
                next->prev = this;
                prev->next = this;
        }
        friend void Aswap(Anode* a, Anode* b) {
                swap(a->prev, b->prev);
                swap(a->next, b->next); 
                if (a->next == a) swap(a->next, b->prev);
                else swap(a->prev, b->next);
                a->upd();
                b->upd();
        }
        friend void add(Anode* a, Anode* b) {
                Anode* rem = a->next;
                a->next = b;
                b->prev->next = rem;
                rem->prev = b->prev;
                b->prev = a;
        }
        friend void isolate(Anode* a) {
                a->prev->next = a->next;
                a->next->prev = a->prev;
                a->next = a->prev = a;
        }
        friend void reverse(Anode* a) {
                if (a->next->next == a) return;
                Anode* rem1 = a->prev;
                Anode* rem2 = a->next->next;
                rem1->next = rem2;
                rem2->prev = rem1;
                a->prev = a->next;
                a->prev->next = a;
                reverse(rem1);
                add(a, rem1);
        }
};

struct Alist {
        map<int, Anode*> sheaf;
        void del(int, int);
        Anode* begin() {
                return sheaf[0]->next;
        }
        Anode* end() {
                return sheaf[0];
        }
        Alist() {
                sheaf[0] = new Anode(0);
        }
        void delnode(Anode* i) {
                add(i->prev, i->next);
                delete(i);
                sheaf.erase(i->id);
        }
        void clear() {
                while (sheaf.size())
                        delnode(sheaf.begin()->second);
        }
        int size() {
                return sheaf.size() - 1;
        }
        void insprev(int a, int b, int val) {
                if (sheaf.find(a) == sheaf.end()) {
                        sheaf[a] = new Anode(a, val);
                } else
                        sheaf[a]->val = val;
                if (sheaf.find(b) == sheaf.end()) {
                        sheaf[b] = new Anode(b);
                }
                add(sheaf[a], sheaf[b]);
        }
        void insnext(int a, int b, int val) {
                insprev(a, b, val);
                Aswap(sheaf[a], sheaf[b]);
        }
        int count(int val) {
                Anode* cur = begin();
                int res = 0;
                while (cur) {
                        if (cur->val == val) {
                                ++res;
                                cur->check = 1;
                        }
                        cur = cur->next;
                }
                return res;
        }
        Anode* scan(vector<int> v) {
                int minf = size() + 1;
                for (int i = 0; i < v.size(); ++i)
                        insprev(i + minf, (i + 1 < v.size() ? i + minf + 1 : minf), v[i]);
                if (v.size()) {
                        v.clear();
                        return sheaf[minf];
                }
                return end();
        }
        void print() {
                for (Anode* cur = begin(); cur != end(); cur = cur->next)
                        printf("%d ", cur->val);
        }
public:
        Anode* operator[] (const int& i) {
                return sheaf[i];
        }
};

vector<int> getv(int n) {
        int a;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
                cin >> a;
                v.push_back(a);
        }
        return v;
}


int main() {
    int n;

        Alist L1;
        cout << "Input the number of entries\n";
        cin >> n;
        cout << "Input nodes of the list one-by-one.\n";
        add(L1.end(), L1.scan(getv(n)));
        for (Anode* i = L1.begin(); i != L1.end(); ) {
                Anode* nextf = i->next;
                if (i->val > 0) isolate(i);
                i = nextf;
        }
        L1.print();
        
        
        L1.clear();
}
