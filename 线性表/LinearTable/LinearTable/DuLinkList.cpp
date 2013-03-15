#include "DuLinkList.h"

Status MakeNode( LP_DuLNode&p , ElemType e )
{
	if( p != NULL )
	{
		return ERROR;
	}

	p = new DuLNode;
	p->data = e;
	p->prior = p;
	p->next = p;
	return OK;
}

void FreeNode( LP_DuLNode& p )
{
	if( p )
	{
		delete p;
		p = NULL;
	}
}

Status InitList_DuL( DuLinkList& L )
{
	if( L.head != NULL )
	{
		return ERROR;
	}

	L.head = NULL;
	L.len = 0;
	return OK;
}

Status DestroyList_DuL( DuLinkList& L )
{
	return ClearList_DuL(L);
}

Status ClearList_DuL( DuLinkList& L )
{
	if( L.head )
	{
		LP_DuLNode p =  L.head->next;
		LP_DuLNode next = p->next;
		while( p != L.head )
		{
			FreeNode(p);
			p = next;
			next = next->next;
		} 
		FreeNode(L.head); 
		L.head = NULL;
		L.len = 0;
		return OK;
	}
	return ERROR;
}

Status InsFirst_DuL(  DuLinkList& L , LP_DuLNode s )
{
	if( L.head == NULL )
	{
		s->next = s;
		s->prior = s;
		L.head = s;
		L.len = 1;
		return OK;
	}

	LP_DuLNode old_head = L.head;
	s->next = old_head;
	s->prior = old_head->prior;
	old_head->prior->next = s;
	old_head->prior = s;
	L.head = s;
	L.len++;
	return OK;
}

Status DelFirst_DuL(  DuLinkList& L , LP_DuLNode& q )
{
	if( L.head == NULL )
	{
		return ERROR;
	}

	LP_DuLNode old_head = L.head;
	q = old_head;
	
	old_head->prior->next = old_head->next;
	old_head->next->prior = old_head->prior;
	
	if( old_head->next == old_head ) 
	{
		L.head = NULL;
	}else{
		L.head = old_head->next;
	}
	L.len--;

	q->next = q;
	q->prior = q;
	 
	return OK;
}

Status Append_DuL( DuLinkList& L , LP_DuLNode s )
{ 
	if( L.head == NULL )
	{
		s->next = s;
		s->prior = s;
		L.head = s;
		L.len = 1;
		return OK;
	}

	L.head->prior->next = s;
	s->prior = L.head->prior;
	s->next = L.head;
	L.head->prior = s;

	L.len++;
	return OK;
}

Status Remove_DuL( DuLinkList& L , LP_DuLNode& q )
{
	if( L.head == NULL )
	{
		return ERROR;
	}
	
	q = L.head->prior;

	if( L.head->prior == L.head )
	{
		L.head = NULL; 
	}else{
		L.head->prior->prior->next = L.head;
		L.head->prior = q->prior;
	}
	L.len--;

	q->next = q;
	q->prior = q;

	return OK;
}

Status InsBefore_DuL( DuLinkList& L , LP_DuLNode& p , LP_DuLNode s )
{
	if( p == NULL || s == NULL )
	{
		return ERROR;
	}

	p->prior->next = s;
	s->prior = p->prior;
	s->next = p;
	p->prior = s;

	L.len++;
	return OK;
}

Status InsAfter_DuL( DuLinkList& L , LP_DuLNode& p , LP_DuLNode s )
{
	if( p == NULL || s == NULL )
	{
		return ERROR;
	}

	p->next->prior =s;
	s->next = p->next;
	s->prior = p;
	p->next = s;

	L.len++;
	return OK;
}

Status SetCurElem_DuL( LP_DuLNode p , ElemType e )
{
	if( p )
	{
		p->data = e;
		return OK;
	}
	return ERROR;
}

Status GetCurElem_DuL( LP_DuLNode p , ElemType& e )
{
	if( p )
	{
		e = p->data;
		return OK;
	}
	return ERROR;
}

Status ListEmpty_DuL( DuLinkList L )
{
	return L.len == 0;
}

int ListLength_DuL( DuLinkList L )
{
	return L.len;
}

LP_DuLNode GetHead_DuL( DuLinkList L )
{
	return L.head;
}

LP_DuLNode GetLast_DuL( DuLinkList L )
{
	if( L.head )
	{
		return L.head->prior;
	}
	return NULL;
}

LP_DuLNode PriorPos_DuL( DuLinkList L , LP_DuLNode p )
{
	if( p )
	{
		return p->prior;
	}
	return NULL;
}

LP_DuLNode NextPos_DuL( DuLinkList L , LP_DuLNode p )
{
	if( p )
	{
		return p->next;
	}
	return NULL;
}

Status LocatePos_DuL( DuLinkList L , int i , LP_DuLNode& p )
{
	int c = 1;
	LP_DuLNode q = L.head;
	do{
		if( c == i )
		{
			p = q;
			return OK;
		}
		c++;
		q = q->next;
	}while( q != L.head );

	return ERROR;
}

LP_DuLNode LocateElem_DuL( DuLinkList L , ElemType e , PFCOMPARE cmp )
{
	LP_DuLNode q = L.head;
	do 
	{
		if( L_EQUAL_R == cmp( e , q->data ) )
		{
			return q;
		}
		q = q->next;
	} while ( q != L.head );

	return NULL;
}

Status ListTraverse_DuL( DuLinkList L , PFVISIT visit )
{
	LP_DuLNode q = L.head;
	do{
		if( VISIT_BREAK == visit(q->data) )
		{
			break;
		}
		q = q->next;
	}while( q != L.head );
	return OK;
}

Status MergeList_DuL( DuLinkList& La , DuLinkList& Lb , DuLinkList& Lc , PFCOMPARE cmp )
{
	int ret = 0;
	if( OK != ( ret = InitList_DuL(Lc) ) )
	{
		return ret;
	}


	while( GetHead_DuL(La) && GetHead_DuL(Lb) )
	{
		LP_DuLNode pa = GetHead_DuL(La);
		LP_DuLNode pb = GetHead_DuL(Lb);

		if( L_LESS_R == cmp(pa->data , pb->data ) )
		{
			DelFirst_DuL( La , pa );
			Append_DuL( Lc , pa );
		}else{
			DelFirst_DuL(Lb , pb);
			Append_DuL( Lc , pb);
		} 
	}

	while(  GetHead_DuL(La) )
	{
		LP_DuLNode pa = NULL;
		DelFirst_DuL(La , pa);
		Append_DuL( Lc , pa ); 
	}

	while( GetHead_DuL(Lb) )
	{
		LP_DuLNode  pb = NULL;
		DelFirst_DuL(Lb , pb);
		Append_DuL( Lc , pb ); 
	}
	 
	return OK;
}
