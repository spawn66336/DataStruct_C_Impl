#include "SLinkList.h"

SLinkList g_slink_list;

void InitSpace_SL( SLinkList& space  )
{
	for( int i = 0 ; i < SLINKLIST_MAXSIZE-1 ; i++ )
		space[i].next = i+1;
	space[SLINKLIST_MAXSIZE-1].next = 0;
}

int Malloc_SL( SLinkList& space )
{
	int i = space[0].next;
	if( space[0].next )
	{
		space[0].next = space[i].next;
		space[i].next = 0;
	}
	return i;
}

void Free_SL( SLinkList& space , int k )
{
	if( k == 0 )
	{
		return;
	}

	space[k].next = space[0].next;
	space[0].next = k;
}

 Status InitList( int& L )
{
	if( L != 0 )
	{
		return ERROR;
	}

	L = Malloc_SL(g_slink_list);
	if( L == 0 )
	{
		return OVERFLOW;
	}
	return OK;
}

 Status DestroyList( int& L )
{
	if( L == 0 )
	{
		return ERROR;
	}

	int curr = L;
	while( curr != 0 )
	{
		int next = g_slink_list[curr].next;
		Free_SL(g_slink_list , curr);
		curr = next;
	}

	L = 0;
	return OK;
}

 Status ListEmpty( const int L )
{
	if( L == 0 )
	{
		return ERROR;
	}

	return g_slink_list[L].next == 0;
}

 Status ListLength( const int L )
{
	if( L == 0 )
	{
		return ERROR;
	}

	int len = 0;
	int curr = g_slink_list[L].next;
	while(curr)
	{
		len++;
		curr = g_slink_list[curr].next;
	}
	return len;
}

 Status GetElem( const int L , const int i , ElemType& e )
{
	if( L == 0 )
	{
		return ERROR;
	}

	int c = 1;
	int curr = g_slink_list[L].next;
	while(curr)
	{
		if( c == i )
		{
			e = g_slink_list[curr].data;
			return OK;
		}
		c++;
		curr = g_slink_list[curr].next;
	}
	return ERROR;
}

 Status LocateElem( const int L , const ElemType& e , PFCOMPARE cmp )
{
	if( L == 0 )
	{
		return ERROR;
	}
	int c = 1;
	int curr = g_slink_list[L].next;
	while( curr )
	{ 
		if( g_slink_list[curr].data == e)
		{
			return c;
		}
		curr = g_slink_list[curr].next;
		c++;
	}
	return ERROR;
}

 Status PriorElem( const int L , const ElemType& cur_e , ElemType& pre_e )
{

}

 Status NextElem( const int L , const ElemType& cur_e , ElemType& next_e )
{

}

 Status ListInsert( const int L , const int i , const ElemType& e )
{

}

 Status ListDelete( const int L , const int i , ElemType& e )
{

}

 void ListTraverse( const int L , PFVISIT visit )
{

}
