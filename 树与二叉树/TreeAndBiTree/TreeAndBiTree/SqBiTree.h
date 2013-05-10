#pragma once

#include "def.h"

typedef struct {
	int nodesCapacity;	//结点缓冲区最大容量
	int nodesNum;		    //结点数
	TElemType* nodes;   //结点列表
}SqBiTree;

extern void InitSqBiTree_Sq( SqBiTree& T , const int maxnum );
extern void DestroySqBiTree_Sq( SqBiTree& T );
extern void ClearBiTree_Sq( SqBiTree& T );
extern bool BiTreeEmpty_Sq( SqBiTree& T );
extern int BiTreeDepth_Sq( SqBiTree& T );
extern int _CalcBiTreeDepth_Sq( SqBiTree& T , const int root_indx );
extern int Root_Sq( SqBiTree& T , TElemType& e );
extern int Value_Sq( SqBiTree& T , const int i , TElemType& e );
extern int Assign_Sq( SqBiTree& T , const int i , const TElemType& e );
extern int Parent_Sq( SqBiTree& T , const int i , int& parent_indx );
extern int LeftChild_Sq( SqBiTree& T , const int i , int& left_indx );
extern int RightChild_Sq( SqBiTree& T , const int i , int& right_indx );
extern int LeftSibling_Sq( SqBiTree& T , const int i , int& left_sib_indx );
extern int RightSibling_Sq( SqBiTree& T , const int i , int& right_sib_indx );
extern int InsertChild_Sq( SqBiTree& T , const int p , const int left_or_right , SqBiTree& insert_subtree  );
extern int DeleteChild_Sq( SqBiTree& T , const int p , const int left_or_right );

extern void PreOrderTraverse_Sq( SqBiTree& T , PFVISIT visit );
extern void InOrderTraverse_Sq( SqBiTree& T , PFVISIT visit );
extern void PostOrderTravers_Sq( SqBiTree& T , PFVISIT visit );
extern void LevelOrderTravers_Sq( SqBiTree& T , PFVISIT visit );