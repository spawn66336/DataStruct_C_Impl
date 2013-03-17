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

void MergeList( LinkList& La , LinkList& Lb )
{

	if( La == NULL || Lb == NULL )
		return;
	
	LinkList ppb = Lb;
	LinkList pb = Lb->next;

	while( pb )
	{
		LinkList ppa = La;
		LinkList pa = La->next;

		while(pa)
		{ 
			if( pb->data < pa->data ) 
			{//Lb�и�Ԫ����La�в�����
				pa = NULL;
				continue;
			}else if( pb->data == pa->data ) 
			{//��Lb��ĳ��Ԫ����La�д��� 
				break;
			} 

			ppa = pa;
			pa = pa->next;
		}


		if( !pa )
		{//����A��û���ҵ�B�и�Ԫ��
			ppa = La;
			pa = La->next;

			//�ҵ�A�еĲ���λ��
			while(pa)
			{
				if( pb->data < pa->data )
				{
					break;
				}
				ppa = pa;
				pa = pa->next;
			}

			//��B�е�Ԫ�ز���
			LinkList lp_new = new LNode;
			lp_new->data = pb->data;
			lp_new->next = pa;
			ppa->next = lp_new;

			//��B�д��ڵ�A�в����ڵ�Ԫ�ش�B��ɾ��
			ppb->next = pb->next;
			delete pb;
			pb = ppb->next;
			continue;
		}

		ppb = pb;
		pb = pb->next;
	}


}

void Biggest( LinkList head , LinkList& front , LinkList& rear )
{
	
	LinkList f_max = head;
	LinkList p_max = head->next;
	LinkList r_max = head->next->next;

	LinkList f = f_max;
	LinkList p = p_max;
	LinkList r = r_max;
	while( p != head )
	{
		if( p->data > p_max->data )
		{
			f_max = f;
			p_max = p;
			r_max = r;
		}

		f = p;
		p = p->next;
		r = r->next;
	}

	front = f_max;
	rear   = r_max;
}

void Division( LinkList& L , LinkList& La , LinkList& Lb )
{ 
	LinkList p = L;

	do 
	{ 
		LinkList s = p;
		p = p->next;
		if( ( s->data % 2 ) == 0  )
		{//��Ϊż��
			
			if( La )
			{
				s->next = La->next;
				La->next = s;
			}else{
				s->next = s;
				La = s;
			}

		}else{//��Ϊ����

			if( Lb )
			{
				s->next = Lb->next;
				Lb->next = s;
			}else{
				s->next = s;
				Lb = s;
			} 
		} 
	} while ( p != L );

	L = NULL;
}

void ReverseList( LinkList& L )
{
	LinkList p = L;
	LinkList n = L->next;
	LinkList nn = L->next->next;
	do 
	{
		 n->next = p;
		 p = n;
		 n = nn;
		 nn = nn->next;
	} while ( p != L );
	L = L->next;
}

void DeleteSameEelems( SqList& L )
{
	if( L.len == 0)
	{
		return;
	}

	int tmp = L.lp_elem[0];
	int j = 0;
	for( int i = 0 ; i < L.len ; i++ )
	{
		if( L.lp_elem[i] != tmp )
		{
			j++;
			L.lp_elem[j] = L.lp_elem[i];
			tmp = L.lp_elem[i];
		}
	}

	L.len = j+1;
}
