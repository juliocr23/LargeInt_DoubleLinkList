/*
 * ListNode.h
 *
 *  Created on: Apr 10, 2017
 *      Author: julio
 *      Purpose: The Purpose of this structre is to implement a doubleLink List Node.
 */

#ifndef LISTNODE_H_
#define LISTNODE_H_

//Declare a structure for the list.
template <class T>
struct ListNode
{
	T value;
	struct ListNode<T> *next;
	struct ListNode<T>*back;
};

#endif /* LISTNODE_H_ */
