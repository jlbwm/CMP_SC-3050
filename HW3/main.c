#include "input_error.h"
#include "CreateMGraph.h"
#include "parsing.h"
#include "BFSTraverse.h"

#define MAXVEX 100


int main(int argc, char** argv) 
{
 
    
    if (argc != 3)//三个参数， 例如 make input.txt output.txt
    {
        exit(INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS);//exit(1)
    }
    
    FILE* fpin = fopen(argv[1], "r");

    if (!fpin)
    {
        exit(INPUT_FILE_FAILED_TO_OPEN);//exit(2)
    }
  
    
  
    FILE* fpout = fopen(argv[2], "w");
    if (!fpout)
    {
        exit(OUTPUT_FILE_FAILED_TO_OPEN);//exit(5)
    }

    MGraph G;
    CreateMGraph(&G);
    parse_getline(fpin, &G);
    BFSTraverse(G, fpout);
    
    if (fclose(fpin) == EOF)
    {
        exit(INPUT_FILE_FAILED_TO_CLOSE);//exit(3)
    }

    if (fclose(fpout) == EOF)
    {
        exit(OUTPUT_FILE_FAILED_TO_CLOSE);//exit(6)
    }

    
    return 0;
    
}



