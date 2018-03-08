#include "parsing.h"
#include "input_error.h"
#include "CreateMGraph.h"
#include "BFSTraverse.h"

#define TRUE 1
#define FALSE 0

void BFSTraverse(MGraph G, FILE* fp)
{
	int i, j;
	int visited[G.numVertexes];
	int distance[G.numVertexes];

	for(i = 0; i < G.numVertexes; i++)
	{
       	visited[i] = FALSE; //将所有节点都变成未访问过的
       	distance[i] = -1;	//将所有节点都变成距离为负
    }

    distance[0] = 0; //给定头结点的距离为0
	
	for(i = 0; i < G.numVertexes; i++)  /* 对每一个顶点做循环 */
    {
		visited[i]=TRUE;		/* 设置当前顶点访问过 */
		for(j=i; j<G.numVertexes; j++) 
		{
			/* 判断其它顶点若与当前顶点存在边且未访问过  */
			if(G.arc[i][j] == 1 && !visited[j]) 
			{ 
				visited[j]=TRUE;/* 将找到的此顶点标记为已访问 */
 				distance[j] = distance[i]+1;/* 将距离加一*/
			} 
				
		}
	}

	for(i = 0; i<G.numVertexes; i++)
	{
		fprintf(fp, "%d\n", distance[i]); //输出各边距离
	}
}