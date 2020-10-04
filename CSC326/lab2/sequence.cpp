#include "sequence.h"
#include <iostream>
#include <cassert>


using namespace std;
// constructors
// default
template <class value_type>
sequence<value_type>::sequence() {
	capacity = 10;
	num_used = 0;
	data = new value_type[10];
}
// argument
template <class value_type>
sequence<value_type>::sequence(int size) {
	capacity = size;
	num_used = 0;
	data = new value_type[size];
}

//destructor
template <class value_type>
sequence<value_type>::~sequence() {
	delete[] data;
}

// is full
template <class value_type>
bool sequence<value_type>::full() const {
	if (num_used == capacity) {
		return true;
	}
	return false;
}
// is empty
template <class value_type>
bool sequence<value_type>::empty() const {
	if (num_used == 0) {
		return true;
	}
	return false;
}
// return capacity
template <class value_type>
int sequence<value_type>::max_capacity() const {
	return capacity;
}
// return num used
template <class value_type>
int sequence<value_type>::num_element() const {
	return num_used;
}

// return element at given position
template <class value_type>
value_type sequence<value_type>::at(int position) const {
	// checks that the input position isn't negative/has a value in it
	assert(position < num_used&& position >= 0);

	return data[position];
}

// overwrite an element
template <class value_type>
void sequence<value_type>::set(const value_type& entry, int position) {	
	// checks that the input position isn't negative/has a value in it
	assert(position < num_used&& position >= 0);

	data[position] = entry;
	cout << "Element overwritten\n";
}

// insert an element
template <class value_type>
void sequence<value_type>::insert(const value_type& entry, int position) {
	// checks that the input position isn't negative/has a value in it
	assert(position < num_used&& position >= 0);

	// Expands container if full
	if (full()) { expand(); }

	// pushes all values from the position forwards
	for (int i = num_used - 1; i >= position; i--) {
		data[i + 1] = data[i];
	}
	data[position] = entry;
	num_used++;
	cout << "Element inserted\n";
}

// add element to end of array
template <class value_type>
void sequence<value_type>::push_back(const value_type& entry) {

	//expands container if full
	if (full()) { expand(); }

	data[num_used] = entry;
	num_used++;
	cout << "Element added\n";
}

// remove an element from a position
template <class value_type>
void sequence<value_type>::remove_current(int position) {
	// checks that the input position isn't negative/has a value in it
	assert(position < num_used&& position >= 0);

	// removes the value and pushes the following values backwards
	for (int i = position; i < num_used; i++) {
		data[i] = data[i + 1];
	}
	num_used--;
	cout << "Element removed\n";
}

// print contents
template <class value_type>
void sequence<value_type>::print() const {
	for (int i = 0; i < num_used; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}


// expand container
template <class value_type>
void sequence<value_type>::expand() {
	capacity = capacity * 2;
	value_type* temp = new value_type[capacity];
	copy(data, data + num_used, temp);
	delete[] data;
	data = temp;
}
