#pragma once

struct NodeOfTree;

typedef int ElementType;
typedef NodeOfTree Tree;

// �������� ������
NodeOfTree *createTree();

//�1 ������� �������� ������ � ������� �����������
void printInAscending(NodeOfTree *mainRoot);

//�2 �������� ������� � ������
void insert(NodeOfTree *&root, ElementType element);

//�3 ��������� ���������
void insertSubTree(NodeOfTree *&root, NodeOfTree *&subroot);

//�4 ����� ��������� ��������
void searchParent(NodeOfTree *&root, ElementType element);

//�5 ����� ������������ ������ ������
void searchGeneralParent(NodeOfTree *root, ElementType element1, ElementType element2);

//�6 ������� ����������� ������� ��������
bool findForElement(NodeOfTree *root, ElementType element);

//�7 �������� ���������
void deleteSudTree(NodeOfTree *&root, NodeOfTree *&subroot);

//�8 �������� �������� �� ������
void deleteElement(NodeOfTree *&root, ElementType value);

// ������� ������
void deleteTree(NodeOfTree *root);

// ������� �������� ������ � ������� ��������
void printInDecreasing(NodeOfTree *mainRoot);

// ���� element � ���������� �� ���� ���������
NodeOfTree *findPointToElement(NodeOfTree *&root, ElementType element);

// ���������� ��������� �� ��������
NodeOfTree *findParent(NodeOfTree *&root, ElementType element);

// ������� ������ ������ � ������� ��� �������� ���������� h
void depth(NodeOfTree *root, ElementType element, int &h);