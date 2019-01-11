/// Lab 4, Circular, Doubly Linked List with a Hash Table Implementation
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751

/// CollisionList.cpp

#include <iostream>
using namespace std; // null

template<class DataType>
inline void CollisionList<DataType>::deepCopy( const CollisionList<DataType>& original )
{
  start = current = NULL;

  if( original.start == NULL )
    return;

  Node<DataType> *copyptr = start = new Node<DataType>;
  Node<DataType> *originalptr = original.start;
  copyptr->info = originalptr->info;

  if( originalptr == original.current )
    current = copyptr;

  while( originalptr->next != NULL )
  {
    originalptr = originalptr->next;
    copyptr->next = new Node<DataType>;
    copyptr = copyptr->next;
    copyptr->info = originalptr->info;

    if( originalptr == original.current )
      current = copyptr;
  }

  copyptr->next = NULL;
}

template<class DataType>
CollisionList<DataType>::CollisionList()
{
  start = NULL;
  current = NULL;
}

template<class DataType>
CollisionList<DataType>::CollisionList( const CollisionList<DataType>& aplist )
{
  deepCopy( aplist );
}

template<class DataType>
CollisionList<DataType>::~CollisionList()
{
  makeEmpty();
}

template<class DataType>
CollisionList<DataType>& CollisionList<DataType>::operator=( const CollisionList<DataType>& rlist )
{
  if( this == &rlist )
    return *this;
  makeEmpty();
  deepCopy(rlist);
  return *this;
}

template<class DataType>
void CollisionList<DataType>::insert( const DataType& element )
{
  Node<DataType> *newNode = new Node<DataType>;
  newNode->info = element;
  newNode->next= start;
  current = newNode;
  start = newNode;
}

template<class DataType>
bool CollisionList<DataType>::first(DataType& listEl)
{
  if(start == NULL)
    return false;

  current = start;
  listEl = start->info;
  return true;
}

template<class DataType>
inline bool CollisionList<DataType>::getNext( DataType& listEl )
{
  if( current == NULL )
    return false;

  if( current->next == NULL )
  {
    current = NULL;
    return false;
  }

  current = current->next;
  listEl = current->info;
  return true;
}

template<class DataType>
bool CollisionList<DataType>::find( const DataType& element )
{
  DataType item;
  if( !first( item ) )
    return false;
  do
  {
    if( item == element )
      return true;
  } while( getNext( item ) );

  return false;
}

template<class DataType>
bool CollisionList<DataType>::retrieve( DataType& element )
{
  if( !find( element ) )
    return false;
  element = current->info;
  return true;
}

template<class DataType>
bool CollisionList<DataType>::replace( const DataType& newElement )
{
  if( current == NULL )
    return false;
  current->info = newElement;
  return true;
}

template<class DataType>
bool CollisionList<DataType>::remove( DataType& element )
{
  current = NULL;

  if( start == NULL )
    return false;

  Node<DataType> *ptr = start;

  if( ptr->info == element )
  {
    element = ptr->info;
    start = start->next;
    delete ptr;
    return true;
  }

  while( ptr->next != NULL )
  {
    if( ptr->next->info == element )
    {
      Node<DataType> *tempPtr = ptr->next;
      element = tempPtr->info;
      ptr->next = tempPtr->next;
      delete tempPtr;
      return true;
    }

    ptr = ptr->next;
  }

  return false;
}

template<class DataType>
void CollisionList<DataType>::makeEmpty()
{
  while( start != NULL )
  {
    current = start;
    start = start->next;
    delete current;
  }

  current = NULL;
}

template<class DataType>
Node<DataType>* CollisionList<DataType>::getcurrent()
{
  return current;
}

template<class DT>
ostream& operator<<( ostream& out, CollisionList<DT>& cl )
{
	for (Node<DT>* temp = cl.start; temp != NULL; temp = temp->next)
	{
		out << temp->info << "->";
	}

	out << "NULL";

	return out;
}
