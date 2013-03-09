#pragma once
#include "def.h"


typedef struct LNode {
	ElemType        data;
	struct LNode* next;
}LNode, *LinkList;


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