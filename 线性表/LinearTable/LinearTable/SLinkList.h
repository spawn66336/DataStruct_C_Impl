#pragma once
#include "def.h"

#define SLINKLIST_MAXSIZE 100
typedef struct{
	ElemType data;
	int			next;
}SL_Node , SLinkList[SLINKLIST_MAXSIZE];
 

extern void InitSpace_SL( SLinkList& space  ); 
extern void InitSpace_SL(void);
extern int Malloc_SL( SLinkList& space );
extern void Free_SL( SLinkList& space , int k );
extern int GetCapacity_SL(void);
extern int GetAllocSize_SL(void);

extern Status InitList_SL( int& L );
extern Status DestroyList_SL( int& L );
extern Status ListEmpty_SL( const int L );
extern Status ListLength_SL( const int L );
extern Status GetElem_SL( const int L , const int i , ElemType& e );
extern Status LocateElem_SL( const int L , const ElemType& e , PFCOMPARE cmp );
extern Status PriorElem_SL( const int L , const ElemType& cur_e , ElemType& pre_e );
extern Status NextElem_SL( const int L , const ElemType& cur_e , ElemType& next_e );
extern Status ListInsert_SL( const int L , const int i , const ElemType& e );
extern Status ListDelete_SL( const int L , const int i , ElemType& e );
extern void ListTraverse_SL( const int L , PFVISIT visit );
extern void MergeList_SL( const int La , const int Lb , const int Lc );
extern void Difference_SL( const int La , const int Lb , int& S );