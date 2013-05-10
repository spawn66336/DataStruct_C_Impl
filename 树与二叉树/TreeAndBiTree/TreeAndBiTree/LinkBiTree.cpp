#include "LinkBiTree.h"
#include <stack>
#include <queue>

using namespace std;

void InitBiTree_Link( BiTree* T )
{
	if( *T != NULL )
	{
		return;
	}
	*T = AllocNode_Link(1);
}

void DestroyBiTree_Link( BiTree* T )
{
	if( *T )
	{
		queue<BiTNode*> q;
		stack<BiTNode*> del_stack;

		q.push(*T);
		while( !q.empty() )
		{
			del_stack.push( q.front() );
			if( q.front()->lchild )
			{
				q.push(q.front()->lchild);
			}
			if( q.front()->rchild )
			{
				q.push(q.front()->rchild);
			}
			q.pop();
		}

		while( !del_stack.empty() )
		{
			if( del_stack.top() )
			{
				del_stack.top()->lchild = NULL;
				del_stack.top()->rchild = NULL;
				delete del_stack.top();
			}
			del_stack.pop();
		} 
		*T = NULL;
	}
}

void ClearBiTree_Link( BiTree T )
{
	if( T )
	{
		queue<BiTNode*> q;
		stack<BiTNode*> del_stack;

		if( T->lchild )
		{
			q.push(T->lchild);
		}
		if( T->rchild )
		{
			q.push(T->rchild );
		}

		while( !q.empty() )
		{
			del_stack.push( q.front() );
			if( q.front()->lchild )
			{
				q.push(q.front()->lchild);
			}
			if( q.front()->rchild )
			{
				q.push(q.front()->rchild);
			}
			q.pop();
		}

		while( !del_stack.empty() )
		{
			if( del_stack.top() )
			{
				del_stack.top()->parent = NULL;
				del_stack.top()->lchild = NULL;
				del_stack.top()->rchild = NULL;
				delete del_stack.top();
			}
			del_stack.pop();
		} 
		
		T->lchild = T->rchild = NULL;
	}
}

  bool BiTreeEmpty_Link( BiTree T )
{
	return ( T->lchild == NULL && T->rchild == NULL );
}

  int BiTreeDepth_Link( BiTree T )
{
	if( T == NULL )
	{
		return 0;
	}

	int left_subtree_depth = BiTreeDepth_Link( T->lchild );
	int right_subtree_depth = BiTreeDepth_Link( T->rchild );
	int max_depth = left_subtree_depth > right_subtree_depth ? left_subtree_depth : right_subtree_depth ;
	return max_depth+1;
}

 BiTNode* Root_Link( BiTree T )
{
	return T;
}
   
BiTNode* LeftSibling_Link( BiTree T , BiTNode* node )
{
	//若为根节点则没有左兄弟
	if( node->parent == NULL )
	{
		return NULL;
	}

	//若该结点为父节点的右孩子，则该左兄弟为父节点的左孩子
	if( node->parent->rchild == node )
	{
		return node->parent->lchild;
	}

	//若该结点为父节点的左孩子，则查看其父节点是否还存在父节点
	if( node->parent->parent == NULL )
	{
		return NULL;
	}

	if( node->parent->parent->rchild  == node->parent )
	{
		if( node->parent->parent->lchild )
		{
			return node->parent->parent->lchild->rchild;
		}
	}

	return NULL;
}

BiTNode* RightSibling_Link( BiTree T , BiTNode* node )
{
	//若为根节点则没有右兄弟
	if( node->parent == NULL )
	{
		return NULL;
	}

	//若该结点为父节点的左孩子，则该右兄弟为父节点的右孩子
	if( node->parent->lchild == node )
	{
		return node->parent->rchild;
	}
	
	//若该节点为父节点的右孩子，查看该节点的父节点是否有父节点
	if( node->parent->parent == NULL )
	{
		return NULL;
	}

	if( node->parent->parent->lchild  == node->parent )
	{
		if( node->parent->parent->rchild )
		{
			return node->parent->parent->rchild->lchild;
		}
	}

	return NULL;
}

int InsertChild_Link( BiTree T , BiTNode* node , const int left_or_right , BiTree insert_subtree )
{
	if( node == NULL || insert_subtree == NULL )
	{
		return 0;
	}

	if( insert_subtree->rchild != NULL )
	{
		return 0;
	}

	BiTree sub_tree = NULL;
	//插入该节点的左子树
	if( left_or_right == 1 )
	{
		sub_tree = node->lchild;
		node->lchild = insert_subtree;
		insert_subtree->rchild = sub_tree;
		insert_subtree->parent = node;
	}else{
		sub_tree = node->rchild;
		node->rchild = insert_subtree;
		insert_subtree->rchild = sub_tree;
		insert_subtree->parent = node;
	} 

	return 1;
}

int DeleteChild_Link( BiTree T , BiTNode* node , const int left_or_right )
{
	if( node == NULL )
	{
		return 0;
	}

	if( left_or_right )
	{
		DestroyBiTree_Link( &(node->lchild) );
	}else{
		DestroyBiTree_Link( &(node->rchild) );
	}
	return 1;
}

 void PreOrderTraverse_Link( BiTree T , PFVISIT visit )
{
	if( T == NULL )
	{
		return;
	}

	visit( T->data );
	PreOrderTraverse_Link( T->lchild );
	PreOrderTraverse_Link( T->rchild );
}

  void InOrderTraverse_Link( BiTree T , PFVISIT visit )
{
	if( T == NULL )
	{
		return;
	}
	 
	PreOrderTraverse_Link( T->lchild );
	visit( T->data );
	PreOrderTraverse_Link( T->rchild );
}

  void PostOrderTravers_Link( BiTree T , PFVISIT visit )
{
	if( T == NULL )
	{
		return;
	}

	PreOrderTraverse_Link( T->lchild );
	PreOrderTraverse_Link( T->rchild ); 
	visit( T->data );
}

 void LevelOrderTravers_Link( BiTree T , PFVISIT visit )
{
	if( T == NULL )
	{
		return;
	}

	queue<BiTNode*> q;
	q.push( T );

	while( !q.empty() )
	{
		visit( q.front()->data );
		if( q.front()->lchild )
		{
			q.push( q.front()->lchild );
		}
		if( q.front()->rchild )
		{
			q.push( q.front()->rchild );
		}
		q.pop();
	}

}

 BiTNode* AllocNode_Link( const TElemType e )
 {
	 BiTNode* node = new BiTNode;
	 node->data = e;
	 node->parent = node->lchild = node->rchild = NULL;
	 return node;
 }
