#include "ALGraph.h"
#include <string.h>
#include <queue>

using namespace std;

int CreateGraph_AL( ALGraph& g , VertexType vset[] , const int vnum , ArcPair arcset[] , const int arcnum , const int graph_type )
{
	if( vnum > MaxVertices )
	{
		return 0;
	}
	 
	g.vexnum = vnum;
	g.type = graph_type;

	memset( &g.vertices , 0 , sizeof(Vnode)*MaxVertices );

	//加入顶点
	for( int i = 0 ; i < vnum ; i++ )
	{
		memcpy( &( g.vertices[i].data ) , &vset[i] , sizeof(vset[i]) ); 
	}
	 
	//加入边 
	g.arcnum = 0;
	for( int i = 0 ; i < arcnum ; i++ )
	{ 
		int vindx = 0;
		int windx = 0;
		if( 
			LocateVex_AL( g , arcset[i].v , vindx ) &&
			LocateVex_AL( g , arcset[i].w , windx )
		)
		{ 
			if( g.type == E_UNDIGRAPH )
			{//无向图
				ArcNode* lp_arc_out = AllocArcNode();
				ArcNode* lp_arc_in = AllocArcNode();

				lp_arc_out->adjvex = windx;
				lp_arc_in->adjvex = vindx;

				lp_arc_out->nextarc = g.vertices[vindx].firstarc;
				g.vertices[vindx].firstarc = lp_arc_out;

				lp_arc_in->nextarc = g.vertices[windx].firstarc;
				g.vertices[windx].firstarc = lp_arc_in;

				g.arcnum+=2;

			}else{//有向图
				ArcNode* lp_arc_out = AllocArcNode();
				lp_arc_out->adjvex = windx;

				lp_arc_out->nextarc = g.vertices[vindx].firstarc;
				g.vertices[vindx].firstarc = lp_arc_out;

				g.arcnum++;
			}
		}
	}//for
	return 1;
}

int DestroyGraph_AL( ALGraph& g )
{
	for( int i = 0 ; i < g.vexnum ; i++ )
	{
		ArcNode* lp_del_arc = g.vertices[i].firstarc;
		while( lp_del_arc )
		{
			ArcNode* lp_next_del_arc = lp_del_arc->nextarc;
			delete lp_del_arc;
			lp_del_arc = lp_next_del_arc;
		}
	}
	g.type = 0;
	g.vexnum = 0;
	g.arcnum = 0;

	return 1;
}

int LocateVex_AL( ALGraph& g , const int vname , int& vindx )
{
	for( int i = 0 ; i < g.vexnum ; i++ )
	{
		if( g.vertices[i].data.name == vname )
		{
			vindx = i;
			return 1;
		}
	}
	return 0;
}

 int GetVex_AL( ALGraph& g , const int vindx , VertexType& v )
{
	if( 
		vindx < 0 || 
		vindx >= g.vexnum 
		)
	{
		return 0;
	}

	memcpy( &v , &( g.vertices[vindx].data) , sizeof(v) );
	return 1;
}

int PutVex_AL( ALGraph& g , const int vindx , const VertexType& v )
{
	if( 
		vindx < 0 || 
		vindx >= g.vexnum 
		)
	{
		return 0;
	}

	memcpy(  &( g.vertices[vindx].data) , &v ,  sizeof(v) );
	return 1;
}

int FirstAdjVex_AL( ALGraph& g , const int vindx , int& firstindx )
{
	if( 
		vindx < 0 || 
		vindx >= g.vexnum 
		)
	{
		return 0;
	}

	if( g.vertices[vindx].firstarc )
	{
		firstindx = g.vertices[vindx].firstarc->adjvex;
		return 1;
	}
	return 0;
}

int NextAdjVex_AL( ALGraph& g , const int vindx , const int windx , int& nextindx )
{
	if( 
		vindx < 0 || 
		vindx >= g.vexnum ||
		windx < 0 ||
		windx >= g.vexnum
		)
	{
		return 0;
	}

	ArcNode* curr_arc = g.vertices[vindx].firstarc;
	while( curr_arc )
	{
		if( curr_arc->adjvex == windx )
		{
			if( curr_arc->nextarc )
			{
				nextindx = curr_arc->nextarc->adjvex;
				return 1;
			}
			return 0;
		}
		curr_arc = curr_arc->nextarc;
	}
	return 0;
}

int InsertVex_AL( ALGraph& g , const VertexType& v )
{
	if( g.vexnum+1 > MaxVertices )
	{
		return 0;
	}

	//若找到同名结点则退出
	for( int i = 0 ; i < g.vexnum ; i++ )
	{
		if( g.vertices[i].data.name == v.name )
		{
			return 0;
		}
	}

	memcpy( &(g.vertices[g.vexnum].data) , &v , sizeof(v) );
	g.vertices[g.vexnum].firstarc = NULL;
	g.vexnum++;
	return 1;
}

int DeleteVex_AL( ALGraph& g , const int vindx )
{
	if( 
		vindx < 0 || 
		vindx >= g.vexnum 
		)
	{
		return 0;
	}

	//删除当前结点的出边
	ArcNode* lp_del_arc = g.vertices[vindx].firstarc;
	while( lp_del_arc )
	{
		ArcNode* lp_next_del_arc = lp_del_arc->nextarc;
		delete lp_del_arc;
		lp_del_arc = lp_next_del_arc;
	}

	//删除该顶点的入边
	for( int i = 0 ; i < g.vexnum ; i++ )
	{
		lp_del_arc = g.vertices[i].firstarc;
		ArcNode** lpp_pre_arc = &(g.vertices[i].firstarc);
		while( lp_del_arc )
		{
			if( lp_del_arc->adjvex == vindx )
			{
				(*lpp_pre_arc) = lp_del_arc->nextarc;
				delete lp_del_arc;
				lp_del_arc = NULL;
				break;
			}
			lpp_pre_arc = &(lp_del_arc->nextarc);
			lp_del_arc = lp_del_arc->nextarc;
		}
	}

	for( int i = vindx+1 ; i < g.vexnum ; i ++ )
	{
		memcpy( &g.vertices[i-1] , &g.vertices[i] , sizeof(Vnode) );
	}
	g.vexnum--;
	return 1;
}

int InsertArc_AL( ALGraph& g , const int vindx , const int windx )
{
	if( 
		vindx < 0 || 
		vindx >= g.vexnum ||
		windx < 0 ||
		windx >= g.vexnum
		)
	{
		return 0;
	}
	
	
	for( 
			ArcNode* lp_curr = g.vertices[vindx].firstarc ;
			lp_curr ; lp_curr = lp_curr->nextarc 
		)
	{
		//已找到相同的边
		if( lp_curr->adjvex == windx )
		{
			return 0;
		}
	}

	ArcNode* lp_new_out_arc = AllocArcNode();
	lp_new_out_arc->adjvex = windx; 
	lp_new_out_arc->nextarc = g.vertices[vindx].firstarc;
	g.vertices[vindx].firstarc = lp_new_out_arc;

	if( g.type == E_UNDIGRAPH )
	{
		ArcNode* lp_new_in_arc = AllocArcNode();
		lp_new_in_arc->adjvex = vindx;
		lp_new_in_arc->nextarc = g.vertices[windx].firstarc;
		g.vertices[windx].firstarc = lp_new_in_arc;
	}
	return 1;
}

int DeleteArc_AL( ALGraph& g , const int vindx , const int windx )
{
	if( 
		vindx < 0 || 
		vindx >= g.vexnum ||
		windx < 0 ||
		windx >= g.vexnum
		)
	{
		return 0;
	}

	ArcNode* lp_del_arc = g.vertices[vindx].firstarc;
	ArcNode** lpp_pre_arc = &( g.vertices[vindx].firstarc );
	while( lp_del_arc )
	{
		if( lp_del_arc->adjvex == windx )
		{
			(*lpp_pre_arc) = lp_del_arc->nextarc;
			delete lp_del_arc;
			break;
		}
		lpp_pre_arc = &(lp_del_arc->nextarc);
		lp_del_arc = lp_del_arc->nextarc;
	}
	 
	//若为无向图
	if( g.type == E_UNDIGRAPH )
	{
		lp_del_arc = g.vertices[windx].firstarc;
		lpp_pre_arc = &(g.vertices[windx].firstarc);
		while( lp_del_arc )
		{
			if( lp_del_arc->adjvex == vindx )
			{
				(*lpp_pre_arc) = lp_del_arc->nextarc;
				delete lp_del_arc;
				break;
			}
			lpp_pre_arc = &(lp_del_arc->nextarc);
			lp_del_arc = lp_del_arc->nextarc;
		}
	}
	return 1;
}

int DFSTraverse_AL( ALGraph& g , PFVISIT visit )
{
	for( int i = 0; i < g.vexnum ; i++ )
	{
		g.vertices[i].data.visited = false;
	}

	for( int i = 0 ; i < g.vexnum ; i++ )
	{
		if( g.vertices[i].data.visited == false )
		{
			DFS_AL( g , i , visit );
		}
	}
	return 1;
}

void DFS_AL( ALGraph& g , const int vindx , PFVISIT visit )
{
	visit( g.vertices[vindx].data );
	g.vertices[vindx].data.visited = true;

	int curr_adjindx = 0; 
	int next_adjindx = 0;
	if( FirstAdjVex_AL( g , vindx , next_adjindx ) )
	{
		do{
			curr_adjindx = next_adjindx;
			if( g.vertices[curr_adjindx].data.visited == false )
			{
				DFS_AL( g , curr_adjindx , visit );
			}
		}while( NextAdjVex_AL( g , vindx , curr_adjindx , next_adjindx ) );
	}
}

int BFSTraverse_AL( ALGraph& g , PFVISIT visit )
{
	for( int i = 0; i < g.vexnum ; i++ )
	{
		g.vertices[i].data.visited = false;
	}

	for( int i = 0 ; i < g.vexnum ; i++ )
	{
		if( g.vertices[i].data.visited == false )
		{
			g.vertices[i].data.visited = true;
			BFS_AL( g , i , visit );
		}
	}
	return 1;
}

 void BFS_AL( ALGraph& g , const int vindx , PFVISIT visit )
{
	queue<int> q;
	q.push(vindx);

	while( q.size() )
	{
		int visit_vindx = q.front();
		q.pop();

		visit( g.vertices[visit_vindx].data );

		int curr_adjindx = 0;
		int next_adjindx = 0;
		if( FirstAdjVex_AL( g , visit_vindx , next_adjindx ) )
		{
			do{
				curr_adjindx = next_adjindx;
				if( g.vertices[curr_adjindx].data.visited == false )
				{
					g.vertices[curr_adjindx].data.visited = true;
					q.push( curr_adjindx );
				}
			}while( NextAdjVex_AL( g , visit_vindx , curr_adjindx , next_adjindx) );
		}
	}

}

 ArcNode* AllocArcNode( void )
 {
	 ArcNode* lp_new_node = new ArcNode;
	 lp_new_node->adjvex = 0;
	 lp_new_node->cost = 0;
	 lp_new_node->nextarc = NULL;
	 return lp_new_node;
 }
