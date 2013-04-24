#include "MGraph.h"
#include "ALGraph.h"

void TestMGraph(void)
{
	MGraph G;
	VertexType V[5];
	for( int i = 0 ; i < 5 ; i++  )
	{
		V[i].name = i+1;
		V[i].visited = false;
		V[i].info = 0;
	}
	ArcPair A[6];
	A[0].v = 1;
	A[0].w = 2;
	A[1].v = 1;
	A[1].w = 4;
	A[2].v = 2;
	A[2].w = 3;
	A[3].v = 3;
	A[3].w = 4;
	A[4].v = 3;
	A[4].w = 5;
	A[5].v = 2;
	A[5].w = 5;

	//CreateGraph(G,V,5,A,6,E_UNDIGRAPH);
	////DFSTraverse(G,OutputVertex);
	//BFSTraverse(G,OutputVertex);
	//DestroyGraph(G);

	ALGraph GAL;
	CreateGraph_AL( GAL,V,5,A,6,E_UNDIGRAPH );
	BFSTraverse_AL( GAL , OutputVertex );
	DestroyGraph_AL( GAL);
}

void main()
{
	TestMGraph();
}