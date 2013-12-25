#pragma once

typedef int ElementType;

struct ListElement;
struct ListPoint;

typedef ListElement *PositionPoint;

//создание списка
ListPoint *create();


//возвращаем указатель на следующий
ListElement *next(ListPoint *list, ListElement *position);
//В=возвращяем указатель на последний элемент
ListElement *last(ListPoint *list);
//возвращаем указатель на голову
ListElement *head(ListPoint *list);
//возращаем значение эелемента по указателю
ElementType returnValue(ListPoint *list, ListElement *position);
//возвращает ссылку на средний элемент
ListElement *middle(ListPoint *list);


//вставляем элемент в отсортированный список, соблюдая отсортированность
void insert(ListPoint *list, ElementType value, ListElement *position);
//вставляем элемент в голову
void insertToHead(ListPoint *list, ElementType element);


//ищем в списке элемент, который нужно удалить, и удаляем
void remove(ListPoint *list, PositionPoint position);
//удаляем все элементы списка
void removeList(ListPoint *list);
//удаляем указатель на первый элемент
void removeHead(ListPoint *list);
//удаляем список
void deleteList(ListPoint *list);


//выводим список
void printList(ListPoint *list);


//возвращает размерность списка
int sizeOfList(ListPoint *list);