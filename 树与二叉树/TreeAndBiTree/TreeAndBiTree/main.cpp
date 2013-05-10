#include <iostream>
#include "def.h"
#include "LinkBiTree.h"

using namespace std;


int Visit_Print( const TElemType& e )
{
	cout<<e<<" ";
	return VISIT_CONTINUE;
}
 

void TestBiTree(void)
{
	BiTree T = NULL;
	InitBiTree_Link(&T);

	BiTNode* node2 =  AllocNode_Link(2);
	BiTNode* node3 = AllocNode_Link(3);
	InsertChild_Link(T,T,1,node2);
	InsertChild_Link(T,T,0,node3);

	BiTNode* node4 = AllocNode_Link(4);
	BiTNode* node5 = AllocNode_Link(5);
	BiTNode* node6 = AllocNode_Link(6);
	BiTNode* node7 = AllocNode_Link(7);

	InsertChild_Link(T,node2,1,node4);
	InsertChild_Link(T,node2,0,node5);
	InsertChild_Link(T,node3,1,node6);
	InsertChild_Link(T,node3,0,node7);

	BiTNode* node8 = AllocNode_Link(8);
	BiTNode* node9 = AllocNode_Link(9);
	BiTNode* node10 = AllocNode_Link(10);
	BiTNode* node11 = AllocNode_Link(11);
	BiTNode* node12 = AllocNode_Link(12);
	BiTNode* node13 = AllocNode_Link(13);
	BiTNode* node14 = AllocNode_Link(14);
	BiTNode* node15= AllocNode_Link(15);

	InsertChild_Link(T,node4,1,node8);
	InsertChild_Link(T,node4,0,node9);

	InsertChild_Link(T,node5,1,node10);
	InsertChild_Link(T,node5,0,node11);

	InsertChild_Link(T,node6,1,node12);
	InsertChild_Link(T,node6,0,node13);

	InsertChild_Link(T,node7,1,node14);
	InsertChild_Link(T,node7,0,node15);

	cout<<"前序遍历:";
	PreOrderTraverse_Link(T);
	cout<<endl;
	cout<<"中序遍历:";
	InOrderTraverse_Link(T);
	cout<<endl;
	cout<<"后序遍历:";
	PostOrderTravers_Link(T);
	cout<<endl;
	cout<<"层序遍历:";
	LevelOrderTravers_Link(T);
	cout<<endl;

	DestroyBiTree_Link(&T);
}

void main()
{
	TestBiTree();
}