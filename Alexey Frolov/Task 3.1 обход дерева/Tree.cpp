#include "stdafx.h"
#include <iostream>
#include "Tree.h"

using namespace std;

struct NodeOfTree
{
	ElementType value;
	Tree *leftChild;
	Tree *rightChild;
};

NodeOfTree *createTree()
{
	return nullptr;
}

NodeOfTree *createNode(ElementType element)
{
	NodeOfTree *root = new NodeOfTree;
	root->value = element;
	root->leftChild = nullptr;
	root->rightChild = nullptr;
	return root;
}

void insert(NodeOfTree *&root, ElementType element)
{
	if (findForElement(root, element))
		return;

	if (root == nullptr)
		root = createNode(element);
	else if (root->value > element)
		insert(root->leftChild, element);
	else if (root->value < element)
		insert(root->rightChild, element);
}

bool findForElement(NodeOfTree *root, ElementType element)
{
	if (root == nullptr)
		return false;

	if (root->value == element)
		return true;
	else if (root->value > element)
		findForElement(root->leftChild, element);
	else if (root->value < element)
		findForElement(root->rightChild, element);
}

void deleteElement(NodeOfTree *&root, ElementType element) 
{
	if (root == nullptr)
		return;

	if (!findForElement(root, element)) // проверяем наличие искомого элемента
		return;

	if (element < root->value)
		deleteElement(root->leftChild, element);
	else if (element > root->value)
		deleteElement(root->rightChild, element);
	else if (root->leftChild == nullptr && root->rightChild == nullptr) // встретили искомый элемент и у него нет детей
	{
		delete root;
		root = nullptr;
	} 
	else if (root->leftChild == nullptr) // у элемента нет левого ребёнка
	{
		NodeOfTree *temp = root; 
		root = root->rightChild; // "сдвинемся вправо"
		delete temp;
	}
	else if (root->rightChild == nullptr) // у элемента нет првого ребёнка
	{
		NodeOfTree *temp = root; 
		root = root->leftChild; // "сдвинемся влево"
		delete temp;
	}
	else // у элемента присутствуют оба ребёнка
	{
		NodeOfTree *temp = root->rightChild; // перейдём к правому ребёнку

		if (temp->leftChild == nullptr) // если у правого ребёнка нет левого сына
		{
			int element = temp->value;

			deleteElement(temp, temp->value);
			root->value = element; // присвоим удаляемому узлу значение правого ребёнка, удалив его уже с помощью функции
		}
		else // если у правого ребёнка есть левый ребёнок
		{
			while (temp->leftChild->leftChild != nullptr) // идём до упора влево
				temp = temp->leftChild;

			int element = temp->leftChild->value;

			deleteElement(temp, temp->leftChild->value);
			root->value = element; // присвоим удаляемому узлу значение последнего слева элемента, удалив его уже с помощью функции
		}
	}
}

void printInAscending(NodeOfTree *root)
{
	if (root != nullptr)
	{
		printInAscending(root->leftChild);
		cout << root->value << " ";
		printInAscending(root->rightChild);
	}
}

void printInDecreasing(NodeOfTree *root)
{
	if (root != nullptr)
	{
		printInDecreasing(root->rightChild);
		cout << root->value << " ";
		printInDecreasing(root->leftChild);
	}
}

void deleteTree(NodeOfTree *root)
{
	if (root == nullptr)
	{
		return;
	}

	if (root->leftChild != nullptr)
	{
		deleteTree(root->leftChild);
	}

	if (root->rightChild != nullptr)
	{
		deleteTree(root->rightChild);
	}

	delete root;
}

void deleteSudTree(NodeOfTree *&root, NodeOfTree *&subroot)
{
	if (subroot != nullptr)
	{
		deleteSudTree(root, subroot->leftChild);
		deleteElement(root, subroot->value);
		deleteSudTree(root, subroot->rightChild);
	}
}

void insertSubTree(NodeOfTree *&root, NodeOfTree *&subroot)
{
	if (subroot != nullptr)
	{
		insertSubTree(root, subroot->leftChild);
		insert(root, subroot->value);
		insertSubTree(root, subroot->rightChild);
	}
}

void searchParent(NodeOfTree *&root, ElementType element)
{
	if (!findForElement(root, element)) // если в дереве нет 
	{
		cout << "Корень не найден" << endl;
		return;
	}

	// элемент в дереве 100% есть, поэтому некоторые условия далее мы можем опускать
	if (root->value == element) // если введённый узел и есть искомый
	{
		cout << root->value;
		return;
	}

	if (root->leftChild == nullptr) // если у узла нет левого ребёнка
	{
		if (root->rightChild->value == element) 
		{
			cout << root->value;
			return;
		}
		else
			searchParent(root->rightChild, element); // идём навраво
	}
	else if (root->rightChild == nullptr) // если у узла нет правого ребёнка
	{
		if (root->leftChild->value == element)
		{
			cout << root->value;
			return;
		}
		else
			searchParent(root->leftChild, element); // идём налево
	}
	else // если у узла есть оба ребёнка, то выберем одно из двух направлений в зависимости от элемента
	{
		if (root->leftChild->value == element || root->rightChild->value == element)
		{
			cout << root->value;
			return;
		}
		else if (root->value > element)
			searchParent(root->leftChild, element);
		else if (root->value < element)
			searchParent(root->rightChild, element);
	}
}

NodeOfTree *findParent(NodeOfTree *&root, ElementType element)
{
	// элемент в дереве 100% есть, поэтому некоторые условия далее мы можем опускать
	if (root->value == element) // если введённый узел и есть искомый
		return root;

	if (root->leftChild == nullptr) // если у узла нет левого ребёнка
	{
		if (root->rightChild->value == element) 
			return root;
		else
			findParent(root->rightChild, element); // идём навраво
	}
	else if (root->rightChild == nullptr) // если у узла нет правого ребёнка
	{
		if (root->leftChild->value == element)
			return root;
		else
			findParent(root->leftChild, element); // идём налево
	}
	else // если у узла есть оба ребёнка, то выберем одно из двух направлений в зависимости от элемента
	{
		if (root->leftChild->value == element || root->rightChild->value == element)
			return root;
		else if (root->value > element)
			findParent(root->leftChild, element);
		else if (root->value < element)
			findParent(root->rightChild, element);
	}
}

NodeOfTree *findPointToElement(NodeOfTree *&root, ElementType element)
{
	// элемент в дереве 100% есть, поэтому некоторые условия далее мы можем опускать
	if (root->value == element) // если введённый узел и есть искомый
		return root;

	if (root->leftChild == nullptr) // если у узла нет левого ребёнка
	{
		if (root->rightChild->value == element) 
			return root->rightChild;
		else
			findPointToElement(root->rightChild, element); // идём навраво
	}
	else if (root->rightChild == nullptr) // если у узла нет правого ребёнка
	{
		if (root->leftChild->value == element)
			return root->leftChild;
		else
			findPointToElement(root->leftChild, element); // идём налево
	}
	else // если у узла есть оба ребёнка, то выберем одно из двух направлений в зависимости от элемента
	{
		if (root->leftChild->value == element)
			return root->leftChild;
		else if (root->rightChild->value == element)
			return root->rightChild;
		else if (root->value > element)
			findPointToElement(root->leftChild, element);
		else if (root->value < element)
			findPointToElement(root->rightChild, element);
	}
}

void depth(NodeOfTree *root, ElementType element, int &h)
{
	// спускаемся пока не встретим элемент, увеличивая при этом k
	h++;
	if (root->value == element)
		return ;
	else if (root->value > element)
		depth(root->leftChild, element, h);
	else if (root->value < element)
		depth(root->rightChild, element, h);
}

void searchGeneralParent(NodeOfTree *root, ElementType element1, ElementType element2)
{
	// вычисляем высоты
	int h1 = 0;
	depth(root, element1, h1);
	int h2 = 0;
	depth(root, element2, h2);

	// создаём указатели на данные элементы
	NodeOfTree *element1Point = findPointToElement(root, element1);
	NodeOfTree *element2Point = findPointToElement(root, element2);

	// постепенно подниматься из каждой вершины вверх по дереву, пока не будет найдена общая вершина
	while (h1 != h2)
	{
       if (h1 > h2)
	   {
			element1Point = findParent(root, element1);
			h1--;
	   }
       else
	   {
			element2Point = findParent(root, element2);
			h2--;
	   }
	}

	while (element1Point->value != element2Point->value)
	{
		element1Point = findParent(root, element1);
		element1 = element1Point->value;
		element2Point = findParent(root, element2);
		element2 = element2Point->value;
	}

	cout << element1Point->value << endl;
}