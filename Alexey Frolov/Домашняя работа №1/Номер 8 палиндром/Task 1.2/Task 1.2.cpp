//Фролов Алексей
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string bay;
	getline(cin, bay);
	
	string temp = bay;
	reverse(bay.begin(), bay.end());
	if (temp == bay)
		cout << "yes" << endl;
	else 
		cout << "no" << endl;

	int end = 0;
	cout << "Enter any key to continue:" << endl;
	cin >> end;
	return 0;
}

