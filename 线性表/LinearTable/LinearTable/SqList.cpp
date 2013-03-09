#include "SqList.h" 

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

 Status InitList_Sq( SqList& L )
{
	if( L.lp_elem != NULL )
	{
		return ERROR;
	}

	L.lp_elem = new ElemType[LIST_INIT_SIZE];
	//若内存分配失败 则返回内存溢出
	if( L.lp_elem == NULL )
	{
		return OVERFLOW;
	}

	L.capacity = LIST_INIT_SIZE;
	L.len = 0;

	return OK;
}

 Status DestroyList_Sq( SqList& L )
{
	if( L.lp_elem )
	{
		delete[] L.lp_elem;
		L.lp_elem = NULL;
		L.len = 0;
		L.capacity = 0;
	}
	return OK;
}

 Status ClearList_Sq( SqList& L )
{
	//若表还未初始化 则返回错误
	if( L.lp_elem == NULL )
	{
		return ERROR;
	}

	L.len = 0;
	return OK;
}

 Status ListEmpty_Sq( SqList& L )
{ 
	if( L.len == 0 )
	{
		return TRUE;
	}
	return FALSE;
}

 Status ListLength_Sq( SqList& L )
{
	return L.len;
}

 Status ListCapacity_Sq( SqList& L )
 {
	 return L.capacity;
 }


 Status GetElem_Sq( SqList& L , const int i , ElemType& e )
{
	if( i < 1 || i > L.len )
	{
		return ERROR;
	}
	e = L.lp_elem[i-1];
	return OK;
}

 Pos LocateElem_Sq( SqList& L , const ElemType& e , PFCOMPARE cmp )
{
	if( L.lp_elem == NULL )
	{
		return ERROR;
	}

	int i = 0;
	for( i = 0 ; i < L.len ; i++ )
	{
		//找到第一个与指定元素相等的 位置
		if( L_EQUAL_R == cmp( L.lp_elem[i] , e ) )
		{
			break;
		}
	}
	return i+1;
}

 Status PriorElem_Sq( SqList& L , const ElemType& cur_e , ElemType& pre_e )
{
	if( L.lp_elem == NULL )
	{
		return ERROR;
	}

	Pos i = LocateElem_Sq(L , cur_e);
	if( i <= 1 || i > L.len  )
	{
		return ERROR;
	}

	Pos prior_pos = i - 1;
	Pos j = prior_pos-1;
	pre_e = L.lp_elem[j];
	return OK;
}

 Status NextElem_Sq( SqList& L , const ElemType& cur_e , ElemType& next_e )
{
	if( L.lp_elem == NULL )
	{
		return ERROR;
	}
	Pos i = LocateElem_Sq(L , cur_e);
	if( i < 1 || i >= L.len  )
	{
		return ERROR;
	}
	Pos next_pos = i+1;
	Pos j = next_pos-1;
	next_e = L.lp_elem[j];
	return OK;
}

 Status ListInsert_Sq( SqList& L , const int i , const ElemType& e )
{
	if( L.lp_elem == NULL )
	{
		return ERROR;
	}

	if( i < 1 || i > L.len+1 ) return ERROR;

	if( L.len+1 > L.capacity )
	{
		int new_size = L.capacity+LIST_INCE_SIZE;
		ElemType* lp_new_elems = new ElemType[ new_size ];
		if( lp_new_elems == NULL )
		{
			return OVERFLOW;
		}
		memcpy( lp_new_elems , L.lp_elem , sizeof(ElemType)*L.len );
		delete[] L.lp_elem;
		L.lp_elem = lp_new_elems;
		L.capacity = L.capacity+LIST_INCE_SIZE;
	}

	for( int j = L.len ; j >= i ; j-- )
	{
		L.lp_elem[j] = L.lp_elem[j-1];
	}
	L.lp_elem[i-1] = e;
	L.len++;

	return OK;
}

 Status ListDelete_Sq( SqList& L , const int i , ElemType& e )
{
	if( L.lp_elem == NULL )
	{
		return ERROR;
	}

	if( i < 1 || i > L.len )
	{
		return ERROR;
	}
	 
	for( int j = i+1 ; j <= L.len ; j++ )
	{
		L.lp_elem[j-2] = L.lp_elem[j-1]; 
	}

	L.len--;
	return OK;
}

 Status ListTraverse_Sq( SqList& L , PFVISIT visit )
{
	if( L.lp_elem == NULL )
	{
		return ERROR;
	}

	for( int i = 0 ; i < L.len ; i++ )
	{
		if(VISIT_BREAK == visit(L.lp_elem[i]) )
		{
			break;
		}
	}
	return OK;
}

 void MergeList_Sq( SqList& La , SqList& Lb , SqList& Lc )
 { 
	 if( OK != InitList_Sq(Lc) )
	 {
		 return;
	 }

	 int i = 1;
	 int j = 1;
	 while( i <= La.len && 
		       j <= Lb.len )
	 {
		 if( La.lp_elem[i-1] < Lb.lp_elem[j-1] )
		 {
			 ListInsert_Sq(Lc , Lc.len+1 , La.lp_elem[i-1]); i++;
		 }else{
			 ListInsert_Sq(Lc , Lc.len+1 , Lb.lp_elem[j-1]); j++;
		 }
	 }

	 while( i <= La.len )
	 {
		  ListInsert_Sq(Lc , Lc.len+1 , La.lp_elem[i-1]); i++;
	 }
	 while( j <= Lb.len )
	 {
		  ListInsert_Sq(Lc , Lc.len+1 , Lb.lp_elem[j-1]); j++;
	 }
	 
 }

