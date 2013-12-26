#include <cstdio>
#include <iostream>                              
#include <algorithm>
using namespace std;

const int maxHash = 1e6 + 3;
int power(int n) // 257^n mod 1e6+3
{
        int res = 1, a = 257;
        while (n)
        {
                if (n % 2 == 1) res = (long long)res * a % maxHash;
                a = (long long)a * a % maxHash;
                n /= 2;
        }
        return res;
}

// String class

class String
{
private:
        class rbst                                                      
        {      
        public:
                char sym;
                int size;      
                int links;      
                int hash;
                rbst *left, *right;
                rbst()
                {
                        size = 1, links = 1;
                        left = right = NULL;
                        hash = 0;
                }
                rbst(rbst &tree)
                {
                        sym = tree.sym;
                        size = tree.size;
                        hash = tree.hash;
                        links = 1;
                        left = tree.left; if (left) left->links++;
                        right = tree.right; if (right) right->links++;
                }
                rbst(char _sym)
                {
                        sym = _sym;
                        size = 1;
                        links = 1;
                        hash = (unsigned int)_sym;
                        left = right = NULL;
                }
                void Delete()
                {
                        links--;
                        if (links == 0) delete this;
                }
                ~rbst()
                {
                        if (left) left->Delete();
                        if (right) right->Delete();
                }
                void Write(char *str)
                {
                        str[left ? left->size : 0] = sym;
                        if (left != NULL) left->Write(str);
                        if (right != NULL) right->Write(str + (left ? left->size : 0) + 1);
                }
                void Update()
                {
                        size = 1;
                        hash = power(left ? left->size : 0) * (unsigned int)sym % maxHash;
                        if (left) size += left->size, hash = (hash + left->hash) % maxHash;
                        if (right) size += right->size, hash = (hash + (long long) power(left ? left->size + 1 : 1) * right->hash) % maxHash;
                }
                void Merge(rbst *tree, rbst *&result)
                {
                        if (tree == NULL) result = this, result->links++;
                        else if ((rand() * RAND_MAX + rand()) % (size + tree->size) < size)
                        {                    
                                result = new rbst(*this);
                                if (result->right) result->right->links--, result->right = NULL;
                                if (right) right->Merge(tree, result->right);
                                else result->right = tree, result->right->links++;
                                result->Update();
                        }
                        else
                        {
                                result = new rbst(*tree);
                                if (result->left) result->left->links--, result->left = NULL;
                                if (tree->left) Merge(tree->left, result->left);
                                else result->left = this, result->left->links++;
                                result->Update();
                        }
                }
                void Split(rbst *&x, rbst *&y, int pos)
                {
                        if (pos <= (left ? left->size : 0))
                        {              
                                y = new rbst(*this);
                                if (y->left) y->left->links--, y->left = NULL;
                                if (left) left->Split(x, y->left, pos);
                                else y->left = x = NULL;
                                y->Update();
                        }
                        else
                        {
                                x = new rbst(*this);
                                if (x->right) x->right->links--, x->right = NULL;
                                if (right) right->Split(x->right, y, pos - (left ? left->size : 0) - 1);
                                else x->right = y = NULL;
                                x->Update();
                        }
                }
        } *symbols;
public:
        String()
        {
                symbols = NULL;
        }
        String(char str)
        {
                symbols = new rbst(str);
        }
        String(const String &str)
        {
                symbols = str.symbols;
                if (symbols) symbols->links++;
        }
        String(char *str)                  
        {
                symbols = NULL;
                for (int i = 0; str[i]; i++)
                        if (symbols)
                        {
                                rbst *symbols2 = NULL, *newsym = new rbst(str[i]);
                                symbols->Merge(newsym, symbols2);
                                newsym->Delete();
                                if (symbols) symbols->Delete();
                                symbols = symbols2;
                        }
                        else symbols = new rbst(str[i]);
        }
        int Hash()
        {
                return symbols == NULL ? 0 : symbols->hash;
        }
        String(const char *str)
        {
                symbols = NULL;
                for (int i = 0; str[i]; i++)
                        if (symbols)
                        {
                                rbst *symbols2 = NULL, *newsym = new rbst(str[i]);
                                symbols->Merge(newsym, symbols2);
                                newsym->Delete();
                                if (symbols) symbols->Delete();
                                symbols = symbols2;
                        }
                        else symbols = new rbst(str[i]);
        }
        char *ToCharPointer()                  
        {
                char *str = new char[(symbols ? symbols->size : 0) + 1];
                str[symbols ? symbols->size : 0] = '\0';
                if (symbols) symbols->Write(str);
                return str;
        }
        String operator = (const String &str)
        {
                if (symbols) symbols->Delete();
                symbols = str.symbols;
                if (symbols) symbols->links++;
                return str;
        }
        String operator + (String str)    
        {
                if (symbols == NULL) return str;
                else
                {
                        String res;
                        symbols->Merge(str.symbols, res.symbols);
                        return res;
                }
        }
        String Clone()
        {
                return *this;
        }
        int Length()                    
        {
                return symbols ? symbols->size : 0;
        }
        bool Empty()
        {
                return symbols == NULL;
        }
        String Substring(int x, int y)          
        {
                String res;
                if (symbols == NULL) return res;
                rbst *left = NULL, *midright = NULL, *middle = NULL, *right = NULL;
                symbols->Split(left, midright, x);
                if (midright) midright->Split(middle, right, y - x);
                else middle = right = NULL;
                if (left) left->Delete();
                if (right) right->Delete();
                if (midright) midright->Delete();
                res.symbols = middle;
        return res;
        }
        ~String()
        {
                if (symbols) symbols->Delete();
        }
        void operator += (String str)
        {
                rbst *symbols2 = NULL;
                if (symbols) symbols->Merge(str.symbols, symbols2);
                else symbols2 = str.symbols, symbols2->links++;
                if (symbols) symbols->Delete();
                symbols = symbols2;
        }
        bool operator == (String str)        
        {
                char *str1 = ToCharPointer();
                char *str2 = str.ToCharPointer();
                for (int i = 0; str1[i] || str2[i]; i++)
                        if (str1[i] != str2[i])
                        {
                                delete[] str1;
                                delete[] str2;
                                return false;
                        }
                delete[] str1;
                delete[] str2;
                return true;
        }
        bool operator != (String str)
        {
                return !(*this == str);
        }
};
                               
int maxLength = 0, sumLength = 0, loadFactor = 0, maxLengthHash = 0, numOfEmptyCells = 0;

struct List
{
        List *next;
        pair<String, int> data;
};

List *hashTable[maxHash];
int length[maxHash];
char str[1000000];
char str2[1000000];

bool add(List *l, String &str) // add element to hash table if it was in table
{
        if (l == NULL)
                return false;
        else if (l->data.first == str)
        {
                l->data.second++;        
                return true;
        }
        else return add(l->next, str);
}

int main()
{
        printf("print \"#\" in the end of input");

        freopen("output.txt", "w", stdout);        
                numOfEmptyCells = maxHash;
        while (gets(str))
        {
                int n;
                for (int i = 0; str[i]; i++)
                {        
                        n = 0;
                        while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t') str2[n++] = str[i++];
                        str2[n] = 0;
                        if (n == 0) continue;
                        if (n == 1 && str2[0] == '#') goto NEXT;
                        String s(str2);
                        if (hashTable[s.Hash()] == NULL) loadFactor++, numOfEmptyCells--;
                        if (!add(hashTable[s.Hash()], s))
                        {
                                length[s.Hash()]++, sumLength++;
                                if (length[s.Hash()] > maxLength) maxLength = length[s.Hash()], maxLengthHash = s.Hash();
                                List *l = new List();
                                l->data = make_pair(s, 1);
                                l->next = hashTable[s.Hash()];
                                hashTable[s.Hash()] = l;
                        }
                }
        }
                                       
    NEXT:printf("load factor - %.6lf\n", (double)loadFactor / maxHash);
        printf("medium length - %.6lf\n", (double)sumLength / maxHash);
        printf("maximum length - %d\n", maxLength);
        for (List *l = hashTable[maxLengthHash]; l; l = l->next)
        {
                char *str = l->data.first.ToCharPointer();
                printf("\"%s\"\n", str);
                delete[] str;
        }
        printf("number of words - %d\n", sumLength);
        printf("number of empty cells - %d\n", numOfEmptyCells);
        for (int i = 0; i < maxHash; i++)
                while (hashTable[i])
                {
                        char *str = hashTable[i]->data.first.ToCharPointer();
                        printf("\"%s\" - %d\n", str, hashTable[i]->data.second);  
                        delete[] str;
                        List *l = hashTable[i]->next;
                        delete hashTable[i];
                        hashTable[i] = l;
                }

        return 0;
}

