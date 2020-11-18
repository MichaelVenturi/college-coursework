//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing 7-1
    @file ArrayStack.cpp */
#include <cassert>       // For assert
#include "ArrayStack.h"  // Header file
#include <iostream>

using namespace std;

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{
}  // end default constructor

// Copy constructor and destructor are supplied by the compiler

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
	return top < 0;	
}  // end isEmpty

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
	//bool result = false;	
	if (top < MAX_STACK - 1)  // Does stack have room for newEntry?
	{
		top++;
		items[top] = newEntry;
		//cout << "Push successful\n";
		return true;
	}  // end if
	//cout << "Push failed\n";
	return false;
}  // end push


template<class ItemType>
bool ArrayStack<ItemType>::pop()
{
	//bool result = false;
	if (!isEmpty())
	{
		top--;
		//cout << "Pop successful\n";
		return true;
	}  // end if
	//cout << "Pop failed\n";
	return false;
}  // end pop


template<class ItemType> 
ItemType ArrayStack<ItemType>::peek() const
{
	assert(!isEmpty());  // Enforce precondition
   
	// Stack is not empty; return top
	return items[top];
}  // end peek
// End of implementation file.

// return if stack is full
template<class ItemType>
bool ArrayStack<ItemType>::isFull() const {
	return (top + 1) >= MAX_STACK;
}

// return if item is in stack
template<class ItemType>
bool ArrayStack<ItemType>::isHere(const ItemType& item) {
	for (int i = 0; i <= top; i++) {
		if (items[i] == item) {
			return true;
		}
	}
	return false;
}

