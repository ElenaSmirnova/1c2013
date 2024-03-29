#pragma once

typedef int ElementType;

struct ListElement;
struct List;

typedef ListElement *Position;

List *create();

//��������� ������� � ��������������� ������, �������� �����������������
void insert(List *list, ElementType element);

//��������� ������� � ������
void insertToHead(List *list, ElementType value);

//���� � ������ �������, ������� ����� �������, � �������
void remove(List *list, ElementType element);

//������� ��� �������� ������
void removeList(List *list);

//������� ������
void print(List *list);

//������� ��������� �� ������ �������
void removeHead(List *list);

//���������� ��������� �� ������
ListElement *head(List *list);

//��������� �������� ��������� �� ���������
ElementType returnValue(List *list, ListElement *position);

//���������� ����� ������
int length(List *list);

//���������� next ��� �������
ListElement *next(List *list, ListElement *position);

//��������� �������� ������������ ��������
void change(List *list, Position position, ElementType element);
