#pragma once

#include "def.h"

typedef struct BiTNode {
	TElemType data; //结点所带数据
	struct BiTNode *parent ,*lchild , *rchild;
}BiTNode , *BiTree;

extern void InitBiTree_Link( BiTree* T  );
extern void DestroyBiTree_Link( BiTree* T );
extern BiTNode* AllocNode_Link( const TElemType e );
extern void ClearBiTree_Link( BiTree T );
extern bool BiTreeEmpty_Link( BiTree T );
extern int BiTreeDepth_Link( BiTree T );  
extern BiTNode* Root_Link( BiTree T  );  
extern BiTNode* LeftSibling_Link( BiTree T , BiTNode* node  );
extern BiTNode* RightSibling_Link( BiTree T , BiTNode* node  );
extern int InsertChild_Link( BiTree T , BiTNode* node  , const int left_or_right , BiTree insert_subtree  );
extern int DeleteChild_Link( BiTree T , BiTNode* node , const int left_or_right ); 
extern void PreOrderTraverse_Link( BiTree T , PFVISIT visit = Visit_Print );
extern void InOrderTraverse_Link( BiTree T , PFVISIT visit = Visit_Print );
extern void PostOrderTravers_Link( BiTree T , PFVISIT visit = Visit_Print );
extern void LevelOrderTravers_Link( BiTree T , PFVISIT visit = Visit_Print );