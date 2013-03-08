#pragma once
#include "def.h"

#define LIST_INIT_SIZE 100
#define LIST_INCE_SIZE 10


typedef struct {
	ElemType* lp_elem;
	int			 len;
	int             capacity;
}SqList;


extern Status InitList_Sq( SqList& L );
extern Status DestroyList_Sq( SqList& L);
extern Status ClearList_Sq( SqList& L);
extern Status ListEmpty_Sq( SqList& L);
extern Status ListLength_Sq( SqList& L);
extern Status GetElem_Sq( SqList& L , const int i  , ElemType& e);
extern Pos LocateElem_Sq( SqList& L , const ElemType& e , PFCOMPARE cmp = Compare );
extern Status PriorElem_Sq( SqList& L , const ElemType& cur_e , ElemType& pre_e );
extern Status NextElem_Sq( SqList& L , const ElemType& cur_e , ElemType& next_e );
extern Status ListInsert_Sq( SqList& L , const int i , const ElemType& e);
extern Status ListDelete_Sq( SqList& L , const int i , ElemType& e );
extern Status ListTraverse_Sq( SqList& L , PFVISIT visit );
