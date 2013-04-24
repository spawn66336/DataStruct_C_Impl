#pragma once
#include "def.h"

typedef struct ArcNode{
	int adjvex;						//�û���ָ��Ķ����λ��
	WeightType cost;			//��Ȩͼ�еı�Ȩֵ
	struct ArcNode* nextarc; //ָ����һ������ָ��
}ArcNode;

typedef struct {
	VertexType data;			//��������
	ArcNode* firstarc;			//ָ���һ�������ö���Ļ�ָ��
}Vnode , AdjList[MaxVertices];

typedef struct {
	int type;						//ͼ������
	int vexnum , arcnum;	//�������뻡��
	AdjList vertices;				//�����б�
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