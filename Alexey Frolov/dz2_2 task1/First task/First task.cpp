#include "stdafx.h"
#include <iostream>
using namespace std;

enum condition
{
	waitFirstDigit,	waitDigitIntegerPartOrPointOrEOrExit, waitDigitFractionalPart, waitDigitFractionalPartOrEOrExit,
	waitDigitPowerOrSign, waitDigitPowerAfterSign, waitDigitPowerOrExit, errorState, endState

};
enum element
{
	point, e, digit, sign, error, finish
};

element nextChar()
{
	char ch = 0;
	cin >> ch;
	if (ch >= '0' && ch <= '9')
		return digit;
	if (ch == '.')
		return point;
	if (ch == 'E')
		return e;
	if (ch == '+' || ch == '-')
		return sign;
	if (ch == ' ' || ch == '\n' || ch == '\t')
		return finish;
	return error;
}

bool isNumber()
{
	element ch = error;
	condition state = waitFirstDigit;
	while (true)
	{
		ch = nextChar();
		if (ch == error || ch == finish)
			break;

		switch (state)
		{
		case waitFirstDigit:
			if (ch == digit)
				state = waitDigitIntegerPartOrPointOrEOrExit;
			else
				state = errorState;
			break;

		case waitDigitIntegerPartOrPointOrEOrExit:
			switch (ch)
			{
			case point:
				state = waitDigitFractionalPart;
				break;
			case e:
				state = waitDigitPowerOrSign;
				break;
			default:
				if (ch != digit)
					state = errorState;
			}
			break;

		case waitDigitFractionalPart:
			if (ch == digit)
				state = waitDigitFractionalPartOrEOrExit;
			else
				state = errorState;
			break;

		case waitDigitFractionalPartOrEOrExit:
			if (ch == e)
				state = waitDigitPowerOrSign;
			else if (ch != digit)
				state = errorState;
			break;

		case waitDigitPowerOrSign:
			if (ch == sign)
				state = waitDigitPowerAfterSign;
			else if (ch == digit)
				state = waitDigitPowerOrExit;
			else
				state = errorState;
			break;

		case waitDigitPowerAfterSign:
			if (ch == digit)
				state = waitDigitPowerOrExit;
			else
				state = errorState;
			break;

		case waitDigitPowerOrExit:
			if (ch != finish && ch != digit)
				state = errorState;
			break;

		case errorState:
			return false;
		}
	}

	if (ch == error)
		return false;
	if (state == waitDigitFractionalPartOrEOrExit || state == waitDigitPowerOrExit || state == waitDigitIntegerPartOrPointOrEOrExit)
		return true;
	return false;
}

int main()
{
	cout << "Enter number - digit+ (. digit+)? (E(+ | -)? digit+)?" << endl;
	if (isNumber())
		cout << "Yes, it is number"<< endl;
	else
		cout << "No, it is not number"<< endl;
	return 0;	
}