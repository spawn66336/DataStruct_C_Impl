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

}
