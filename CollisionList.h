/// Lab 4, Circular, Doubly Linked List with a Hash Table Implementation
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751

/// CollisionList.h

#ifndef COLLISIONLIST_H
#define COLLISIONLIST_H

#include <iostream>
using std::ostream;

template <class DataType>
struct Node
{
  DataType info;
  Node<DataType> *next;
  Node<DataType> *dlnext;
  Node<DataType> *dlback;
};

template <class DataType>
class CollisionList
{
private:
  Node<DataType>* start;
  Node<DataType>* current;
  inline void deepCopy( const CollisionList<DataType>& original );

public:
  CollisionList();
  CollisionList( const CollisionList<DataType>& aplist );
  ~CollisionList();
  CollisionList<DataType>& operator=( const CollisionList<DataType>& rlist );
  void insert( const DataType& element );
  bool first( DataType& listEl );
  inline bool getNext( DataType& listEl );
  bool find( const DataType& element );
  bool retrieve( DataType& element );
  bool replace( const DataType& newElement );
  bool remove( DataType& element );
  bool isEmpty() const;
  void makeEmpty();
  Node<DataType>* getcurrent();

  template<class DT>
	friend ostream& operator<<( ostream &out, CollisionList<DT>& cl );
};

#include "CollisionList.cpp"

#endif // COLLISIONLIST_H
