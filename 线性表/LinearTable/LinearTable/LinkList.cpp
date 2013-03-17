#include "LinkList.h"

Status InitList_L( LinkList& L )
{
	if( L != NULL )
	{
		return ERROR;
	}

	L = new LNode;
	L->data = 0;
	L->next = NULL;
	return OK;
}

Status DestroyList_L( LinkList& L )
{
	if( L == NULL )
	{
		return ERROR;
	}

	ClearList_L(L);
	delete L;
	L = NULL;
	return OK;
}

 Status ClearList_L( LinkList L )
{
	if( L == NULL )
	{
		return ERROR;
	}

	LinkList p = L->next;
	while(p)
	{
		LinkList del_p = p;
		p = p->next;
		delete del_p;
	}
	L->next = NULL;
	return OK;
}

 Status ListEmpty_L( LinkList L )
{
	if( L == NULL )
	{
		return ERROR;
	}
	return ( L->next == NULL );
}

 Status ListLength_L( LinkList L )
{
	if( L == NULL )
	{
		return ERROR;
	}

	int c = 0;
	LinkList p = L->next;
	while(p)
	{
		c++;
		p = p->next;
	}
	return c;
}

 Status GetElem_L( LinkList L , const int i , ElemType& e )
{
	if( L == NULL )
	{
		return ERROR;
	}

	int c = 0;
	LinkList p = L->next;
	while(p)
	{ 
		if( ++c == i  )
		{
			break;
		} 
		p = p->next;
	}

	if(p)
	{
		e = p->data;
		return OK;
	} 
	return ERROR; 
}

 Pos LocateElem_L( LinkList L , const ElemType& e , PFCOMPARE cmp /*= Compare */ )
{
	if( L == NULL )
	{
		return ERROR;
	}

	int c = 1;
	LinkList p = L->next;
	while(p)
	{  
		if( cmp( p->data , e ) == L_EQUAL_R )
		{
			return c;
		}

		p = p->next;
		c++;
	}

	return ERROR;
}

 Status PriorElem_L( LinkList L , const ElemType& cur_e , ElemType& pre_e )
{
	if( L == NULL )
	{
		return ERROR;
	}
	LinkList p = L->next;
	LinkList pre_p = NULL;
	while(p)
	{  
		if( p->data == cur_e )
		{
			if( pre_p )
			{
				pre_e = pre_p->data;
				return OK;
			}else{
				return ERROR;
			}
		} 
		pre_p = p;
		p = p->next; 
	}
	return ERROR;
}

 Status NextElem_L( LinkList L , const ElemType& cur_e , ElemType& next_e )
{
	if( L == NULL )
	{
		return ERROR;
	}

	if( TRUE == ListEmpty_L(L) )
	{
		return ERROR;
	}

	LinkList p = L->next;
	LinkList next_p = L->next->next;
	while(p)
	{
		if( p->data == cur_e )
		{
			if( next_p )
			{
				next_e = next_p->data;
				return OK;
			}else{
				return ERROR;
			}
		} 
		p = p->next;
		next_p = p->next;
	}
	return ERROR;
}

 Status ListInsert_L( LinkList L , const int i , const ElemType& e )
{
	if( L == NULL )
	{
		return ERROR;
	}

	int c = 1;
	int len = 0;
	LinkList pre_p = L;
	LinkList p = L->next;
	while(p)
	{
		len++;
		if( c == i )
		{  
			LinkList new_p = new LNode;
			new_p->data = e;
			new_p->next = p;
			pre_p->next = new_p;
			return OK;
		} 
		pre_p = p;
		p = p->next;
		c++;
	}

	if( i == len+1 )
	{
		pre_p->next = new LNode;
		pre_p->next->data = e;
		pre_p->next->next = NULL;
		return OK;
	}
	return ERROR;
}

 Status ListDelete_L( LinkList L , const int i , ElemType& e )
{
	if( L == NULL )
	{
		return ERROR;
	}
	
	int c = 1;

	LinkList pre_p = L;
	LinkList p = L->next;
	while(p)
	{
		if( c == i )
		{
			e = p->data;
			pre_p->next = p->next;
			delete p;
			return OK;
		}

		pre_p = p;
		p = p->next;
	}
	return ERROR;
}

 Status ListTraverse_L( LinkList L , PFVISIT visit )
{
	if( L == NULL )
	{
		return ERROR;
	}
	
	LinkList p = L->next;
	while(p)
	{
		if( VISIT_CONTINUE != visit(p->data) )
		{
			break;
		}
		p = p->next;
	}
	return OK;
}

 void MergeList_L( LinkList La , LinkList Lb , LinkList Lc )
 {
	 if( !La || !Lb || !Lc )
	 {
		 return;
	 }

	 LinkList pa = La->next;
	 La->next = NULL;
	 LinkList pb = Lb->next;
	 Lb->next = NULL;
	 LinkList pc = Lc;

	 while( pa && pb )
	 {
		 if( pa->data < pb->data )
		 {
			 pc->next = pa;
			 pc = pa;
			 pa = pa->next;
		 }else{
			 pc->next = pb;
			 pc = pb;
			 pb = pb->next;
		 }
	 }

	 if( pa )
	 {
		 pc->next = pa;
	 }

	 if( pb )
	 {
		 pc->next = pb;
	 } 
 }


  Status InitList_CL( LinkList& L )
 {
	 if( L != NULL )
	 {
		 return ERROR;
	 }

	 L = new LNode;
	 L->next = L;
	 return OK;
 }

  Status DestroyList_CL( LinkList& L )
 {
	 if( L == NULL )
	 {
		 return ERROR;
	 }
	 ClearList_CL(L);
	 delete L;
	 L = NULL;
	 return OK;
 }

  Status ClearList_CL( LinkList L )
 {
	 if( L == NULL )
	 {
		 return ERROR;
	 }
	  
	 LinkList p = L->next; 
	 while( p != L )
	 { 
		  L->next = p->next;
		  delete p;
		  p = L->next;
	 }

	 L->next = L;
	 return OK;
 }

  Status ListEmpty_CL( LinkList L )
 {
	 if( L == NULL )
	 {
		 return ERROR;
	 }

	 return ( L->next == L );
 }

  Status ListLength_CL( LinkList L )
 {
	 if( L == NULL )
	 {
		 return ERROR;
	 }

	 int len = 0;
	 LinkList p = L->next;
	 while( p != L )
	 {
		 len++;
		 p = p->next;
	 }
	 return len;
 }

  Status GetElem_CL( LinkList L , const int i , ElemType& e )
 {
	 if( L == NULL )
	 {
		 return ERROR;
	 }

	 int c = 1;
	 LinkList p = L->next;
	 while( p != L )
	 { 
		 if( c == i )
		 {
			 e = p->data;
			 return OK;
		 }
		 c++;
		 p = p->next;
	 }
	 return ERROR;
 }

  Pos LocateElem_CL( LinkList L , const ElemType& e , PFCOMPARE cmp /*= Compare */ )
 {
	 if( L == NULL )
	 {
		 return ERROR;
	 }

	 int c = 1;
	 LinkList p = L->next;
	 while( p != L )
	 { 
		 if( L_EQUAL_R == cmp( p->data , e ) )
		 {
			return c;
		 } 
		 c++;
		 p = p->next;
	 }

	 return ERROR;
 }

  Status PriorElem_CL( LinkList L , const ElemType& cur_e , ElemType& pre_e )
 {
	 if( L == NULL )
	 {
		 return ERROR;
	 }

	LinkList q = L;
	LinkList p = L->next;
	while( p != L )
	{
		if( p->data == cur_e )
		{
			if( q != L )
			{
				pre_e = q->data;
				return OK;
			}
		}
		q = p;
		p = p->next;
	} 
	 return ERROR;
 }

  Status NextElem_CL( LinkList L , const ElemType& cur_e , ElemType& next_e )
 {
	 if( L == NULL )
	 {
		 return ERROR;
	 }
	  
	 LinkList p = L->next;
	 LinkList q = L->next->next;
	 while( p != L )
	 {
		 if( p->data == cur_e )
		 {
			 if( q != L )
			 { 
				 next_e = q->data;
				 return OK;
			 }
		 }
		 p = q;
		 q = q->next;
	 } 
	 return ERROR;
 }

  Status ListInsert_CL( LinkList L , const int i , const ElemType& e )
 {
	 if( L == NULL )
	 {
		 return ERROR;
	 }

	 int c = 1;
	 LinkList p = L->next;
	 LinkList q = L;  // q保存的是p的前驱
	 while( p != L )
	 {
		 if( c == i )
		 {
			 break;
		 }

		 c++;
		 q = p;
		 p = p->next;
	 }
	  
	if( i == c )
	{
		LinkList n = new LNode;
		n->data = e;
		n->next = p;
		q->next = n;
		return OK;
	} 
	 return ERROR;
 }

  Status ListDelete_CL( LinkList L , const int i , ElemType& e )
 {
	 if( L == NULL )
	 {
		 return ERROR;
	 }

	 int c = 1;
	 LinkList p = L->next;
	 LinkList q = L;  // q保存的是p的前驱
	 while( p != L )
	 {
		 if( c == i )
		 {
			 q->next = p->next;
			 e = p->data;
			 delete p;
			 p = NULL;
			 return OK;
		 }

		 c++;
		 q = p;
		 p = p->next;
	 }
	 return ERROR;
 }

  Status ListTraverse_CL( LinkList L , PFVISIT visit )
 {
	 if( L == NULL )
	 {
		 return ERROR;
	 }

	  LinkList p = L->next;
	  while( p != L )
	  {
		 if( VISIT_BREAK == visit( p->data ) )
		 {
			 break;
		 }
		  p = p->next;
	  }
	  return OK;
 }

   Status InitList_CLNH( LinkList& L )
  {
	  L = NULL;
	  return OK;
  }

  Status DestroyList_CLNH( LinkList& L )
  {
		return ClearList_CLNH(L);
  }

  Status ClearList_CLNH( LinkList& L )
  {
	  if( L == NULL )
	  {
		  return ERROR;
	  }

	  LinkList p = L;
	  do 
	  {
		  LinkList s = p;
		  p = p->next;
		  delete s; 
	  } while ( p != L );

	  L = NULL;
	  return OK;
  }

 Status ListEmpty_CLNH( LinkList L )
  {
	  return L == NULL;
  }

  Status ListLength_CLNH( LinkList L )
  {
	  if( L == NULL )
	  {
		  return 0;
	  }

	  int len = 0;
	  LinkList p = L;
	  do 
	  {
			len++;
			p = p->next;
	  } while ( p != L );

	  return len;
  }

   Status GetElem_CLNH( LinkList L , const int i , ElemType& e )
  {
	  if( L == NULL )
	  {
		  return ERROR;
	  }

	  int c = 1;
	  LinkList p = L;

	  do 
	  {
		  if( c == i )
		  {
			  e = p->data;
			  return OK;
		  }
		  c++;
		  p = p->next;
	  }while( p != L );

	  return ERROR;
  }

   Pos LocateElem_CLNH( LinkList L , const ElemType& e , PFCOMPARE cmp /*= Compare */ )
  {
	  if( L == NULL )
	  {
		  return ERROR;
	  }

	  int c = 1;
	  LinkList p = L;
	  do 
	  {
		  if( L_EQUAL_R == cmp( e , p->data) )
		  {
			  return c;
		  }
		  c++;
		  p = p->next;
	  } while ( p != L );

	  return ERROR;
  }

 Status PriorElem_CLNH( LinkList L , const ElemType& cur_e , ElemType& pre_e )
  {
	  if( L == NULL )
	  {
		  return ERROR;
	  }

	  LinkList pp = L;
	  LinkList p = L->next;
	 do 
	 {
		  if( p->data == cur_e )
		  {
			  pre_e = pp->data;
			  return OK;
		  }
		  pp = p;
		  p = p->next;

	  }while( p != L->next );

	 return ERROR;
  }

  Status NextElem_CLNH( LinkList L , const ElemType& cur_e , ElemType& next_e )
  {
	  if( L == NULL )
	  {
		  return ERROR;
	  }
	   
	  LinkList p = L;
	  do 
	  {
		  if( p->data == cur_e )
		  {
			 next_e = p->next->data;
			 return OK;
		  }
		  p = p->next;
	  } while ( p != L );

	  return ERROR;
  }

 Status ListInsert_CLNH( LinkList& L , const int i , const ElemType& e )
 {
	 if( L == NULL )
	 {
		 if( i == 1 )
		 {
			 L = new LNode;
			 L->next = L;
			 L->data = e;
			 return OK;
		 }
		 return ERROR;
	 } 
	  LinkList pp = L;
	  LinkList p = L;
	  while( pp->next != L ) pp = pp->next;

	   int c = 1;

	  do 
	  {
		  if( c == i )
		  {
			  pp->next = new LNode;
			  pp->next->next = p;
			  pp->data = e;

			  if( c == 1 )
			  {
				  L = pp->next;
			  }
			  return OK;
		  }
		  c++;
		  pp = p;
		  p = p->next;
	  } while ( p != L );

	  //在队尾插入
	  if( c == i )
	  {
		  pp->next = new LNode;
		  pp->next->next = p;
		  pp->next->data = e;
		  return OK;
	  }
	  return ERROR;
  }

  Status ListDelete_CLNH( LinkList& L , const int i , ElemType& e )
  {
	  if( L == NULL )
	  {
		  return ERROR;
	  } 
	  LinkList pp = L;
	  LinkList p = L;

	  while( pp->next != L ) pp = pp->next;
		
	  int c = 1;
	  do 
	  {
		  if( c == i )
		  {
			  e = p->data;
			  pp->next = p->next;
			  if( c == 1 )
			  {
				  L = p->next;
			  }
			  delete p;
			  return OK;
		  }

		  c++;
		  pp = p;
		  p = p->next;
	  } while ( p != L );

	  return ERROR;
  }

   Status ListTraverse_CLNH( LinkList L , PFVISIT visit )
  {

	  if( L == NULL )
	  {
		  return ERROR;
	  } 

	  LinkList p = L;

	  do 
	  {
		  if( VISIT_BREAK == visit(p->data) )
		  {
			  break;
		  }
		  p = p->next;
	  } while ( p != L );

	  return OK;
  }
