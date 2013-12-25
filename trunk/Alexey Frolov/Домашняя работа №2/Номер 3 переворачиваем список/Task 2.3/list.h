#pragma once

typedef int ElementType;

struct ListElement;
struct List;

typedef ListElement *Position;

List *create();

//вставляем элемент в отсортированный список, соблюдая отсортированность
void insert(List *list, ElementType element);

//вставляем элемент в голову
void insertToHead(List *list, ElementType value);

//ищем в списке элемент, который нужно удалить, и удаляем
void remove(List *list, ElementType element);

//удаляем все элементы списка
void removeList(List *list);

//выводим список
void print(List *list);

//удаляем указатель на первый элемент
void removeHead(List *list);

//возвращаем указатель на голову
ListElement *head(List *list);

//возращаем значение эелемента по указателю
ElementType returnValue(List *list, ListElement *position);

//возвращаем длину списка
int length(List *list);

//возвращаем next для позиции
ListElement *next(List *list, ListElement *position);

//изменение значения определённого элемента
void change(List *list, Position position, ElementType element);
