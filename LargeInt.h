/*
 * Author: Julio Rosario
 * Date: 4/26/17
 * Purpose: The purpose of this class is to implement a LargeInt class capable of
 *          adding any huge numbers by using  double linkList aggregated object
 */

#ifndef LARGEINT_H_
#define LARGEINT_H_
#include "LinkList.h"
#include "LinkList.cpp"
#include <iostream>
using namespace std;

class LargeInt
{
	private:
		int length;					//Number of element in list.
		LinkList<int> list;

	public:
		LargeInt();		                   //Constructor

		LargeInt operator+(LargeInt&);	    //Add LargeInt
		bool operator==(LargeInt&);          //Compare LargeInt

		friend ostream& operator<<(ostream& out,LargeInt&);	//Output LargeInt
		friend istream& operator>>(istream& in,LargeInt&);  //InputLargeInt
};

#endif /* LARGEINT_H_ */
