#pragma once
#include "def.h"


typedef struct LNode {
	ElemType        data;
	struct LNode* next;
}LNode, *LinkList;


/*
====================
		单链表实现
====================
*/
extern Status InitList_L( LinkList& L);
extern Status DestroyList_L( LinkList& L);
extern Status ClearList_L( LinkList L);
extern Status ListEmpty_L( LinkList L);
extern Status ListLength_L( LinkList L); 
extern Status GetElem_L( LinkList L , const int i  , ElemType& e);
extern Pos	  LocateElem_L( LinkList L , const ElemType& e , PFCOMPARE cmp = Compare );
extern Status PriorElem_L( LinkList L , const ElemType& cur_e , ElemType& pre_e );
extern Status NextElem_L( LinkList L , const ElemType& cur_e , ElemType& next_e );
extern Status ListInsert_L( LinkList L , const int i , const ElemType& e);
extern Status ListDelete_L( LinkList L , const int i , ElemType& e );
extern Status ListTraverse_L( LinkList L , PFVISIT visit );
extern void    MergeList_L( LinkList La , LinkList Lb , LinkList Lc );

/*
===================
		单循环链表
===================
*/

extern Status InitList_CL( LinkList& L);
extern Status DestroyList_CL( LinkList& L);
extern Status ClearList_CL( LinkList L);
extern Status ListEmpty_CL( LinkList L);
extern Status ListLength_CL( LinkList L); 
extern Status GetElem_CL( LinkList L , const int i  , ElemType& e);
extern Pos	  LocateElem_CL( LinkList L , const ElemType& e , PFCOMPARE cmp = Compare );
extern Status PriorElem_CL( LinkList L , const ElemType& cur_e , ElemType& pre_e );
extern Status NextElem_CL( LinkList L , const ElemType& cur_e , ElemType& next_e );
extern Status ListInsert_CL( LinkList L , const int i , const ElemType& e);
extern Status ListDelete_CL( LinkList L , const int i , ElemType& e );
extern Status ListTraverse_CL( LinkList L , PFVISIT visit );


/*
===================
		无头结点的单循环链表
===================
*/
extern Status InitList_CLNH( LinkList& L);
extern Status DestroyList_CLNH( LinkList& L);
extern Status ClearList_CLNH( LinkList& L);
extern Status ListEmpty_CLNH( LinkList L);
extern Status ListLength_CLNH( LinkList L); 
extern Status GetElem_CLNH( LinkList L , const int i  , ElemType& e);
extern Pos	  LocateElem_CLNH( LinkList L , const ElemType& e , PFCOMPARE cmp = Compare );
extern Status PriorElem_CLNH( LinkList L , const ElemType& cur_e , ElemType& pre_e );
extern Status NextElem_CLNH( LinkList L , const ElemType& cur_e , ElemType& next_e );
extern Status ListInsert_CLNH( LinkList& L , const int i , const ElemType& e);
extern Status ListDelete_CLNH( LinkList& L , const int i , ElemType& e );
extern Status ListTraverse_CLNH( LinkList L , PFVISIT visit );