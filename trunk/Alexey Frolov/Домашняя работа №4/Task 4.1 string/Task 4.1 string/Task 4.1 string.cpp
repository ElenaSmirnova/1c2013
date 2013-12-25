//Task 4.1 string
//������ �������
#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include "string.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	char strChar[100];
	cout << "������� ������:" << endl;
	cin.getline(strChar, 100);// ���������� strChar

	String *str = strCreate();// ��������
	
	str = charToStr(strChar);// �������������� � ���� String
	// �������������� � ��������� �� char ����� �����������(� string.cpp), �� �� ����� ���������� � ������ ���������

	cout << "������ ������ ��������������� � ���� ������:" << endl;
	strPrint(str);// ����� ������

	String *cloneStr = strCreate();// ��������

	cloneStr = strClone(str);// str2 ���������� ������ str

	cout << "���� ������ ������:" << endl;
	strPrint(cloneStr);
	 
	strAdd(str, cloneStr);// ����������� ������ � �������

	cout << "��������� �������� ������ � ������:" << endl;
	strPrint(str);

	cout << endl;

	cout << "������� ������ ������:" << endl;
	cin.getline(strChar, 100);
	String *str2 = strCreate();
	str2 = charToStr(strChar);
	if (strIsEmpty(str2))// �������� �� �������(���� ������, �� ���������� ������)
		cout << "������ ������! (������ ��������� �� ������)" << endl;
	else
		cout << "������ �� ������! (������ ��������� �� ������)" << endl;

	cout << "����� ������ ������:" << endl;
	cout << strLen(str2) << endl;

	int begin = 0;
	int end = 0;
	cout << "������� ������ ��������� � ������ �� ����� �� ������ ������� �� ������ ������:" << endl;
	cin >> begin >> end;
	
	strCut(str2, begin, end);

	cout << "������ ������ ����� ���������:\n(���� ������ ���� ������� �����������, �� �������� ��������� �� ���������)" << endl;
	strPrint(str2);

	return 0;
}