#pragma once

#define MaxVertices 100					//顶点数目的最大值

enum E_GRAPH_TYPE{
	E_DIGRAPH = 1,	//有向图
	E_UNDIGRAPH		//无向图
};

typedef struct {
	int name;		//顶点名称
	int visited;		//标记该顶点是否被访问了
	int info;			//顶点信息
}VertexType;

typedef struct {
	int v;		//弧尾
	int w;	//弧头
}ArcPair;

typedef int WeightType;  //边权类型
 
typedef int (*PFVISIT)( const VertexType& v ); 
extern int OutputVertex( const VertexType& v  );