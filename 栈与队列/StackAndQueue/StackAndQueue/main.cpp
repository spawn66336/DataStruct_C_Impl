#include <iostream>
#include "Stack.h"
#include "T_Stack.h"
#include "Problems.h"
#include "T_Queue.h"

using namespace std;


void SqStack_Test(void)
{
	SqStack S;
	memset( &S , 0 , sizeof(S) );
	InitStack_Sq(S);

	for( int i = 1 ; i <= 100 ; i++ )
	{
		Push_Sq(S,i);
	}

	cout<<"S stacksize="<<S.stacksize<<" size="<<StackLength_Sq(S)<<" :"<<endl;
	StackTraverse_Sq(S,Visit_Print);
	cout<<endl;

	for( int i = 1 ; i<=20 ; i++ )
	{
		ElemType e;
		Pop_Sq(S,e);
	}

	cout<<"S stacksize="<<S.stacksize<<" size="<<StackLength_Sq(S)<<" :"<<endl;
	StackTraverse_Sq(S,Visit_Print);
	cout<<endl;

	DestroyStack_Sq(S);
}

void T_Stack_Test(void)
{
	T_Stack<int> s; 
	for( int i = 1 ; i <= 100 ; i++ )
	{
		s.Push(i);
	} 
	Print_T_Stack_BasicType( s ); 
}

void T_Queue_Test(void)
{
	T_Queue<int> q;
	for( int i = 1 ; i <= 100 ; i++ )
	{
		q.EnQueue(i);
	}
	Print_T_Queue_BasicType(q);
}

void main()
{
	//SqStack_Test();
	//T_Stack_Test();
	//Expression_Problem();
	T_Queue_Test();
}