#include "Stack.h"

int Compare( const ElemType& lhs , const ElemType& rhs )
{
	if( lhs > rhs )
		return L_GREATER_R;
	else if( lhs < rhs )
		return L_LESS_R;
	else 
		return L_EQUAL_R;
}

int Visit_Print( const ElemType& e )
{
	printf("%d ",e);
	return VISIT_CONTINUE;
}

Status InitStack_Sq( SqStack& S )
{
	if( S.base )
	{
		return ERROR;
	}

	S.base = new ElemType[STACK_INIT_SIZE];
	if( S.base == NULL )
	{
		return OVERFLOW;
	}

	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack_Sq( SqStack& S )
{
	if( S.base == NULL )
	{
		return ERROR;
	}

	delete[] S.base;
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;
	return OK;
}

Status ClearStack_Sq( SqStack& S )
{
	S.top = S.base;
	return OK;
}

Status StackEmpty_Sq( SqStack& S )
{
	return S.top == S.base;
}

int StackLength_Sq( SqStack& S )
{
	return S.top - S.base;
}

Status GetTop_Sq( SqStack& S , ElemType& e )
{
	if( StackLength_Sq(S) )
	{
		e = *( S.top-1 );
		return OK;
	}
	return ERROR;
}

Status Push_Sq( SqStack& S , ElemType& e )
{
	if( S.base == NULL )
	{
		return ERROR;
	}

	if( StackLength_Sq(S) >= S.stacksize-1 )
	{
		ElemType* lp_new_base = new ElemType[S.stacksize+STACK_INC_SIZE];
		if( !lp_new_base ) return OVERFLOW;
		memcpy( lp_new_base , S.base , S.stacksize*sizeof(ElemType) );
		delete[] S.base;
		S.base = lp_new_base;
		S.top = S.base + S.stacksize-1;
		S.stacksize += STACK_INC_SIZE;
	}

	(*S.top) = e;
	S.top++;
	return OK;
}

Status Pop_Sq( SqStack& S , ElemType& e )
{
	if( S.base == S.top )
	{
		return ERROR;
	}
	
	e = *(S.top-1);
	S.top--;
	return OK;
}

Status StackTraverse_Sq( SqStack& S , PFVISIT visit )
{
	ElemType* p = S.base;
	while( p != S.top )
	{
		if( VISIT_BREAK == visit(*p) ) break;
		p++;
	}
	return OK;
}
