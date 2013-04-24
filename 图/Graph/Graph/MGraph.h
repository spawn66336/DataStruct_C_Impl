#pragma once
 
#include "def.h"



typedef struct {
	VertexType vexs[MaxVertices];		//���ͼ�ж������Ϣ
	int arc[MaxVertices*MaxVertices];	//�ڽӾ��󣬴��ͼ�бߵ���Ϣ
	int vexnum , arcnum;				//ͼ�еĶ������ͱ���
	int type;									//ͼ������
} MGraph;								//MGraph���ڽӾ���洢��ͼ����

 

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