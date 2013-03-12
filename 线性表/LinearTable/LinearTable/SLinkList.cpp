#include "SLinkList.h"

SLinkList g_slink_list;

void InitSpace_SL( SLinkList& space  )
{
	for( int i = 0 ; i < SLINKLIST_MAXSIZE-1 ; i++ )
		space[i].next = i+1;
	space[SLINKLIST_MAXSIZE-1].next = 0;
}

 void InitSpace_SL( void )
{
	InitSpace_SL(g_slink_list);
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

 Status InitList_SL( int& L )
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

 Status DestroyList_SL( int& L )
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

 Status ListEmpty_SL( const int L )
{
	if( L == 0 )
	{
		return ERROR;
	}

	return g_slink_list[L].next == 0;
}

 Status ListLength_SL( const int L )
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

 Status GetElem_SL( const int L , const int i , ElemType& e )
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

 Status LocateElem_SL( const int L , const ElemType& e , PFCOMPARE cmp )
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

 Status PriorElem_SL( const int L , const ElemType& cur_e , ElemType& pre_e )
{
	if( L == 0 )
	{
		return ERROR;
	}
	
	int pre_p = 0; 
	int curr_p = g_slink_list[L].next;
	while( curr_p )
	{
		if( g_slink_list[curr_p].data == cur_e )
		{
			if( pre_p )
			{
				pre_e = g_slink_list[pre_p].data;
				return OK;
			}else{
				return ERROR;
			}
		}
		pre_p = curr_p;
		curr_p = g_slink_list[curr_p].next;
	} 
	return ERROR;
}

 Status NextElem_SL( const int L , const ElemType& cur_e , ElemType& next_e )
{
	if( L == 0 )
	{
		return ERROR;
	}

	int curr_p = g_slink_list[L].next;
	int next_p = 0;
	if(curr_p)
		next_p = g_slink_list[curr_p].next;

	while( curr_p )
	{
		if( g_slink_list[curr_p].data == cur_e )
		{
			if( next_p )
			{
				next_e = g_slink_list[next_p].data;
				return OK;
			}else{
				return ERROR;
			}
		}	

		curr_p = g_slink_list[curr_p].next;
		if(curr_p)
			next_p = g_slink_list[curr_p].next;
	} 
	return ERROR;
}

 Status ListInsert_SL( const int L , const int i , const ElemType& e )
{
	if( L == 0 )
	{
		return ERROR;
	} 
	int c = 1;
	int prev_p = L;
	int curr_p = g_slink_list[L].next;

	while( curr_p )
	{
		if( c == i )
		{ 
			int new_p = Malloc_SL(g_slink_list);
			if( new_p == 0) return OVERFLOW;
			g_slink_list[prev_p].next = new_p;
			g_slink_list[new_p].next = curr_p;
			g_slink_list[new_p].data = e;
			return OK;
		}  

		prev_p = curr_p;
		curr_p = g_slink_list[curr_p].next;
		c++;
	}

	if( c == i)
	{
		int new_p = Malloc_SL(g_slink_list);
		if( new_p == 0) return OVERFLOW;
		g_slink_list[prev_p].next = new_p;
		g_slink_list[new_p].data = e;
		g_slink_list[new_p].next = 0;
		return OK;
	}

	return ERROR;
}

 Status ListDelete_SL( const int L , const int i , ElemType& e )
{
	if( L == 0 )
	{
		return ERROR;
	} 

	int c = 1;
	int prev_p = L;
	int curr_p = g_slink_list[L].next;
	while( curr_p )
	{ 
		if( c == i )
		{
			g_slink_list[prev_p].next = g_slink_list[curr_p].next;
			Free_SL(g_slink_list , curr_p); 
			return OK;
		} 

		prev_p = curr_p;
		curr_p = g_slink_list[curr_p].next;
		c++;
	}

	return ERROR;
}

 void ListTraverse_SL( const int L , PFVISIT visit )
{
	if( L == 0 )
	{
		return;
	} 
	 
	int curr_p = g_slink_list[L].next; 
	while( curr_p )
	{
		if( VISIT_BREAK == visit( g_slink_list[curr_p].data ) )
		{
			break;
		}
		curr_p = g_slink_list[curr_p].next;
	}
}

  int GetCapacity_SL(void)
 {
	 int curr_p = g_slink_list[0].next;
	 int capacity = 0;
	 while( curr_p )
	 {
		 capacity++;
		 curr_p = g_slink_list[curr_p].next;
	 }
	 return capacity;
 }

  int GetAllocSize_SL(void)
 {
	 return SLINKLIST_MAXSIZE - GetCapacity_SL();
 }

 void MergeList_SL( const int La , const int Lb , const int Lc )
 {
	if( 
		La == 0 ||
		Lb == 0 ||
		Lc == 0
		)
	{
		return;
	}

	int pa = g_slink_list[La].next;
	int pb = g_slink_list[Lb].next;
	int pc = Lc;

	while( pa != 0 && pb != 0 )
	{
		ElemType a = g_slink_list[pa].data;
		ElemType b = g_slink_list[pb].data;
		if( a < b )
		{
			g_slink_list[pc].next = pa;
			pa = g_slink_list[pa].next;
			g_slink_list[g_slink_list[pc].next].next = 0;
			pc = g_slink_list[pc].next;
		}else{
			g_slink_list[pc].next = pb;
			pb = g_slink_list[pb].next;
			g_slink_list[g_slink_list[pc].next].next = 0;
			pc = g_slink_list[pc].next;
		}
	}

	while( pa != 0 )
	{
		g_slink_list[pc].next = pa;
		pa = g_slink_list[pa].next;
		g_slink_list[g_slink_list[pc].next].next = 0;
		pc = g_slink_list[pc].next;
	}

	while( pb != 0)
	{
		g_slink_list[pc].next = pb;
		pb = g_slink_list[pb].next;
		g_slink_list[g_slink_list[pc].next].next = 0;
		pc = g_slink_list[pc].next;
	}

	g_slink_list[La].next = 0;
	g_slink_list[Lb].next = 0;
 }

void Difference_SL( const int La , const int Lb , int& S )
{
	if( OK != InitList_SL(S) )
	{
		return;
	}

	int ps = S;
	int pa = g_slink_list[La].next;
	int pb = g_slink_list[Lb].next;

	while(pa)
	{
		int new_node = Malloc_SL(g_slink_list);
		if( new_node == 0 )
		{
			DestroyList_SL(S);
			S = 0;
			return;
		}
		g_slink_list[ps].next = new_node;
		g_slink_list[new_node].data = g_slink_list[pa].data;
		ps = new_node;

		pa = g_slink_list[pa].next;
	}

	while(pb)
	{
		int p_psame = S;
		int p_same = g_slink_list[S].next; 
		while(p_same)
		{
			if( g_slink_list[p_same].data == g_slink_list[pb].data )
			{
				break;
			} 
			p_psame = p_same;
			p_same = g_slink_list[p_same].next;
		}

		if( p_same )
		{ 
			g_slink_list[p_psame].next = g_slink_list[p_same].next;
			Free_SL(g_slink_list , p_same);
			if( p_same == ps )
			{
				ps = p_psame;
			} 
		}else{
			int new_node = Malloc_SL(g_slink_list);
			if( 0 == new_node )
			{
				DestroyList_SL(S);
				S = 0;
				return;
			}
			g_slink_list[ps].next = new_node;
			g_slink_list[new_node].data = g_slink_list[pb].data;
			g_slink_list[new_node].next = 0;
			ps = new_node;
		} 
		pb = g_slink_list[pb].next;
	}
	
}
