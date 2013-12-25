#pragma once

typedef int ElementType;

struct ListElement;
struct ListPoint;

typedef ListElement *PositionPoint;

//�������� ������
ListPoint *create();


//���������� ��������� �� ���������
ListElement *next(ListPoint *list, ListElement *position);
//�=���������� ��������� �� ��������� �������
ListElement *last(ListPoint *list);
//���������� ��������� �� ������
ListElement *head(ListPoint *list);
//��������� �������� ��������� �� ���������
ElementType returnValue(ListPoint *list, ListElement *position);
//���������� ������ �� ������� �������
ListElement *middle(ListPoint *list);
//���������� �������� ���������� test
bool returnTest(ListPoint *list, ListElement *position);


//��������� ������� � ��������������� ������, �������� �����������������
void insert(ListPoint *list, ElementType value, ListElement *position);
//��������� ������� � ������
void insertToHead(ListPoint *list, ElementType element);
//�������� �������� ���������� test �� ���������������
void changeTestToTrue(ListPoint *list, PositionPoint position);


//���� � ������ �������, ������� ����� �������, � �������
void remove(ListPoint *list, PositionPoint position);
//������� ��� �������� ������
void removeList(ListPoint *list);
//������� ��������� �� ������ �������
void removeHead(ListPoint *list);
//������� ������
void deleteList(ListPoint *list);


//������� ������
void printList(ListPoint *list);


//���������� ����������� ������
int sizeOfList(ListPoint *list);

void loop(ListPoint *list, PositionPoint point);