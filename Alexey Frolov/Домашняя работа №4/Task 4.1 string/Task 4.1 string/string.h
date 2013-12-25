#pragma once

struct String
{
	char *begin;
	int length;
};

// создание строки
String* strCreate();

// строку типа char преобразовывает в String
String* charToStr(char *a);

// удаление строки
void strDelete(String *&str);

// возвращает копию исходной строки
String* strClone(String *str);

// добавление строки
void strAdd(String *&str, String *&add);

// проверка равенства строк
bool strIsEqual(String *str1, String *str2);

// проверка равенства строк
bool strIsEqual(String *str1, char *str2);

// проверка строки на пустоту
bool strIsEmpty(String *str);

// считает длину строки
int strLen(String *str);

// удаляет подстроку из исходной строки
void strCut(String *&str, int begin, int end);

// преобразует String в char
char* strToChar(String *str);

// выводит строку
void strPrint(String *str);