#include <stdio.h>
#include <stdlib.h>
#include "input_error.h"

// enum error {
//     INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS = 1,！
//     INPUT_FILE_FAILED_TO_OPEN,！
//     INPUT_FILE_FAILED_TO_CLOSE,！
//     PARSING_ERROR_EMPTY_INPUT_FILE,！
//     OUTPUT_FILE_FAILED_TO_OPEN,！
//     OUTPUT_FILE_FAILED_TO_CLOSE,！
//     INTEGER_IS_NOT_A_VERTEX,
//     PARSING_ERROR_INVALID_FORMAT,
// };

#define TRUE 1
#define FALSE 0

#define MAXVEX 100
#define MAX_LENTH 1024
#define INFINITY 65535


int main(int argc, char** argv) 
{
    int arc[MAXVEX][MAXVEX];
    int numVertexes;
    int value;
    
    int min, node;
    int i, j;


    if (argc != 3)
    {
        exit(INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS);//1
        
    }
    
    FILE* fpin = fopen(argv[1], "r");

    if (!fpin)
    {
        exit(INPUT_FILE_FAILED_TO_OPEN);//2
        
    }
  
    
  
    FILE* fpout = fopen(argv[2], "w");
    if (!fpout)
    {
        exit(OUTPUT_FILE_FAILED_TO_OPEN);//5
    }

    char c = fgetc(fpin);

    if (c==EOF)
    {
    	//fprintf(fpout, "PARSING_ERROR_EMPTY_INPUT_FILE");
        exit(PARSING_ERROR_EMPTY_INPUT_FILE);//4
        

    }
    else if(c>='0' && c<='9')
    {
    	//do nothing
    }
    else
    {
    	//fprintf(fpout, "PARSING_ERROR_INVALID_FORMAT");
    	exit(PARSING_ERROR_INVALID_FORMAT);//8
    }
    ungetc(c, fpin);


    if(fscanf(fpin, "%d", &numVertexes))
    {
        //fprintf(fpout, "%d\n", numVertexes); //get Vertex number
    }

    for (i = 0; i < numVertexes; i++)/* initialize the graph */
    {
        for (j = 0; j < numVertexes; j++)
        {
            arc[i][j] = INFINITY; //all edges are INFINITY
            //fprintf(fpout, "arc[%d][%d] = %d\n", i, j, arc[i][j]);
        }
    }



    char buffer[MAX_LENTH];

    while(fgets(buffer,MAX_LENTH,fpin)!=NULL)
    {

        sscanf(buffer, "(%d,%d,%d)", &i, &j, &value);
        
        if(i<=numVertexes && j<=numVertexes && i>=1 && j>=1)
        {
            arc[i-1][j-1] = value;

        }
        else
        {
        	//fprintf(fpout, "INTEGER_IS_NOT_A_VERTEX");
            exit(INTEGER_IS_NOT_A_VERTEX);//7
            
            
        }
    }
    arc[numVertexes-1][numVertexes-1] = INFINITY; //make sure the last arc is INFINITY


    //output all the edges
    // for (i = 0;  i< numVertexes; i++)
    // {
    //     for (int j = 0; j < numVertexes; j++)
    //     {
    //         fprintf(fpout, "arc[%d][%d] = %d\n", i, j, arc[i][j]);
            
    //     }
    // }

    //fprintf(fpout, "\n");

    int visited[numVertexes];
    int distance[numVertexes];
    int previous[numVertexes];


	for(i = 0; i < numVertexes; i++) //initialization
    {
        visited[i] = FALSE;         //all vertexs are unvisited
        distance[i] = arc[0][i];   //give distance[i] values whose weight is not INFINITY
        previous[i] = 0;
        
    }
    
    distance[0] = 0; // 0 -> 0 is 0
    visited[0] = TRUE;

  
    //find the nearest vertex
    for(i = 1; i<numVertexes; i++)
    {
        min = INFINITY;

        for(j = 0; j<numVertexes; j++)
        {
            if(!visited[j] && distance[j] < min)
            {
                node = j;
                min = distance[j];
                
            }
        }

        visited[node] = TRUE;

        for(int k = 0; k<numVertexes; k++)
        {
            if(!visited[k] && (min + arc[node][k] < distance[k]))
            {
                distance[k] = min + arc[node][k];
                previous[k] = node;
               
            }
        }


    }

    for(i = 0; i < numVertexes; i++)
    {
    	if(distance[i] == INFINITY)
    	{
    	distance[i] = -1;
    	}
        fprintf(fpout, "%d\n", distance[i]);
    }

    
    if (fclose(fpin) == EOF)
    {
        exit(INPUT_FILE_FAILED_TO_CLOSE);   
    }

    if (fclose(fpout) == EOF)
    {
        exit(OUTPUT_FILE_FAILED_TO_CLOSE);
    }

    
    return 0;
    
}