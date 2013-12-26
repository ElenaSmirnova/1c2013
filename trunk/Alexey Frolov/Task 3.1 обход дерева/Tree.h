#pragma once

struct NodeOfTree;

typedef int ElementType;
typedef NodeOfTree Tree;

// Создание дерева
NodeOfTree *createTree();

//№1 Выводим элементы дерева в порядке возрастания
void printInAscending(NodeOfTree *mainRoot);

//№2 Добавить элемент в дерево
void insert(NodeOfTree *&root, ElementType element);

//№3 Вставляем поддерево
void insertSubTree(NodeOfTree *&root, NodeOfTree *&subroot);

//№4 поиск корневого элемента
void searchParent(NodeOfTree *&root, ElementType element);

//№5 поиск минимального общего предка
void searchGeneralParent(NodeOfTree *root, ElementType element1, ElementType element2);

//№6 Функция проверяющее наличее элемента
bool findForElement(NodeOfTree *root, ElementType element);

//№7 Удаление поддерева
void deleteSudTree(NodeOfTree *&root, NodeOfTree *&subroot);

//№8 Удаление элемента из дерева
void deleteElement(NodeOfTree *&root, ElementType value);

// Удаляем дерево
void deleteTree(NodeOfTree *root);

// Выводим элементы дерева в порядке убывания
void printInDecreasing(NodeOfTree *mainRoot);

// Ищет element и возвращает на него указатель
NodeOfTree *findPointToElement(NodeOfTree *&root, ElementType element);

// Возвращает указатель на родителя
NodeOfTree *findParent(NodeOfTree *&root, ElementType element);

// Считает высоту дерева и передаёт это значение переменной h
void depth(NodeOfTree *root, ElementType element, int &h);