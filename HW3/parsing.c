#include "parsing.h"
#include "input_error.h"
#include "CreateMGraph.h"
#include "BFSTraverse.h"

#define MAX_LENTH 1024

#define MAXVEX 100



typedef int VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */





void parse_getline(FILE* fp， MGraph *G) 
{
	int c = fgetc(fp);

    if (c==EOF)
    {
    	exit(PARSING_ERROR_EMPTY_FILE);
    }
    ungetc(c,fp);

    if(fscanf(fp, "%d", &G->numVertexes))
    {
    	//
	}
	else
	{
		exit(PARSING_ERROR_INVALID_FORMAT);
	}

	char buffer[MAX_LENTH];

	while(fgets(buffer,MAX_LENTH,fp)!=NULL)
	{
		int i, j;
		sscanf(buffer, "(%d,%d)", &i, &j);
		if(i<=G->numVertexes && j<=G->numVertexes && i>=1 && j>=1)
		{
			G->arc[i-1][j-1]=1;
		}
		else
		{
			exit(INTEGER_IS_NOT_A_VERTEX);
		}
	}
	
}
