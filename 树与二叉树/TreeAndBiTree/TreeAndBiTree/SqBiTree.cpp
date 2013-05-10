#include "SqBiTree.h"
#include <string.h>
#include <lmcons.h>

void InitSqBiTree_Sq( SqBiTree& T , const int maxnum )
{
	//若该树已存在 则返回
	if( T.nodes )
	{
		return;
	}

	T.nodesCapacity = maxnum;
	T.nodes = new TElemType[maxnum];
	memset( T.nodes , 0 , sizeof(TElemType)*maxnum );
	for( int i = 0 ; i < maxnum ; i++ )
	{
		T.nodes[i] = -1;
	}
	return;
}

void DestroySqBiTree_Sq( SqBiTree& T )
{
	//该二叉树没有初始化
	if( NULL == T.nodes )
	{
		return;
	}

	T.nodesCapacity = 0;
	delete[] T.nodes;
	T.nodes = NULL;
	return;
}

void ClearBiTree_Sq( SqBiTree& T )
{
	if( T.nodes )
	{
		for( int i = 0 ; i < T.nodesCapacity ; i++ )
		{
			T.nodes[i] = -1;
		}
	}
}

bool BiTreeEmpty_Sq( SqBiTree& T )
{
	if( T.nodes )
	{
		if( T.nodes[0] != -1 )
		{
			return true;
		}
		return false;
	}
	return false;
}

int BiTreeDepth_Sq( SqBiTree& T )
{
	if( BiTreeEmpty_Sq(T) )
	{
		return 0;
	}
	return _CalcBiTreeDepth_Sq( T , 0 );
}

int _CalcBiTreeDepth_Sq( SqBiTree& T , const int root_indx )
{
	if( root_indx >= T.nodesCapacity )
	{
		return 0;
	}

	if( T.nodes[root_indx] != -1 )
	{
		int left_subtree_depth = _CalcBiTreeDepth_Sq( T , root_indx*2+1 );
		int right_subtree_depth = _CalcBiTreeDepth_Sq( T , root_indx*2+2 );
		int max_subtree_depth = left_subtree_depth > right_subtree_depth ? left_subtree_depth : right_subtree_depth;
		return 1 + max_subtree_depth;
	}
	return 0;
}

 

int Root_Sq( SqBiTree& T , TElemType& e )
{
	if( BiTreeEmpty_Sq(T) )
	{
		return 0;
	}
	e = T.nodes[0];
	return 1;
}

int Value_Sq( SqBiTree& T , const int i , TElemType& e )
{
	if( BiTreeEmpty_Sq(T) )
	{
		return 0;
	}
	if( i >= T.nodesCapacity )
	{
		return 0;
	}

	e = T.nodes[i];
	return 1;
}

int Assign_Sq( SqBiTree& T , const int i , const TElemType& e )
{
	if( BiTreeEmpty_Sq(T) )
	{
		return 0;
	}
	if( i >= T.nodesCapacity )
	{
		return 0;
	}
	T.nodes[i] = e;
	return 1;
}

int Parent_Sq( SqBiTree& T , const int i , int& parent_indx )
{
	if( BiTreeEmpty_Sq(T) )
	{
		return 0;
	}

	if( i >= T.nodesCapacity )
	{
		return 0;
	}

	//若该节点索引是根节点则根节点再无父节点
	if( i == 0 )
	{
		return 0;
	}

	parent_indx = (i-1)>>1;
	return 1;
}

int LeftChild_Sq( SqBiTree& T , const int i , int& left_indx )
{
	if( BiTreeEmpty_Sq(T) )
	{
		return 0;
	} 
	if( i >= T.nodesCapacity )
	{
		return 0;
	} 
	int left_child_indx = (i<<1)+1;
	if( left_child_indx >= T.nodesCapacity )
	{
		return 0;
	}
	left_indx = left_child_indx;
	return 1;
}

int RightChild_Sq( SqBiTree& T , const int i , int& right_indx )
{
	if( BiTreeEmpty_Sq(T) )
	{
		return 0;
	} 
	if( i >= T.nodesCapacity )
	{
		return 0;
	} 
	int right_child_indx = (i<<1)+2;
	if( right_child_indx >= T.nodesCapacity )
	{
		return 0;
	}
	right_indx = right_child_indx;
	return 1;
}

int InsertChild_Sq( SqBiTree& T , const int p , const int left_or_right , SqBiTree& insert_subtree )
{
	if( BiTreeEmpty_Sq(T) )
	{
		return 0;
	}

	if( insert_subtree.nodesNum == 0 )
	{
		return 0;
	}

	if( insert_subtree.nodesNum + T.nodesNum > T.nodesCapacity )
	{
		return 0;
	}
	
	if( p < 0 || p >= T.nodesCapacity )
	{
		return 0;
	}

	if( T.nodes[p] == -1 )
	{
		return 0;
	}

	
	
	return 1;
}

int DeleteChild_Sq( SqBiTree& T , const int p , const int left_or_right )
{
	return 0;
}

void PreOrderTraverse_Sq( SqBiTree& T , PFVISIT visit )
{

}

void InOrderTraverse_Sq( SqBiTree& T , PFVISIT visit )
{

}

void PostOrderTravers_Sq( SqBiTree& T , PFVISIT visit )
{

}

void LevelOrderTravers_Sq( SqBiTree& T , PFVISIT visit )
{

}

int LeftSibling_Sq( SqBiTree& T , const int i , int& left_sib_indx )
{
	return 0;
}

int RightSibling_Sq( SqBiTree& T , const int i , int& right_sib_indx )
{
	return 0;
}
