// Task 3.1 обход дерева
//Фролов Алексей
#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include "Tree.h"

using namespace std;

// анализатор вводимой команды
void go(int n, Tree *&tree);

// вывод справки
void reference();

int main()
{
	int n = 0;
    setlocale(LC_ALL,"rus");

	Tree *tree = createTree();
	cout << "Двоичное дерево поиска:" << endl;

	reference();// справка

    do
	{
		cout << "Введите номер запроса:" << endl;
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
		case -1: // вызов справки
			{
				reference(); 
				break;
			}
		case 0: break; // окончание работы
		case 1: // вывод дерева в симметричном порядке
			{
				cout << "Данное дерево в симметричном порядке:" << endl;
				printInAscending(tree);
				cout << endl;

				break;
			}
		case 2: // вставка элемента
		{
			int number = 0;
			cout << "Введите элемент, который хотите вставить:" << endl;// если элемент уже есть в дереве, то программа проигнорирует запрос
			cin >> number;
			insert(tree, number);

			break;
		}
		case 3: // вставка поддерева
		{
			Tree *subTree = createTree();

			cin.ignore(1);
			char str[1000];
			cout << "Введите элементы, из которых состоит дерево, которое вы хотите вставить:" << endl;
			cin.getline(str, 1000); // если будут введены элементы, которые уже есть в дереве, то программа их проигнорирует
			int i = 0;
			while (i < strlen(str)) // задаём элементы в subTree
			{
				if (str[i] != ' ')
					insert(subTree, str[i] - '0'); // (str[i] - '0') превращает char в int
				i++;
			}

			insertSubTree(tree, subTree); // собственно функция

			deleteTree(subTree);

			break;
		}
		case 4: // поиск корневого узла
		{
			int element = 0;
			cout << "Введите элемент, корневой узел которого хотите найти:" << endl;
			cin >> element; // если будет введён корень всего дерева, то программа вернёт его
			cout << "Корневой узел: ";
			searchParent(tree, element);
			cout << endl;

			break;
		}
		case 5: // нахождение наименьшего общего предка двух вершин
		{
			int element1 = 0;
			int element2 = 0;
			cout << "Введите элементы, общего предка которых хотите найти:" << endl;
			cin >> element1 >> element2;

			searchGeneralParent(tree, element1, element2);

			break;
		}
		case 6: // поиск элемента
		{
			int element = 0;
			cout << "Введите элемент, который хотите найти:" << endl;
			cin >> element;
			if (findForElement(tree, element))
				cout << "Данный элемент найден в дереве" << endl;
			else
				cout << "Данного элемента не обнаружено" << endl;

			break;
		}
		case 7: // удаление поддерева
		{
			Tree *subTree = createTree();

			cin.ignore(1);
			char str[1000];
			cout << "Введите элементы, из которых состоит дерево, которое вы хотите удалить:" << endl;
			cin.getline(str, 1000); // если будут введены элементы, которых нет в дереве, то программа их проигнорирует
			int i = 0;
			while (i < strlen(str))// задаём элементы в subTree
			{
				if (str[i] != ' ')
					insert(subTree, str[i] - '0'); // (str[i] - '0') превращает char в int
				i++;
			}

			insertSubTree(tree, subTree); // собственно функция

			deleteTree(subTree);

			break;
		}
		case 8: // удаление элемента
		{
			int number = 0;
			cout << "Введите элемент, который хотите удалить:" << endl;
			cin >> number;
			
			deleteElement(tree, number);

			break;
		}
        default: 
		{
			cout << "Введён некорректный номер задачи. Повторите ввод. " << endl;
			break;
		}
    }
}

void reference()
{
	cout << "-1 - снова вывести это окно подсказки" << endl;
	cout << "0 - закончить работу" << endl;
	cout << "1 - обход дерева в симметричном порядке:" << endl;
	cout << "2 - вставка нового элемента" << endl;
	cout << "3 - вставка поддерева" << endl;
	cout << "4 - нахождение корневого элемента" << endl;
	cout << "5 - нахождение общего предка" << endl;
	cout << "6 - поиск элемента" << endl;
	cout << "7 - удаление поддерева" << endl;
	cout << "8 - удаление элемента" << endl;
	cout << "9 - найти путь от корня к листьям веса 0" << endl;
}