/// Lab 4, Circular, Doubly Linked List with a Hash Table Implementation
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751

/// CDLHashTable.h
#ifndef CDLHASHTABLE_H
#define CDLHASHTABLE_H

#include <iostream>
using std::ostream;

#include "CollisionList.h"
#include "Array.h"

// client must provide a hash function with the following characteristics:
//  1) 1 input parameter of DataType (see below), passed by const reference
//  2) returns and integer between 0 and size - 1, inclusive, where size if the number of elements in the hash table
//  3) the name of the function is passed as the first parameter to the HashTable constructor
//  4) client may make as many hash functions for as many HashTables as desired
// if a struct is used for DataType, a typical use of retrieve, remove, and update would be to set the key of an object and then pass the object into the function
//  1) the hash function supplied above does not return a valid index
//  2) the supplied key or element cannot be found in the hash table
// otherwise, these functions will return true if successful
// For retrieve, remove and update functions, if you are using an object as an element, a typical use would be to set the key of the desire object to retrieve, remove, or update; then pass the object in to the function.
// if an object of a struct is used for DataType, the == operator must be overloaded for it; the left and right operands are both DataType objects
// the == comparison is used for finding elements, usually by key value
// *Exceptions can be thrown in the constructor, the (default) copy oonstructor, the (default) assignment operator, or the insert function if out of heap memory

template<class DataType>
class CDLHashTable
{
private:
  Array< CollisionList<DataType> > table;
  int(*hashfunc)(const DataType&); // pointer to hash function supplied by client
  int location;

public:
  CDLHashTable( int(*hf)(const DataType&), int s );
  bool insert( const DataType& newObject ); // returns true if successful; returns false if invalid index was returned from hash function
  bool retrieve( DataType& retrieved ); // see description above class template
  bool remove( DataType& removed ); // see description above class template
  bool update( DataType& updateObject ); // see description above class template
  void makeEmpty();
  Node<DataType>* getcurrent();
  int(*gethashfunc() const)(const DataType&);
  void sethashfunc( int(*hf)(const DataType&) );
  int getsize() const;
  void changeSize( int newSize );

  template <class DT>
	friend ostream& operator<<( ostream& out, CDLHashTable<DT>& dlht );
};

#include "CDLHashTable.cpp"

#endif // CDLHASHTABLE_H
