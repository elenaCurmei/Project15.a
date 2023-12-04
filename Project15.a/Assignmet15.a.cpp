// Elena Curmei
// CIS 1202 201
// December 3, 2023

#include <iostream>
using namespace std;

//Exception classes

//class to handle invalidCharacterExcpeption
class invalidCharacterExcpeption
{
};

//class to handle invalidRangeException
class invalidRangeException
{
};

//class to handle caseConversionException
class caseConversionException
{
};

//function to find character offset value
char character(char start, int offset)
{
	//find the ascii value of start
	int startAsciiValue = int(start);
	//add the offset to start's ascii value to find the value of target
	int target = startAsciiValue + offset;
	try {
		//if start is not an lower case alphabet or upper case alphabet throw invalidCharacterExcpeption
		if (startAsciiValue < 65 || (startAsciiValue > 90 && startAsciiValue < 97) || startAsciiValue > 122)
		{
			throw invalidCharacterExcpeption();
		}
		//else if target is not lower case alphabet or upper case alphabet throw invalidRangeException
		else if (target < 65 || (target > 90 && target < 97) || target > 122)
		{
			throw invalidRangeException();
		}
		//else if target is lower case and start is upper case or target is upper case and start is lower case then throw caseConversionException
		else if ((target >= 65 && target <= 90 && startAsciiValue >= 95 && startAsciiValue <= 122) || (target >= 95 && target <= 122 && startAsciiValue >= 65 && startAsciiValue <= 90))
		{
			throw caseConversionException();
		}
	}
	//catch all respective expressions and print the message
	catch (invalidCharacterExcpeption exception1)
	{
		cout << "\ninvalidCharacterException " << endl;
		return ' ';
	}
	catch (invalidRangeException exception2)
	{
		cout << "\ninvalidRangeException " << endl;
		return ' ';
	}
	catch (caseConversionException exception3)
	{
		cout << "Cannot make case changes from upper to lower or otherwise. " << endl;
		return ' ';
	}
	//if no exception was catched return the character value of target
	return char(target);
}

int main()
{
	cout << character('a', 1) << endl;
	cout << character('a', -1) << endl;
	cout << character('Z', -1) << endl;
	cout << character('?', 5) << endl;
	cout << character('A', 32) << endl;

}