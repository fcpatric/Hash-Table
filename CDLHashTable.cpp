/// Lab 4, Circular, Doubly Linked List with a Hash Table Implementation
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751

/// CDLHashTable.cpp

template <class DataType>
CDLHashTable<DataType>::CDLHashTable( int(*hf)(const DataType&), int s )
: table(s)
{
  hashfunc = hf;
}

template <class DataType>
bool CDLHashTable<DataType>::insert( const DataType& newObject )
{
  location = hashfunc( newObject );

  if( location < 0 || location >= table.length() )
    return false;

  table[location].insert( newObject );

  return true;
}

template <class DataType>
bool CDLHashTable<DataType>::retrieve( DataType& retrieved )
{
  location = hashfunc( retrieved );

  if( location < 0 || location >= table.length() )
    return false;

  if( !table[location].retrieve( retrieved ) )
    return false;

  return true;
}

template <class DataType>
bool CDLHashTable<DataType>::remove( DataType& removed )
{
  location = hashfunc( removed );

  if( location < 0 || location >= table.length() )
    return false;

  if( !table[location].remove( removed ) )
    return false;

  return true;
}

template <class DataType>
bool CDLHashTable<DataType>::update( DataType& updateObject )
{
  location = hashfunc( updateObject );

  if( location < 0 || location >= table.length() )
    return false;

  if( !table[location].find( updateObject ) )
    return false;

  table[location].replace( updateObject );

  return true;
}

template <class DataType>
void CDLHashTable<DataType>::makeEmpty()
{
  for( int i = 0; i < table.length();i++ )
    table[i].makeEmpty();
}

template <class DataType>
Node<DataType>* CDLHashTable<DataType>::getcurrent()
{
  return table[location].getcurrent();
}

template <class DataType>
int(*CDLHashTable<DataType>::gethashfunc() const)(const DataType&)
{
  return hashfunc;
}

template <class DataType>
void CDLHashTable<DataType>::sethashfunc( int(*hf)(const DataType&) )
{
  hashfunc = hf;
}

template <class DataType>
int CDLHashTable<DataType>::getsize() const
{
  return table.length();
}

template <class DataType>
void CDLHashTable<DataType>::changeSize( int newSize )
{
  table.changeSize( newSize );
}

template <class DT>
ostream& operator<<( ostream& out, CDLHashTable<DT>& dlht )
{
	out << dlht.table;

	return out;
}
