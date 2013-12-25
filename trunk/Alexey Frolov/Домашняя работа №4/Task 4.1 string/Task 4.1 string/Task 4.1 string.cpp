//Task 4.1 string
//Фролов Алексей
#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include "string.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	char strChar[100];
	cout << "Введите строку:" << endl;
	cin.getline(strChar, 100);// считывание strChar

	String *str = strCreate();// создание
	
	str = charToStr(strChar);// преобразование к типу String
	// преобразование к указателю на char также реализовано(в string.cpp), но не нашло применения в данной программе

	cout << "Данная строка преобразованная к типу стринг:" << endl;
	strPrint(str);// вывод строки

	String *cloneStr = strCreate();// создание

	cloneStr = strClone(str);// str2 становится копией str

	cout << "Клон данной строки:" << endl;
	strPrint(cloneStr);
	 
	strAdd(str, cloneStr);// дописывание строки к текущей

	cout << "Соеденили исходную строку с клоном:" << endl;
	strPrint(str);

	cout << endl;

	cout << "Введите вторую строку:" << endl;
	cin.getline(strChar, 100);
	String *str2 = strCreate();
	str2 = charToStr(strChar);
	if (strIsEmpty(str2))// проверка на пустоту(если пустая, то возвращает истину)
		cout << "Строка пустая! (пробел считается за символ)" << endl;
	else
		cout << "Строка не пустая! (пробел считается за символ)" << endl;

	cout << "Длина второй строки:" << endl;
	cout << strLen(str2) << endl;

	int begin = 0;
	int end = 0;
	cout << "Введите номера элементов с какого по какой вы хотите удалить во второй строке:" << endl;
	cin >> begin >> end;
	
	strCut(str2, begin, end);

	cout << "Вторая строка после обработки:\n(если данные были введены некорректно, то удаление подстроки не произойдёт)" << endl;
	strPrint(str2);

	return 0;
}