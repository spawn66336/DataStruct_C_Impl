#pragma once
 
#include "def.h"



typedef struct {
	VertexType vexs[MaxVertices];		//存放图中顶点的信息
	int arc[MaxVertices*MaxVertices];	//邻接矩阵，存放图中边的信息
	int vexnum , arcnum;				//图中的顶点数和边数
	int type;									//图的类型
} MGraph;								//MGraph是邻接矩阵存储的图类型

 

extern int CreateGraph( MGraph& g , VertexType vset[] , const int vnum , ArcPair arcset[] , const int arcnum , const int graph_type  );
extern int DestroyGraph( MGraph& g );
extern int LocateVex( MGraph& g , const int vname , int& vindx );
extern int GetVex( MGraph& g , const int vindx , VertexType& v );
extern int PutVex( MGraph& g , const int vindx , const VertexType& v );
extern int FirstAdjVex( MGraph& g , const int vindx  , int& firstindx );
extern int NextAdjVex( MGraph& g , const int vindx , const int windx , int& nextindx );
extern int InsertVex( MGraph& g , const VertexType& v );
extern int DeleteVex( MGraph& g , const int vindx );
extern int InsertArc( MGraph& g , const int vindx , const int windx );
extern int DeleteArc( MGraph& g , const int vindx , const int windx );
extern int DFSTraverse( MGraph& g , PFVISIT visit );
extern void DFS_M( MGraph& g , const int vindx , PFVISIT visit );
extern int BFSTraverse( MGraph& g , PFVISIT visit );
extern  void BFS_M( MGraph& g , const int vindx , PFVISIT visit );