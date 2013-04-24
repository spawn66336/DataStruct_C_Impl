#pragma once

#define MaxVertices 100					//������Ŀ�����ֵ

enum E_GRAPH_TYPE{
	E_DIGRAPH = 1,	//����ͼ
	E_UNDIGRAPH		//����ͼ
};

typedef struct {
	int name;		//��������
	int visited;		//��Ǹö����Ƿ񱻷�����
	int info;			//������Ϣ
}VertexType;

typedef struct {
	int v;		//��β
	int w;	//��ͷ
}ArcPair;

typedef int WeightType;  //��Ȩ����
 
typedef int (*PFVISIT)( const VertexType& v ); 
extern int OutputVertex( const VertexType& v  );