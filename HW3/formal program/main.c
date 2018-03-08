#include <stdio.h>
#include <stdlib.h>

enum error {
    INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS = 1,
    INPUT_FILE_FAILED_TO_OPEN,
    INPUT_FILE_FAILED_TO_CLOSE,
    PARSING_ERROR_EMPTY_INPUT_FILE,
    OUTPUT_FILE_FAILED_TO_OPEN,
    OUTPUT_FILE_FAILED_TO_CLOSE,
    INTEGER_IS_NOT_A_VERTEX,
    PARSING_ERROR_INVALID_FORMAT,
};

#define TRUE 1
#define FALSE 0

#define MAXVEX 100
#define MAX_LENTH 1024


int main(int argc, char** argv) 
{
    int arc[MAXVEX][MAXVEX];
    int numVertexes;
    
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

    int c = fgetc(fpin);

    if (c==EOF)
    {
        exit(PARSING_ERROR_EMPTY_INPUT_FILE);//4
    }
    ungetc(c, fpin);


    if(fscanf(fpin, "%d", &numVertexes))
    {
        //fprintf(fpout, "%d\n", numVertexes); //get Vertex number
    }
    else
    {
        exit(PARSING_ERROR_INVALID_FORMAT);//8
        
    }

    for (i = 0; i < numVertexes; i++)/* initialize the graph */
    {
        for ( j = 0; j < numVertexes; j++)
        {
            arc[i][j] = 0;//all edges are 0
            //fprintf(fpout, "arc[%d][%d] = %d\n", i, j, arc[i][j]);

        }
    }

    char buffer[MAX_LENTH];

    while(fgets(buffer,MAX_LENTH,fpin)!=NULL)
    {

        sscanf(buffer, "(%d,%d)", &i, &j);
        
        if(i<=numVertexes && j<=numVertexes && i>=1 && j>=1)
        {
            arc[i-1][j-1] = 1;
            arc[j-1][i-1] = 1;

        }
        else
        {
            exit(INTEGER_IS_NOT_A_VERTEX);//7
            
        }
    }
    arc[0][0] = 0; //make sure (0,0) = 0
    arc[numVertexes-1][numVertexes-1] = 0; //make sure (0,0) = 0

    for (i = 0; i < numVertexes; i++)/* initialize the graph */
    {
        for ( j = 0; j < numVertexes; j++)
        {
            //fprintf(fpout, "arc[%d][%d] = %d\n", i, j, arc[i][j]);
        }
    }


    int visited[numVertexes];
    int distance[numVertexes];

    for(i = 0; i < numVertexes; i++)
    {
        visited[i] = FALSE; //all vertexs are unvisited
        distance[i] = -1;   //all vertexs' distance is -1  
    }

    distance[0] = 0; //give head vertex distance is 0
    
    for(i = 0; i < numVertexes; i++)  /* loop every vertex */
    {
        visited[i]=TRUE;        /* make it visited */
        for(j=i; j<numVertexes; j++) 
        {
            /* estimate the other vertexs have edge and unvisited */
            if(arc[i][j] == 1 && !visited[j]) 
            { 
                visited[j]=TRUE;/* make is visited */
                distance[j] = distance[i]+1;/* distance +1 */
            } 
                
        }
    }

    for(i = 0; i<numVertexes; i++)
    {
        fprintf(fpout, "%d\n", distance[i]); //out diatance 
        
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