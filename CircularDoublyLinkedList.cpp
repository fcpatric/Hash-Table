/// Lab 4, Circular, Doubly Linked List with a Hash Table Implementation
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751

/// CircularDoublyLinkedList.cpp

#include <iostream>
using namespace std; // null

template <class DataType>

inline void CircularDoublyLinkedList<DataType>::deepCopy(const CircularDoublyLinkedList<DataType> &original)
{
	if (original.table.getsize() != table.getsize())
		table.changeSize(original.table.getsize());

	table.sethashfunc(original.table.gethashfunc());
	current = header = trailer = NULL;
  Node<DataType>* save = NULL;
	Node<DataType>* originalptr = original.trailer;

	if (original.isEmpty() || !insert(originalptr->info))
		return;

	while (originalptr->dlback != original.header)
	{
		originalptr = originalptr->dlback;

		if ( !insert(originalptr->info) )
		{
			makeEmpty();
			return;
		}

		if( original.current == originalptr )
      save = header;
	}

  !insert(original.header->info);

  originalptr = NULL;
	current = save;
}

template <class DataType>
CircularDoublyLinkedList<DataType>::CircularDoublyLinkedList(int(*hf)(const DataType &), int s)
	: table(hf, s), current(NULL), header(NULL), trailer(NULL) {}

// copy constructor
template <class DataType>
CircularDoublyLinkedList<DataType>::CircularDoublyLinkedList(const CircularDoublyLinkedList<DataType> &aplist)
: table( aplist.table.gethashfunc(), aplist.table.getsize() )
{
  deepCopy(aplist);
}

// destructor
template <class DataType>
CircularDoublyLinkedList<DataType>::~CircularDoublyLinkedList()
{
  makeEmpty();
}

// overloaded operator=
template <class DataType>
CircularDoublyLinkedList<DataType>& CircularDoublyLinkedList<DataType>::operator=(const CircularDoublyLinkedList<DataType> &rlist)
{
  if(this == &rlist)
    return *this;
  makeEmpty();
  deepCopy(rlist);
  return *this;
}

template <class DataType>
bool CircularDoublyLinkedList<DataType>::insert(const DataType &element)
{
  if( !table.insert(element) )
    return false;

  current = table.getcurrent();

	if ( isEmpty() )
		trailer = current;

	else
	{
		current->dlnext = header;
		header->dlback = current;
		trailer->dlnext = current;
	}

  current->dlback = trailer;
  trailer->dlnext = current;
	header = current;
	current = NULL;
  return true;
}

template <class DataType>
bool CircularDoublyLinkedList<DataType>::find( const DataType &element )
{
  DataType el = element;

  if( table.retrieve(el) )
  {
    current = table.getcurrent();
    return true;
  }

  current = NULL;
  return false;
}

template <class DataType>
bool CircularDoublyLinkedList<DataType>::retrieve( DataType &element )
{
  if( !find( element ) )
    return false;

  element = current->info;
  return true;
}

template <class DataType>
bool CircularDoublyLinkedList<DataType>::remove( DataType &element )
{
  if( !retrieve(element) )
    return false;

  // want to remove the head
 if ( current == header && current != trailer )
	{
		header = current->dlnext;
		header->dlback = trailer;
		trailer->dlnext = header;
	}

  // want to remove the tail
  else if ( current == trailer && current != header )
	{
		trailer = current->dlback;
		trailer->dlnext = header;
		header->dlback = trailer;
	}

  // want to remove in between head and tail
	else if( current != header && current != trailer )
	{
		current->dlback->dlnext = current->dlnext;
		current->dlnext->dlback = current->dlback;
	}

  // want to remove the only node that is left
  else if( current == header && current == trailer )
  {
    current->dlnext = NULL;
    current->dlback = NULL;
    header = NULL;
    trailer = NULL;
  }

  current = NULL;
  table.remove(element);

  return true;
}

template <class DataType>
bool CircularDoublyLinkedList<DataType>::replace( const DataType &newElement )
{
  if( isEmpty() || current == NULL )
    return false;

  current->info = newElement;
  return true;
}

template <class DataType>
bool CircularDoublyLinkedList<DataType>::isEmpty() const
{
  return (header == NULL && trailer == NULL);
}

template <class DataType>
void CircularDoublyLinkedList<DataType>::makeEmpty()
{
  table.makeEmpty();
	current = header = trailer = NULL;
}

template <class DataType>
void CircularDoublyLinkedList<DataType>::display() const
{
	if ( isEmpty() )
	{
		cout << "Circular Doubly Linked List is Empty.\n";
		return;
	}

	cout << "Header using dlnext...\n";
	cout << header->info << " ";
	for (Node<DataType>* temp = header->dlnext; temp != header; temp = temp->dlnext)
		cout << temp->info << " ";

	cout << endl;
	cout << endl;

	cout << "Header using dlback...\n";
	cout << header->info << " ";
	for (Node<DataType>* temp = header->dlback; temp != header; temp = temp->dlback)
		cout << temp->info << " ";
	cout << endl;
	cout << endl;

	cout << "Trailer using dlnext...\n";
	cout << trailer->info << " ";
	for (Node<DataType>* temp = trailer->dlnext; temp != trailer; temp = temp->dlnext)
		cout << temp->info << " ";
	cout << endl;
	cout << endl;

	cout << "Trailer using dlback...\n";
	cout << trailer->info << " ";
	for (Node<DataType>* temp = trailer->dlback; temp != trailer; temp = temp->dlback)
		cout << temp->info << " ";
	cout << endl;

	return;
}

template <class DT>
ostream& operator<<(ostream& out, CircularDoublyLinkedList<DT>& dl)
{
	out << dl.table;

	return out;
}
