#include <iostream>
#include "Stack.h"

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

void main()
{
	SqStack_Test();
}