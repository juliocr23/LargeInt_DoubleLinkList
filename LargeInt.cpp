/*
 * Author: Julio Rosario
 *   Date: 4/26/17
 * Purpose: To implement the  LargeInt class.
 */

#include "LargeInt.h"
#include <iostream>
using namespace std;

LargeInt:: LargeInt()
{
	length = 0;
}

istream& operator>>(istream& in, LargeInt& integer)
{
	//Get input from the user and calculate # of digits.
	string temp;
	getline(in,temp);
	integer.length = temp.length();

	// convert char to int and Copy digit by digit backwards
	for (int  j = 0; j<integer.length; j++)
		integer.list.pushFront(temp[j] - '0');

	return in;
}

ostream& operator<<(ostream& out,LargeInt& integer)
{
	integer.list.pointToBack(); //Get front iterator.

	  //Print the list.
	 for(int i  = 0; i<integer.length; i++)
	  {
	     cout <<*integer.list;
	     --integer.list;
	  }

	  integer.list.reset(); //reset iterator.
	return out;
}

bool LargeInt:: operator==(LargeInt& integer)
{
	bool flag  = true;

	 if(length != integer.length)
    	  return false;
      else
      {
    	  //Create front iterators.
    	  list.pointToFront();
    	  integer.list.pointToFront();

		  for(int i = 0; i<length; i++)
		  {
			  //Compare list values
			 if( *list != *integer.list)
			 {
				 flag = false;
				 break;
			 }
			 ++list;
			 ++integer.list;
		  }
      }
	 //Reset iterators.
	 list.reset();
	 integer.list.reset();
	 return flag;
}

/**
   Base case: When the length of both list are the
	         same and the sum of each digit is less than 9. (CHECKED)

   case 2: When  the length of one list is greater than other
	      and the sum of each digit is less than 9.           (CHECKED)

   case 3: When the length of both list are the same and the sum of
           each digit is greater than 9.                       (CHECKED)

   case 4: When the length of one list is greater than other
           and the sum of each digit is greater than 9.       (CHECKED)
*/
LargeInt  LargeInt:: operator+(LargeInt& integer)
{
	LargeInt sum;
	int carry = 0; //The carry of the sum of the two digit.

	//Create Back iterators.
	integer.list.pointToFront();
	list.pointToFront();

	for(int i = 0, j = 0; (i<length || j<integer.length) || carry > 0; i++,j++)
    {
	    int digitSum = 0;			//The sum of each digit.
	    digitSum += carry;          //Add carry to the sum

		if (j<integer.length)
			digitSum += *integer.list;
		if (i< length)
			digitSum += *list;

		if (digitSum > 9)
		{
			digitSum -=10;
			carry = 1;
			sum.list.pushBack(digitSum);
		}
		else
		{
			sum.list.pushBack(digitSum);
			carry = 0;
		}

		//Walk the iterators forward
		++list;
		++integer.list;

		sum.length++;	//Increase the length of LargeInt class.
	}

     //Reset the iterators of the lists.
     list.reset();
     integer.list.reset();

	return sum;
}
