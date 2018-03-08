#include "CreateMGraph.h"

#define MAXVEX 100



typedef int VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */



void CreateMGraph(MGraph *G)
{
	int i, j;

	//G->numEdges = 5;
	//G->numVertexes = 5 ;

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		for ( j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j]=0;
		}
	}

	G->arc[0][0]=0;
	

	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = 0; j < G->numVertexes; j++)
		{
	  		if(G->arc[i][j] == 1 && i>j)
	  		{
	  			G->arc[j][i] = G->arc[i][j];//交换大值防止被覆盖
	  			//printf("G->arc[%d][%d] == %d\n\n", j, i, G->arc[j][i]);
	  		}
	  	}
	 }
	
	for(i = 0; i < G->numVertexes; i++)
	{
	 	for(j = i; j < G->numVertexes; j++)
	 	{
	 		G->arc[j][i] =G->arc[i][j];//有问题，当先赋值的G->arc[0][4]=0会覆盖后边有值的G->arc[4][0]=0
	 	}
	}



 }		