#pragma once
#include "def.h"

typedef struct ArcNode{
	int adjvex;						//该弧所指向的顶点的位置
	WeightType cost;			//带权图中的边权值
	struct ArcNode* nextarc; //指向下一条弧的指针
}ArcNode;

typedef struct {
	VertexType data;			//顶点数据
	ArcNode* firstarc;			//指向第一条依附该顶点的弧指针
}Vnode , AdjList[MaxVertices];

typedef struct {
	int type;						//图的类型
	int vexnum , arcnum;	//顶点数与弧数
	AdjList vertices;				//顶点列表
}ALGraph;

extern ArcNode* AllocArcNode(void);
extern int CreateGraph_AL( ALGraph& g , VertexType vset[] , const int vnum , ArcPair arcset[] , const int arcnum , const int graph_type  );
extern int DestroyGraph_AL( ALGraph& g );
extern int LocateVex_AL( ALGraph& g , const int vname , int& vindx );
extern int GetVex_AL( ALGraph& g , const int vindx , VertexType& v );
extern int PutVex_AL( ALGraph& g , const int vindx , const VertexType& v );
extern int FirstAdjVex_AL( ALGraph& g , const int vindx  , int& firstindx );
extern int NextAdjVex_AL( ALGraph& g , const int vindx , const int windx , int& nextindx );
extern int InsertVex_AL( ALGraph& g , const VertexType& v );
extern int DeleteVex_AL( ALGraph& g , const int vindx );
extern int InsertArc_AL( ALGraph& g , const int vindx , const int windx );
extern int DeleteArc_AL( ALGraph& g , const int vindx , const int windx );
extern int DFSTraverse_AL( ALGraph& g , PFVISIT visit );
extern void DFS_AL( ALGraph& g , const int vindx , PFVISIT visit );
extern int BFSTraverse_AL( ALGraph& g , PFVISIT visit );
extern  void BFS_AL( ALGraph& g , const int vindx , PFVISIT visit );