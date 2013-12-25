#include <cstdio>
#include <iostream>                               
#include <algorithm>
using namespace std;

class String
{
private:
	class rbst									// implicit persistent random balanced search tree
	{	
	public:
		char sym;
		int size;								// size of tree
		int links;								// number of links to garbage collection
		rbst *left, *right;
		rbst()
		{
			size = 1, links = 1;
			left = right = NULL;
		}
		rbst(rbst &tree)
		{
			sym = tree.sym;
			size = tree.size;
			links = 1;
			left = tree.left; if (left) left->links++;
			right = tree.right; if (right) right->links++;
		}
		rbst(char _sym)
		{
			sym = _sym;
			size = 1;
			links = 1;
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
			if (left) size += left->size;
			if (right) size += right->size;
		}
		void Merge(rbst *tree, rbst *&result)	// merge two trees with random
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
		void Split(rbst *&x, rbst *&y, int pos)	// split tree by pos
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
	String(char *str)                           // create string from char pointer, O(N)
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
	char *ToCharPointer()                       // create char pointer from string, O(N)
	{
		char *str = new char[symbols ? symbols->size : 0 + 1];
		str[symbols ? symbols->size : 0] = '\0';
		if (symbols) symbols->Write(str);
		return str;
	}
	String operator = (const String &str)       // copy string, O(1)
	{
		if (symbols) symbols->Delete();
		symbols = str.symbols;
		if (symbols) symbols->links++;
		return str;
	}
	String operator + (String str)              // concatenation, O(log N)
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
	int Length()                                // length of string, O(1)
	{
		return symbols ? symbols->size : 0;
	}
	bool Empty()
	{
		return symbols == NULL;
	}
	String Substring(int x, int y)              // substring, O(log N)
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
	bool operator == (String str)               // string comparsion, O(N)
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

int main()
{ 
	String str1("abacaba");
	String str2 = str1;
	str1 += str1;
	printf("%s\n", str1.ToCharPointer());
	printf("%s\n", str2.ToCharPointer());
	str1 = str1.Substring(2, 4);
	printf("%s\n", str1.ToCharPointer());
	return 0;
}