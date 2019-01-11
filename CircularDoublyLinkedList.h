/// Lab 4, Circular, Doubly Linked List with a Hash Table Implementation
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751

/// CircularDoublyLinkedList.h

#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

#include <iostream>
using std::ostream;

#include "CDLHashTable.h"

// If an object of a struct is used for DataType, the == operator must be
// overloaded for it; the left and right operands are both DataType objects
// the == comparison is used for finding elements, usually by key value
// For find, retrieve and remove functions, if you are using an object as an element, a
// typical use would be to set the key of the desired object to find or remove, then pass
// the object into the function

// client must provide a hash function with the following characteristics:
// 1) 1 input parameter of DataType(see below), passed by const reference
// 2) returns an integer between 0 and size -1, inclusive, where size is the
//    number of elements in the hash table
// 3) the name of the function is passed as the first parameter to the CircularDoublyLinkedList
//    constructor, the size of the hash table is passed as the second parameter
// 4) client may make as many hash functions for as many CircularDoublyLinkedLists as desired

// The insert, find, retrieve, and remove functions will return false if an invalid index
// is obtained from the hash function. The copy constructor and overloaded
// assignment operator will produce an empty list if an invalid index is obtained
// from the hash function

// The constructor, copy constructor, overloaded assignment operator, and insert
// functions will throw an exception if out of heap memory
template <class DataType>
class CircularDoublyLinkedList
{
private:
	CDLHashTable<DataType> table;
	Node<DataType> *current;
	Node<DataType> *header;
	Node<DataType> *trailer;
	inline void deepCopy(const CircularDoublyLinkedList<DataType> &original);

public:
	CircularDoublyLinkedList(int (*hf)(const DataType &), int s);
	CircularDoublyLinkedList(const CircularDoublyLinkedList<DataType> &aplist);
	~CircularDoublyLinkedList();
	CircularDoublyLinkedList<DataType>& operator=(const CircularDoublyLinkedList<DataType> &rlist);
	bool insert(const DataType &element);
	bool find(const DataType &element);
	bool retrieve(DataType &element);
	bool remove(DataType &element);
	bool replace(const DataType &newElement);
	bool isEmpty() const;
	void makeEmpty();

	void display() const; // to display the doubly linked list

  template <class DT>
	friend ostream& operator<<(ostream& out, CircularDoublyLinkedList<DT>& dl); // to diplsy the hash table
};

#include "CircularDoublyLinkedList.cpp"

#endif
