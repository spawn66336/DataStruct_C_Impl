#pragma once

#include "def.h"

template<typename T>
class T_Queue
{
public:
	T_Queue();
	~T_Queue();

	Status Clear(void);
	Status Length(void) const;
	Status IsEmpty(void);
	Status GetHead( T& e );
	Status EnQueue( const T& e );
	Status DeQueue( const T& e );
	Status GetAt( const int i , T& e ) const;

protected:
	typedef struct queueNode_t{
		T data;
		queueNode_t* next;
	};

	queueNode_t* front;
	queueNode_t* rear;
};

template<typename T>
Status T_Queue<T>::GetAt( const int i , T& e ) const
{
	queueNode_t* currNode = front->next;
	int currIndx = 1;
	while( currNode )
	{
		if( currIndx == i )
		{
			e = currNode->data;
			return OK;
		}
		currIndx++;
		currNode = currNode->next;
	}
	return ERROR;
}

template<typename T>
T_Queue<T>::T_Queue():
front(NULL),
rear(NULL)
{
	front = new queueNode_t;
	front->data = 0;
	front->next = NULL;
	rear = front;
}


template<typename T>
T_Queue<T>::~T_Queue()
{
	Clear();
	delete front;
	front = rear = NULL;
}


template<typename T>
Status T_Queue<T>::DeQueue( const T& e )
{
	if( front->next )
	{
		queueNode_t* delNode = front->next;
		e = delNode->data;
		front->next = front->next->next;
		delete delNode;
		return OK;
	}
	return ERROR;
}

template<typename T>
Status T_Queue<T>::EnQueue( const T& e )
{
	queueNode_t* newNode = new queueNode_t;
	if( !newNode ) return OVERFLOW;
	newNode->data = e;
	newNode->next = NULL;

	rear->next = newNode;
	rear = newNode;

	return OK;
}

template<typename T>
Status T_Queue<T>::GetHead( T& e )
{
	if( front->next )
	{
		e = front->next->data;
		return OK;
	}
	return ERROR;
}

template<typename T>
Status T_Queue<T>::IsEmpty( void )
{
	return front == rear;
}

template<typename T>
Status T_Queue<T>::Length( void ) const
{
	int len = 0;
	queueNode_t* currNode = front->next;
	while( currNode )
	{
		len++;
		currNode = currNode->next;
	}
	return len;
}

template<typename T>
Status T_Queue<T>::Clear( void )
{
	queueNode_t* currNode = front->next;
	while( currNode )
	{
		queueNode_t* nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	} 
	rear = front;
	return OK;
}

template<typename T>
void Print_T_Queue_BasicType( const T_Queue<T>& Q )
{
	for( int i = 1 ; i <= Q.Length() ; i++ )
	{
		T e;
		Q.GetAt( i , e );
		cout<<e<<" ";
	}
	cout<<endl;
}