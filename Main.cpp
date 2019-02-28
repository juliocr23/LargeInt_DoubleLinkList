/*
 * Author : Julio Rosario
 * Date: 4/26/17
 * Purpose: The purpose of this program is to test the DoubleLink list and LargeInt class
 *          by comparing and prompting the user for two numbers and displaying the addition
 *          of the numbers entered.
 */

#include <iostream>
#include "LargeInt.h"
using namespace std;

int main()
{
	LargeInt a,b,c;

	cout << "Enter an integer: ";
	cin>> a;

	cout << "\nEnter another integer: ";
	cin>> b;

	if(a == b)
		cout << "\nIntegers entered are equal\n";
	else
		cout << "\nIntegers entered are not equal\n";
	c = a+b;

	cout << "\n\nThe sum of " << a << " and " << b << " is " << c;
	return 0;
}
