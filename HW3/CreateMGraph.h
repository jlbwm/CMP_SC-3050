#ifndef H_PARSING_H
#define H_PARSING_H

#include <stdio.h>
#include <stdlib.h>

typedef int VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */

#define MAXVEX 100

typedef struct
{
	EdgeType arc[MAXVEX][MAXVEX];/* 邻接矩阵，可看作边表 */
	int numVertexes, numEdges; /* 图中当前的顶点数和边数 */ 
}MGraph;

void CreateMGraph(MGraph *G);



#endif