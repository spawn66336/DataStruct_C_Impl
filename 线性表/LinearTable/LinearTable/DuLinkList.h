#pragma once

#include "def.h"

typedef struct DuLNode{
	ElemType data;
	int freq;			//结点的访问频度
	struct DuLNode	*prior;
	struct DuLNode   *next;
}DuLNode , *LP_DuLNode;

typedef struct {
	LP_DuLNode head;
	int len;
}DuLinkList;

extern Status MakeNode( LP_DuLNode&p , ElemType e );
extern void FreeNode( LP_DuLNode& p);

Status InitList_DuL( DuLinkList& L );
Status DestroyList_DuL( DuLinkList& L );
Status ClearList_DuL( DuLinkList& L);
Status InsFirst_DuL(  DuLinkList& L , LP_DuLNode s );
Status DelFirst_DuL(  DuLinkList& L , LP_DuLNode& q );
Status Append_DuL( DuLinkList& L , LP_DuLNode s );
Status Remove_DuL( DuLinkList& L , LP_DuLNode& q );
Status InsBefore_DuL( DuLinkList& L , LP_DuLNode& p , LP_DuLNode s );
Status InsAfter_DuL( DuLinkList& L , LP_DuLNode& p , LP_DuLNode s );
Status SetCurElem_DuL( LP_DuLNode p , ElemType e );
Status GetCurElem_DuL( LP_DuLNode p , ElemType& e);
Status ListEmpty_DuL( DuLinkList L );
int	   ListLength_DuL( DuLinkList L );
LP_DuLNode		GetHead_DuL( DuLinkList L );
LP_DuLNode		GetLast_DuL( DuLinkList L);
LP_DuLNode		PriorPos_DuL( DuLinkList L , LP_DuLNode p);
LP_DuLNode		NextPos_DuL( DuLinkList L , LP_DuLNode p);
Status  LocatePos_DuL( DuLinkList L , int i , LP_DuLNode& p );
LP_DuLNode		LocateElem_DuL( DuLinkList L , ElemType e , PFCOMPARE cmp );
Status  ListTraverse_DuL( DuLinkList L , PFVISIT visit );

Status MergeList_DuL( DuLinkList& La , DuLinkList& Lb , DuLinkList& Lc , PFCOMPARE cmp );
