#include "StdAfx.h"
#include <iostream>
#include <fstream>
#include <string>
 

using namespace std;


int i;int State;int len;


std::string s;
std::string ss;


//автомат
void DKA(int i){
switch (State)
{
case 1/*Внутри, ожидаю * */:
	{
		if (s[i]=='*') { cout<<'*'; State=2;} else {cout<<s[i];};
	}break;
case 2 /*Внутри, ожидаю / */:
	{
		switch(s[i])
		{
		case '/': {cout<<"/ ";State=3;} break; /*выход*/
		case '*': {cout<<'*';} break;
		default: {cout<<s[i];State=1;};break;
		}
	}break;
	case 3/*Вне, ожидаю / */:
	{
		if (s[i]=='/') { State=4;} 
	}break;
	case 4 /*Вне, ожидаю * */:
	{
		switch(s[i])
		{
		case '*': {State=1;cout<<"/*";} break; /*вход внутрь*/
		case '/': {State=3;} break;
		default: {State=3;} ;break;
		}
	}break;
}
}



int main()
{
	//считываем из файла в строку  s
ifstream test("test.txt");           

ifstream fin("test.txt");
while (!test.eof())                         
    {
        if (test.eof()) break;              
        test>>ss;  
		s=s+" "+ss;
    }                                          
test.close();    





 setlocale(LC_CTYPE, "");
 //программа
 State=3;
 i=0;
 len=s.length();
		for (i=0;i<len;i++)
		{
			
			DKA(i);
		}
		cout <<"\n";
		
system("pause");
        return 0;
}
