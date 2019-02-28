
/*
 * Author: Julio Rosario
 * Date: 4/26/17
 * Purpose: The purpose of this class is to implement a double link list class
 *          capable of performing operations, such as inserting at the front and
 *          back with an iterator which a client can use to get the info of the
 *          list.
 */
#ifndef LINKLIST_H_
#define LINKLIST_H_
#include "ListNode.h"
template<class T>
class LinkList
{
private:
	ListNode<T>*first;          //The first element in the list.
	ListNode<T>*last;			//The last element in the list.
	int length;					//The length of the list.

	ListNode<T>* iterator;		//To iterate the list.
	ListNode<T>* store;		    //To reset the list when needed it.
public:

	LinkList();			//constructor.

	//Delete all nodes in the list.
	~LinkList();
	void deleteAll();

	//Copy List
	LinkList(const LinkList&);
	void operator=(const LinkList&);
	void copy(const LinkList&);


	void pushBack(T);		 //Insert a node at the end of the list.
	void pushFront(T);         //Insert a node at the beginning of the list.

	int getLength();		  //Return the length of the list.
	void print();			   //Print all of the values from the list.

	void pointToFront();		//Point the iterator to the first element
	void pointToBack();        //Point the iterator to the last element
	void reset();               //Reset the iterator

    T operator*();   	      //return the info of the iterator.
	void operator++();	      //Walk the pointer forward
	void operator--();        //Walk the pointer backward.
};
#endif //  LIST_H
