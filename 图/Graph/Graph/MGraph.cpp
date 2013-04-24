#include "MGraph.h"
#include <iostream>
#include <queue>


using namespace std;

int OutputVertex( const VertexType& v )
{
	cout<<v.name<<" ";
	return 1;
}

 int CreateGraph( MGraph& g , VertexType vset[] , const int vnum , ArcPair arcset[] , const int arcnum , const int graph_type )
{

	if( vnum > MaxVertices )
	{
		return 0;
	}
	 
	g.vexnum = vnum;
	g.type = graph_type;

	for( int i = 0 ; i < vnum ; i++ )
	{
		memcpy( &g.vexs[i] , &vset[i] , sizeof(vset[i]) );
	}

	g.arcnum = 0;

	for( int i = 0 ; i < arcnum ; i++ )
	{
		int vindx = 0;
		int windx = 0;
		if( 
			LocateVex( g , arcset[i].v , vindx ) &&
			LocateVex( g , arcset[i].w , windx )
		)
		{
			if( graph_type == E_DIGRAPH )
			{//有向图
				g.arc[vindx*MaxVertices+windx] = 1;
				g.arcnum++;
			}else{ // 无向图
				g.arc[vindx*MaxVertices+windx] = 1;
				g.arc[windx*MaxVertices+vindx] = 1;
				g.arcnum += 2;
			}
		}else{//为非法边
			continue;
		}
	}

	return 1;
}

 int DestroyGraph( MGraph& g )
{
	memset( &g , 0 , sizeof(g) );
	return 1;
}

 int LocateVex( MGraph& g , const int vname , int& vindx )
{
	for( int i = 0 ; i < g.vexnum ; i++ )
	{
		if( g.vexs[i].name == vname )
		{
			vindx = i;
			return 1;
		}
	}
	return 0;
}

 int GetVex( MGraph& g , const int vindx , VertexType& v )
{
	if( vindx < g.vexnum && vindx >= 0 )
	{
		memcpy( &v , &g.vexs[vindx] , sizeof(v) );
		return 1;
	}
	return 0;
}

 int PutVex( MGraph& g , const int vindx , const VertexType& v )
{
	if( vindx < g.vexnum && vindx >= 0 )
	{
		memcpy( &g.vexs[vindx] , &v , sizeof(v) );
		return 1;
	}
	return 0;
}

 int FirstAdjVex( MGraph& g , const int vindx , int& firstindx )
{
	if( 
		vindx >= g.vexnum ||
		vindx < 0 
		)
	{
		return 0;
	}

	for( int i = 0 ;  i < g.vexnum ; i++ )
	{
		if( g.arc[vindx*MaxVertices+i] )
		{
			firstindx = i;
			return 1;
		}
	}
	return 0;
}

 int NextAdjVex( MGraph& g , const int vindx , const int windx , int& nextindx )
{
	if( 
		vindx >= g.vexnum ||
		vindx < 0 || 
		windx >= g.vexnum ||
		windx < 0 
		)
	{
		return 0;
	}


	for( int i = windx+1 ;  i < g.vexnum ; i++ )
	{
		if( g.arc[vindx*MaxVertices+i] )
		{
			nextindx = i;
			return 1;
		}
	} 

	return 0;
}

 int InsertVex( MGraph& g , const VertexType& v )
{
	if( g.vexnum+1 > MaxVertices )
	{
		return 0;
	}

	memcpy( &g.vexs[g.vexnum] , &v , sizeof(VertexType) );

	for( int i = 0 ; i < MaxVertices ; i++ )
	{
		g.arc[g.vexnum*MaxVertices+i] = 0;
	}

	for( int i = 0 ; i < MaxVertices ; i++ )
	{
		g.arc[i*MaxVertices+g.vexnum] = 0;
	}

	g.vexnum++;
	return 1;
}

 int DeleteVex( MGraph& g , const int vindx )
{
	//若顶点索引不在范围内
	if( vindx >= g.vexnum ||
		vindx < 0 )
	{
		return 0;
	}

	for( int i = vindx+1 ; i < g.vexnum ; i++ )
	{
		memcpy( &g.vexs[i-1] , &g.vexs[i] , sizeof(VertexType) );
	}

	int curr_vex_arc_num = 0;
	for( int i = 0 ; i < g.vexnum ; i++ )
	{
		if( g.arc[i*MaxVertices+vindx] )
			curr_vex_arc_num++;
	}
	for( int i = 0 ; i < g.vexnum ; i++ )
	{
		if( g.arc[vindx*MaxVertices+i] )
			curr_vex_arc_num++;
	}

	for( int i = vindx+1 ; i < g.vexnum ; i ++ )
	{
		for( int j = 0 ; j < g.vexnum ; j++ )
		{
			g.arc[j*MaxVertices+i-1] = g.arc[j*MaxVertices+i];
		}
	}

	for( int i = vindx+1 ; i < g.vexnum ; i++ )
	{
		for( int j = 0 ; j < g.vexnum-1 ; j++ )
		{
			g.arc[(i-1)*MaxVertices+j] = g.arc[i*MaxVertices+j];
		}
	}

	g.arcnum -= curr_vex_arc_num;
	g.vexnum--;
	return 1;
}

 int InsertArc( MGraph& g , const int vindx , const int windx )
{
	if( vindx < 0 ||
		vindx >= g.vexnum ||
		windx < 0 ||
		windx >= g.vexnum 
		)
	{
		return 0;
	}
	if( vindx == windx )
	{
		return 0;
	}

	g.arc[vindx*MaxVertices+windx] = 1;
	if( g.type == E_UNDIGRAPH )
	{
		g.arc[windx*MaxVertices+vindx] = 1;
	}
	return 1;
}

 int DeleteArc( MGraph& g , const int vindx , const int windx )
{
	if( vindx < 0 ||
		vindx >= g.vexnum ||
		windx < 0 ||
		windx >= g.vexnum 
		)
	{
		return 0;
	}
	if( vindx == windx )
	{
		return 0;
	}
	g.arc[vindx*MaxVertices+windx] = 0;
	if( g.type == E_UNDIGRAPH )
	{
		g.arc[windx*MaxVertices+vindx] = 0;
	}
	return 1;
}

 int DFSTraverse( MGraph& g , PFVISIT visit )
{
	for( int i = 0 ; i < g.vexnum ; i++ )
	{
		g.vexs[i].visited = false;
	}

	for( int i = 0 ; i < g.vexnum ; i++ )
	{
		if( g.vexs[i].visited == false )
		{
			DFS_M(g,i,visit);
		}
	}
	return 1;
}
  
 void DFS_M( MGraph& g , const int vindx ,  PFVISIT visit )
 {
	 visit( g.vexs[vindx] );
	 g.vexs[vindx].visited = true;

	 int curr = 0; 
	 int next = 0;

	 if( FirstAdjVex(g,vindx,next) )
	 {

		 do{
			 curr = next;
			 if( g.vexs[curr].visited == false )
			 {
				DFS_M(g,curr,visit);
			 }
		 }while( NextAdjVex(g,vindx,curr,next) );

	 }
 }


 int BFSTraverse( MGraph& g , PFVISIT visit )
{
	for( int i = 0 ; i < g.vexnum ; i++ )
	{
		g.vexs[i].visited = false;
	}

	for( int i = 0 ; i < g.vexnum ; i++ )
	{
		if( g.vexs[i].visited == false )
		{
			g.vexs[i].visited = true;
			BFS_M( g , i , visit );
		}
	}
	return 0;
}


 void BFS_M( MGraph& g , const int vindx , PFVISIT visit )
 {
	 queue<int> q;
	 q.push(vindx);
	 g.vexs[vindx].visited = true;
	 
	while( q.size() )
	{
		int curr = q.front();
		q.pop();

		visit( g.vexs[curr] );
		
		int adj_indx = 0;
		int next_adj_indx = 0;
		if( FirstAdjVex( g , curr , next_adj_indx ) )
		{
			do{
				adj_indx = next_adj_indx;
				if( g.vexs[adj_indx].visited == false )
				{
					g.vexs[adj_indx].visited = true;
					q.push( adj_indx );
				}
			}while( NextAdjVex( g , curr , adj_indx , next_adj_indx  ) );
		}
	}
 }