#pragma once
#include "def.h"

#define T_STACK_INIT_SIZE 100
#define T_STACK_INC_SIZE 10

template<typename T>
class T_Stack{
public:
	T_Stack();
	~T_Stack();

	 Status Clear( void );
	 Status IsEmpty( void) const;
	 int	    GetLength( void ) const;
	 Status GetTop( T& e ) const;
	 Status GetAt( const int i , T& e ) const;
	 Status Push( const T& e );
	 Status Pop( T& e );

protected:
	T* base;
	T* top;
	int capacity;
};



template<typename T>
T_Stack<T>::T_Stack():
base(0),
top(0),
capacity(0)
{
	capacity = T_STACK_INIT_SIZE;
	base = new T[capacity];
	top = base;
	if(!base)
	{
		capacity = 0;
	}
}


template<typename T>
T_Stack<T>::~T_Stack()
{
	if( base )
	{
		delete[] base;
		base = top = NULL;
		capacity = 0;
	}
}

template<typename T>
Status T_Stack<T>::Clear( void )
{
	top = base;
	return OK;
}


template<typename T>
Status T_Stack<T>::IsEmpty( void ) const
{
	return (top == base);
}


template<typename T>
int T_Stack<T>::GetLength( void ) const
{
	return top - base;
}


template<typename T>
Status T_Stack<T>::GetTop( T& e ) const
{
	if( IsEmpty() )
	{
		return ERROR;
	}

	e = *(top-1); 
	return OK;
}


template<typename T>
Status T_Stack<T>::GetAt( const int i , T& e ) const
{
	if( i < 0 || i >= GetLength() )
	{
		return ERROR;
	}

	e = base[i];
	return OK;
}


template<typename T>
Status T_Stack<T>::Push( const T& e )
{
	if( GetLength()+1 >= capacity )
	{
		int old_len = GetLength();
		T* new_base = new T[capacity+T_STACK_INC_SIZE]; 
		if( !new_base ) return OVERFLOW; 
		memcpy( new_base , base , old_len*sizeof(T) );

		delete[] base;
		base = new_base;
		top = base+old_len;
		capacity += T_STACK_INC_SIZE;
	}

	*top = e;
	 top++;
	 return OK;
}

template<typename T>
Status T_Stack<T>::Pop( T& e )
{
	if( GetLength() )
	{
		e = *(top-1);
		top--;
		return OK;
	}
	return ERROR;
}

template<typename T>
void Print_T_Stack_BasicType( const T_Stack<T>& S )
{
	for( int i = 0 ; i < S.GetLength() ; i++ )
	{
		T e;
		S.GetAt( i , e );
		cout<<e<<" ";
	}
	cout<<endl;
}