#include "Problems.h"

Status ClearSameElem( LinkList L )
{
	if( L == NULL )
	{
		return ERROR;
	}

	LinkList p = L->next;

	while(p)
	{ 
		LinkList r = p;
		LinkList q = p->next;
		while(q)
		{
			if( p->data == q->data )
			{
				r->next = q->next;
				delete q;
				q = NULL;
				q = r->next;
				continue;
			} 
			r = q;
			q = q->next;
		}
		p = p->next;
	}

	return OK;
}

void Adjust( LinkList& p )
{
	LinkList q = p->next; //q用于找到p的前驱结点
	LinkList r = q; //p的后继结点
	if( p == q )
	{
		return;
	}

	//找p的前驱
	while( q->next != p ) { q = q->next; }

	//摘除p的后继
	p->next = r->next;

	//将r提至p的前驱
	r->next = p;
	q->next = r;
}

void Locate( DuLinkList& L , const ElemType& e )
{
	if( L.len == 0 )
	{
		return;
	} 

	LP_DuLNode p = L.head;
	do{
		if( p->data == e )
		{
			p->freq++;

			if( p == L.head )
			{
				if( p->next == p )
				{
					L.head = NULL;
				}else{
					L.head = p->next;
				}
			}

			//摘除p结点
			p->next->prior = p->prior;
			p->prior->next = p->next;
			p->next = NULL;
			p->prior = NULL;

			//将摘除的p放在适当的位置
			LP_DuLNode q = L.head;
			do{
				//找到第一个 小于等于p结点频度的结点 
				//将p结点插入q之前
				if( q->freq <= p->freq )
				{
					if( q == L.head )
					{
						L.head = p;
					}
										
					p->next = q;
					p->prior = q->prior;
					q->prior->next = p;
					q->prior = p;
					break;
				}
				q = q->next;
			}while( q != L.head );

			return;
		}
		p = p->next;
	}while( p != L.head );
	
}
