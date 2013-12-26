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

	if (!findForElement(root, element)) // ��������� ������� �������� ��������
		return;

	if (element < root->value)
		deleteElement(root->leftChild, element);
	else if (element > root->value)
		deleteElement(root->rightChild, element);
	else if (root->leftChild == nullptr && root->rightChild == nullptr) // ��������� ������� ������� � � ���� ��� �����
	{
		delete root;
		root = nullptr;
	} 
	else if (root->leftChild == nullptr) // � �������� ��� ������ ������
	{
		NodeOfTree *temp = root; 
		root = root->rightChild; // "��������� ������"
		delete temp;
	}
	else if (root->rightChild == nullptr) // � �������� ��� ������ ������
	{
		NodeOfTree *temp = root; 
		root = root->leftChild; // "��������� �����"
		delete temp;
	}
	else // � �������� ������������ ��� ������
	{
		NodeOfTree *temp = root->rightChild; // ������� � ������� ������

		if (temp->leftChild == nullptr) // ���� � ������� ������ ��� ������ ����
		{
			int element = temp->value;

			deleteElement(temp, temp->value);
			root->value = element; // �������� ���������� ���� �������� ������� ������, ������ ��� ��� � ������� �������
		}
		else // ���� � ������� ������ ���� ����� ������
		{
			while (temp->leftChild->leftChild != nullptr) // ��� �� ����� �����
				temp = temp->leftChild;

			int element = temp->leftChild->value;

			deleteElement(temp, temp->leftChild->value);
			root->value = element; // �������� ���������� ���� �������� ���������� ����� ��������, ������ ��� ��� � ������� �������
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
	if (!findForElement(root, element)) // ���� � ������ ��� 
	{
		cout << "������ �� ������" << endl;
		return;
	}

	// ������� � ������ 100% ����, ������� ��������� ������� ����� �� ����� ��������
	if (root->value == element) // ���� �������� ���� � ���� �������
	{
		cout << root->value;
		return;
	}

	if (root->leftChild == nullptr) // ���� � ���� ��� ������ ������
	{
		if (root->rightChild->value == element) 
		{
			cout << root->value;
			return;
		}
		else
			searchParent(root->rightChild, element); // ��� �������
	}
	else if (root->rightChild == nullptr) // ���� � ���� ��� ������� ������
	{
		if (root->leftChild->value == element)
		{
			cout << root->value;
			return;
		}
		else
			searchParent(root->leftChild, element); // ��� ������
	}
	else // ���� � ���� ���� ��� ������, �� ������� ���� �� ���� ����������� � ����������� �� ��������
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
	// ������� � ������ 100% ����, ������� ��������� ������� ����� �� ����� ��������
	if (root->value == element) // ���� �������� ���� � ���� �������
		return root;

	if (root->leftChild == nullptr) // ���� � ���� ��� ������ ������
	{
		if (root->rightChild->value == element) 
			return root;
		else
			findParent(root->rightChild, element); // ��� �������
	}
	else if (root->rightChild == nullptr) // ���� � ���� ��� ������� ������
	{
		if (root->leftChild->value == element)
			return root;
		else
			findParent(root->leftChild, element); // ��� ������
	}
	else // ���� � ���� ���� ��� ������, �� ������� ���� �� ���� ����������� � ����������� �� ��������
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
	// ������� � ������ 100% ����, ������� ��������� ������� ����� �� ����� ��������
	if (root->value == element) // ���� �������� ���� � ���� �������
		return root;

	if (root->leftChild == nullptr) // ���� � ���� ��� ������ ������
	{
		if (root->rightChild->value == element) 
			return root->rightChild;
		else
			findPointToElement(root->rightChild, element); // ��� �������
	}
	else if (root->rightChild == nullptr) // ���� � ���� ��� ������� ������
	{
		if (root->leftChild->value == element)
			return root->leftChild;
		else
			findPointToElement(root->leftChild, element); // ��� ������
	}
	else // ���� � ���� ���� ��� ������, �� ������� ���� �� ���� ����������� � ����������� �� ��������
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
	// ���������� ���� �� �������� �������, ���������� ��� ���� k
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
	// ��������� ������
	int h1 = 0;
	depth(root, element1, h1);
	int h2 = 0;
	depth(root, element2, h2);

	// ������ ��������� �� ������ ��������
	NodeOfTree *element1Point = findPointToElement(root, element1);
	NodeOfTree *element2Point = findPointToElement(root, element2);

	// ���������� ����������� �� ������ ������� ����� �� ������, ���� �� ����� ������� ����� �������
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