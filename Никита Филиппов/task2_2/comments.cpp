
#include "StdAfx.h"
#include <iostream>
#include <fstream>
#include <string>
 

using namespace std;


int i;int State;int len;


std::string s;
std::string ss;


//�������
void DKA(int i){
switch (State)
{
case 1/*������, ������ * */:
	{
		if (s[i]=='*') { cout<<'*'; State=2;} else {cout<<s[i];};
	}break;
case 2 /*������, ������ / */:
	{
		switch(s[i])
		{
		case '/': {cout<<"/ ";State=3;} break; /*�����*/
		case '*': {cout<<'*';} break;
		default: {cout<<s[i];State=1;};break;
		}
	}break;
	case 3/*���, ������ / */:
	{
		if (s[i]=='/') { State=4;} 
	}break;
	case 4 /*���, ������ * */:
	{
		switch(s[i])
		{
		case '*': {State=1;cout<<"/*";} break; /*���� ������*/
		case '/': {State=3;} break;
		default: {State=3;} ;break;
		}
	}break;
}
}



int main()
{
	//��������� �� ����� � ������  s
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
 //���������
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
