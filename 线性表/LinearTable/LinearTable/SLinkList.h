#pragma once
#include "def.h"

#define SLINKLIST_MAXSIZE 100
typedef struct{
	ElemType data;
	int			next;
}SL_Node , SLinkList[SLINKLIST_MAXSIZE];
 

extern void InitSpace_SL( SLinkList& space  ); 
extern int Malloc_SL( SLinkList& space );
extern void Free_SL( SLinkList& space , int k );

extern Status InitList( int& L );
extern Status DestroyList( int& L );
extern Status ListEmpty( const int L );
extern Status ListLength( const int L );
extern Status GetElem( const int L , const int i , ElemType& e );
extern Status LocateElem( const int L , const ElemType& e , PFCOMPARE cmp );
extern Status PriorElem( const int L , const ElemType& cur_e , ElemType& pre_e );
extern Status NextElem( const int L , const ElemType& cur_e , ElemType& next_e );
extern Status ListInsert( const int L , const int i , const ElemType& e );
extern Status ListDelete( const int L , const int i , ElemType& e );
extern void ListTraverse( const int L , PFVISIT visit );