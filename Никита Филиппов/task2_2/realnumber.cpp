// realnumber.cpp: определяет точку входа для консольного приложения.
//
#include "StdAfx.h"
#include <iostream>
#include <fstream>
#include <string>
 

using namespace std;
int State,i;
std::string s;
bool qqq (char b)
{
	return b>='0' && b<='9'; 
}
bool DKA(int i){
	while (i<s.length())
	{
switch (State)
{
case 1://digit(.|E)->
	{
		if (qqq(s[i])) i++; else
		{
			switch (s[i])
			{
			case 'E': {State=3;i++;}break;
			case '.': {State=2;i++;}break; 
			default:return false;break;	
			}
		}
		 
	}break;
case 2:// digitE
	{
		if (qqq(s[i])) i++; else
		{
			if (s[i]=='E') {State=3;i++;} else return false;
		}
	}	break;
case 3://+ - 
	{
		if (s[i]=='+' || s[i]=='-') {State=4;i++;} else State=4;
	}break;
case 4://digit
	{
		if (qqq(s[i])) i++; else return false;
	}
	break;
}
	}
	if (qqq(s[i-1])) return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	State=1;
    std::getline(std::cin, s);
	cout <<"\n";
	if (DKA(0))  cout<< "is real" ; else cout<< "is not real";
	cout <<"\n";

system("pause");
	return 0;
}

