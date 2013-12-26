// Task 3.1 ����� ������
//������ �������
#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include "Tree.h"

using namespace std;

// ���������� �������� �������
void go(int n, Tree *&tree);

// ����� �������
void reference();

int main()
{
	int n = 0;
    setlocale(LC_ALL,"rus");

	Tree *tree = createTree();
	cout << "�������� ������ ������:" << endl;

	reference();// �������

    do
	{
		cout << "������� ����� �������:" << endl;
        cin >> n;
        go(n, tree);
    }
	while (n);

	return 0;
}

void go(int n, Tree *&tree)
{
    switch (n)
    {
		case -1: // ����� �������
			{
				reference(); 
				break;
			}
		case 0: break; // ��������� ������
		case 1: // ����� ������ � ������������ �������
			{
				cout << "������ ������ � ������������ �������:" << endl;
				printInAscending(tree);
				cout << endl;

				break;
			}
		case 2: // ������� ��������
		{
			int number = 0;
			cout << "������� �������, ������� ������ ��������:" << endl;// ���� ������� ��� ���� � ������, �� ��������� ������������� ������
			cin >> number;
			insert(tree, number);

			break;
		}
		case 3: // ������� ���������
		{
			Tree *subTree = createTree();

			cin.ignore(1);
			char str[1000];
			cout << "������� ��������, �� ������� ������� ������, ������� �� ������ ��������:" << endl;
			cin.getline(str, 1000); // ���� ����� ������� ��������, ������� ��� ���� � ������, �� ��������� �� �������������
			int i = 0;
			while (i < strlen(str)) // ����� �������� � subTree
			{
				if (str[i] != ' ')
					insert(subTree, str[i] - '0'); // (str[i] - '0') ���������� char � int
				i++;
			}

			insertSubTree(tree, subTree); // ���������� �������

			deleteTree(subTree);

			break;
		}
		case 4: // ����� ��������� ����
		{
			int element = 0;
			cout << "������� �������, �������� ���� �������� ������ �����:" << endl;
			cin >> element; // ���� ����� ����� ������ ����� ������, �� ��������� ����� ���
			cout << "�������� ����: ";
			searchParent(tree, element);
			cout << endl;

			break;
		}
		case 5: // ���������� ����������� ������ ������ ���� ������
		{
			int element1 = 0;
			int element2 = 0;
			cout << "������� ��������, ������ ������ ������� ������ �����:" << endl;
			cin >> element1 >> element2;

			searchGeneralParent(tree, element1, element2);

			break;
		}
		case 6: // ����� ��������
		{
			int element = 0;
			cout << "������� �������, ������� ������ �����:" << endl;
			cin >> element;
			if (findForElement(tree, element))
				cout << "������ ������� ������ � ������" << endl;
			else
				cout << "������� �������� �� ����������" << endl;

			break;
		}
		case 7: // �������� ���������
		{
			Tree *subTree = createTree();

			cin.ignore(1);
			char str[1000];
			cout << "������� ��������, �� ������� ������� ������, ������� �� ������ �������:" << endl;
			cin.getline(str, 1000); // ���� ����� ������� ��������, ������� ��� � ������, �� ��������� �� �������������
			int i = 0;
			while (i < strlen(str))// ����� �������� � subTree
			{
				if (str[i] != ' ')
					insert(subTree, str[i] - '0'); // (str[i] - '0') ���������� char � int
				i++;
			}

			insertSubTree(tree, subTree); // ���������� �������

			deleteTree(subTree);

			break;
		}
		case 8: // �������� ��������
		{
			int number = 0;
			cout << "������� �������, ������� ������ �������:" << endl;
			cin >> number;
			
			deleteElement(tree, number);

			break;
		}
        default: 
		{
			cout << "����� ������������ ����� ������. ��������� ����. " << endl;
			break;
		}
    }
}

void reference()
{
	cout << "-1 - ����� ������� ��� ���� ���������" << endl;
	cout << "0 - ��������� ������" << endl;
	cout << "1 - ����� ������ � ������������ �������:" << endl;
	cout << "2 - ������� ������ ��������" << endl;
	cout << "3 - ������� ���������" << endl;
	cout << "4 - ���������� ��������� ��������" << endl;
	cout << "5 - ���������� ������ ������" << endl;
	cout << "6 - ����� ��������" << endl;
	cout << "7 - �������� ���������" << endl;
	cout << "8 - �������� ��������" << endl;
	cout << "9 - ����� ���� �� ����� � ������� ���� 0" << endl;
}