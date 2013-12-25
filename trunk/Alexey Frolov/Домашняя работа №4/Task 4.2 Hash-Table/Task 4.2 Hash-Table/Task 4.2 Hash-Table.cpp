//Hash-table
//������ �������
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "list.h"
#include "strings.h"
#include "hash.h"
#include <locale.h>

using namespace std;

void wordCorrect(String *string)
{
	if (string->begin[0] >= 'A' && string->begin[0] <= 'Z')
		string->begin[0] = string->begin[0] + 32;

	if (string->begin[string->length - 1] < 'A' || 
	   string->begin[string->length - 1] > 'z' || 
	   (string->begin[string->length - 1] > 'Z' && string->begin[string->length - 1] < 'a'))
			strCut(string, 0, string->length - 1);
}
	
int main()
{
	setlocale (LC_ALL, "Russian");

	cout << "��������� ������� ������� ������������� ���� � ������" << endl;
	ifstream in ("input.txt");
	
	if (!in)
	{
		cout << "������ ������ �� �����!" << endl;
		int n = 0;
		cin >> n;
		return 1;
	}

	const int sizeOfHash = 100;
	List **hashTable = hashCreate(sizeOfHash);

	String *str = strCreate();
	

	while (!in.eof())
	{
		char *a = new char [100];
		in >> a;
		strDelete(str);
		delete str;
		str = charToStr(a);
		wordCorrect(str);
		hashAdd(str, hashTable, sizeOfHash);
	}

	hashPrint(hashTable, sizeOfHash);

	cout << endl << "������������ ����� �������: " << hashMaxLength(hashTable, sizeOfHash)
		<< endl << "������� ����� �������: " << hashMeanLength(hashTable, sizeOfHash)
		<< endl << "����� ����: " << hashWordAmount(hashTable, sizeOfHash) 
		<< endl << "load factor: " << hashLoadFactor(hashTable, sizeOfHash)
		<< endl << "���������� ������ �����: " << hashEmptyValues(hashTable, sizeOfHash) << endl;
	
	strDelete(str);
	delete str;

	hashDelete(hashTable, sizeOfHash);

	return 0;
}