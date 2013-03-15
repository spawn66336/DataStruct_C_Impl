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
	LinkList q = p->next; //q�����ҵ�p��ǰ�����
	LinkList r = q; //p�ĺ�̽��
	if( p == q )
	{
		return;
	}

	//��p��ǰ��
	while( q->next != p ) { q = q->next; }

	//ժ��p�ĺ��
	p->next = r->next;

	//��r����p��ǰ��
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

			//ժ��p���
			p->next->prior = p->prior;
			p->prior->next = p->next;
			p->next = NULL;
			p->prior = NULL;

			//��ժ����p�����ʵ���λ��
			LP_DuLNode q = L.head;
			do{
				//�ҵ���һ�� С�ڵ���p���Ƶ�ȵĽ�� 
				//��p������q֮ǰ
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
