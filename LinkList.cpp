
/*
 * Author: Julio Rosario
 * Date: 4/26/17
 * Purpose: To implement the class LinkList.
 */
#include "LinkList.h"
#include "iostream"
template<class T>
LinkList<T>::LinkList()
{
	first = 0;
	last = 0;
	length = 0;
	store = 0;
	iterator = 0;
}

template<class T>
LinkList<T>::~LinkList()
{
	deleteAll();
}


template<class T>
LinkList<T>::LinkList(const LinkList& obj)
{
	copy(obj);
}

template<class T>
void LinkList<T>:: operator=(const LinkList& obj)
{
	copy(obj);
}

template<class T>
void LinkList<T>:: pushBack(T item)
{
	//Create new node.
	ListNode<T>* newNode = new ListNode<T>;
	newNode->value = item;
	newNode->next = 0;

	/*
	* If the list is empty create a new node
	* and store the item in new node and
	* let last reference first.
	*/
	if (length == 0)
	{
		first = newNode;
		last  = newNode;
	}
	else{ //Insert element at the back of the list.

		last->next = newNode;
		newNode->back = last;
		last = newNode;
	}
	length++;
}

template<class T>
void LinkList<T>:: pushFront(T item)
{
	//Create new node.
	ListNode<T>* newNode = new ListNode<T>;
	newNode->value = item;
	newNode->next = 0;
	newNode->back = 0;

	if (length == 0)
	{
		first = newNode;
		last  = newNode;
	}
	else{ //Insert element at the beginning of the list.

		newNode->next = first;
		first->back = newNode;
		first = newNode;
	}
	length++;
}

template<class T>
int LinkList<T>::getLength()
{
	return length;
}

template<class T>
void LinkList<T>:: print()
{
	ListNode<T>* traverse = first;

	while(traverse != 0)
	{
	 std:: cout<< traverse->value<< std:: endl;
	  traverse = traverse->next;
	}

}

template<class T>
void LinkList<T>:: deleteAll()
{
	ListNode<T> * traverse = 0;

	while(first != 0)
	{
		traverse = first;
		first = first->next;
		delete traverse;
	}
	last = 0;
	length = 0;
}

template<class T>
void LinkList<T>::copy(const LinkList& obj)
{
	/*
	 * NOTE: I know I could have called function pushBack
	 *       in a while loop. But I want to do it without it
	 *       just for practice.
	 */

	deleteAll();	//Delete all nodes inside the list.

	ListNode<T> *traverse = obj.first;

	while(traverse != 0)
	{
		//Create a new Node
		ListNode<T>* newNode = new ListNode<T>;
		newNode->value = traverse->value;
		newNode->next = 0;

		//If it is the first time
		if(first == 0)
		{
			newNode->back = 0;
			first = newNode;
			last = newNode;
		}
		else
		{
			last->next = newNode;
			newNode->back = last;
			last = newNode;
		}

		traverse = traverse->next;
	}
}

template<class T>
void LinkList<T>:: pointToFront()
{
	iterator = first;
	store = first;
}

template<class T>
void LinkList<T>:: pointToBack()
{
	iterator = last;
	store = last;
}

template<class T>
void LinkList<T>:: reset()
{
	iterator = store;
}

template<class T>
T LinkList<T>:: operator*()
{
	if(iterator!= 0)
		return iterator->value;
	else//Sentinel value indicating that the list is empty.
		return 0;
}
template<class T>
void LinkList<T>:: operator++()
{
	if(iterator->next)
		iterator = iterator->next;
}

template<class T>
void LinkList<T>:: operator--()
{
	if(iterator->back)
	  iterator = iterator->back;
}
