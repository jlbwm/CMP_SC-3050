#include <stdio.h>
#include <stdlib.h>
#include "input_error.h"


#define TRUE 1
#define FALSE 0

#define MAXSIZE 100
#define MAX_LENTH 65535


typedef struct
{
   int x;
   int y;

}Point; //coordinate struct

typedef struct
{
	Point route[MAX_LENTH]; //stack, store Point
	int top; //头结点

}stack;



stack STA; //store the S-E route
stack STA1;//store the F-L route

//int rs, cs, re, ce; //start_row start_column end_row end_column 
int row;
int column;



void initStack(stack *S) 
{ 
    
    S->top = -1;
}

void push(stack *S, Point e) 
{
        if(S->top == MAX_LENTH -1) // full
        {
            exit(STACK_OVER_FLOW);
        }
        S->top++;				
        S->route[S->top]=e;  
}

void Pop(stack *S) 
{ 
    if(S->top == -1)
    {
        exit(STACK_EMPTY);
    }
    
    
    S->top--;
    
}

Point top(stack *S)
{
    return S->route[S->top];
}

	
    



void stackTraverse(stack S, FILE *fp) //reverse put route
{
    if(S.top == -1)
    {
        fprintf(fp, "no route");

    }
    else
    {
        for(int i = 0; i <= S.top; i++)
        {
        fprintf(fp, "(%d, %d)", S.route[i].x, S.route[i].y);
        }
    }
    fprintf(fp, "\n");
}

int empty(stack S)
{
    if(S.top == -1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void initMaze_c(int maze [][column], char maze_c[][column], int row, int column)
{
	for(int i = 0; i<row; i++) //inital the original maze
	{
		for(int j = 0; j<column; j++)
		{
			if(maze[i][j] == 1)
			{
				maze_c[i][j] = ' '; 
			}
			else if(maze[i][j] == 0)
			{
				maze_c[i][j] = '#';
			}
		}
			
	}

	

}

void printMaze(FILE *fp, char maze_c[][column], int row, int column)
{
	
	for(int i = 0; i<row; i++)
 	{
 		for(int j = 0; j<column; j++)
 		{
 			if(j == column - 1)
 			{
 				fprintf(fp, "%c", maze_c[i][j]);
 			}
 			else
 			{
				fprintf(fp, "%c", maze_c[i][j]);
 			}
 		}
 		fprintf(fp, "\n");
	}


}


// My first edition of algorithm, use recurrence, but cannot end the recurrence, failed

// void DFS(int rs, int cs, int re, int ce, int row, int column, FILE *fpout, int maze[][column], char maze_c[][column], int visited[][column], stack STA, char a, container container) //rs cs 起点坐标  re, ce 终点坐标
// {
	
// 	if(visited[rs][cs] || maze[rs][cs] == 0)  //if already visited or it is obstacle, return the upper level
// 	{
// 		return;
// 	}
//     else
//     {
//         visited[rs][cs] = TRUE; 

//         point p;
//         p.x = rs;
//         p.y = cs;
//         push(&STA, p); 

//         maze_c[p.x][p.y] = a;
//         fprintf(fpout, "push(%d, %d) ", p.x, p.y);

//         if(rs == re && cs ==ce)
//         {
//             fprintf(fpout, "\n");
//             printMaze(fpout, maze_c, row, column); 
//             fprintf(fpout, "\n");
//             for(int i = 0; i <= STA.top; i++)
//             {
//                 fprintf(fpout, "(%d, %d)", STA.route[i].x, STA .route[i].y);
//             }
//             fprintf(fpout, "\n");



//         }
//         else
//         {
//             if((rs-1) >= 0)
//             {
//                 DFS(rs-1, cs, re, ce, row, column, fpout, maze, maze_c, visited, STA, a, container); //↑
//             }
//             if((rs+1) < row)
//             {
//                 DFS(rs+1, cs, re, ce, row, column, fpout, maze, maze_c, visited, STA, a, container); //↓
//             }
//             if((cs-1) >= 0)
//             {
//                 DFS(rs, cs-1, re, ce, row, column, fpout, maze, maze_c, visited, STA, a, container); //←
//             }
//             if((cs+1) < column)
//             {
//                 DFS(rs, cs+1, re, ce, row, column, fpout, maze, maze_c, visited, STA, a, container); //→
//             }
//             if((rs-1) >= 0 && (cs-1) >= 0)
//             {
//                 DFS(rs-1, cs-1, re, ce, row, column, fpout, maze, maze_c, visited, STA, a, container); //↖
//             }
//             if((rs+1) < row && (cs-1) >= 0) 
//             {
//                 DFS(rs+1, cs-1, re, ce, row, column, fpout, maze, maze_c, visited, STA, a, container); //↙
//             }
//             if((rs-1) >= 0 && (cs+1) < column)
//             {
//                 DFS(rs-1, cs+1, re, ce, row, column, fpout, maze, maze_c, visited, STA, a, container); //↗
//             }
//             if((rs+1) < row && (cs+1) < column)
//             {
//                 DFS(rs+1, cs+1, re, ce, row, column, fpout, maze, maze_c, visited, STA, a,container); //↘
//             }
            
//             point e;
//             pop(&STA, &e);//this point does not have the possibilty of going to the next point, pop it from the stack
//             maze_c[e.x][e.y] = ' ';
//             fprintf(fpout, "pop(%d, %d) ", e.x, e.y);
//             return;
            
            

//         }

//     }

//}


//new version of algorithm

Point getAdjacentNotVisitedNode(int maze[][column], Point point, int row, int column)
{
    
    Point resp;
    resp.x = -1;
    resp.y = -1;

    if((point.x - 1 >= 0) && (maze[point.x -1][point.y] == 1))
    {   
        //↑
        resp.x=point.x-1;
        resp.y=point.y;
        return resp;
    }
    if( (point.y + 1 < column) && (maze[point.x][point.y+1] == 1))
    {   
        //→
        resp.x=point.x;
        resp.y=point.y+1;
        return resp;
    }
    if((point.x + 1 < row) && (maze[point.x+1][point.y] == 1))
    {
        //↓
        resp.x=point.x+1;
        resp.y=point.y;
        return resp;
    }
    if( (point.y-1 >= 0) && maze[point.x][point.y-1] == 1)
    {   
        //←
        resp.x=point.x;
        resp.y=point.y-1;
        return resp;
    }
    if((point.x -1 >= 0) && (point.y -1 >=0) && maze[point.x-1][point.y-1] == 1)
    {
        //↖
        resp.x=point.x-1;
        resp.y=point.y-1;
        return resp;
    }
    if((point.x -1 >= 0) && (point.y +1 < column) && maze[point.x-1][point.y+1] == 1)
    {
        //↗
        resp.x=point.x-1;
        resp.y=point.y+1;
        return resp;
    }
    if((point.x + 1 < row) && (point.y +1 < column) && maze[point.x+1][point.y+1] == 1)
    {
        //↘
        resp.x=point.x+1;
        resp.y=point.y+1;
        return resp;
    }
    if((point.x + 1 < row) && (point.y -1  >= 0) && maze[point.x+1][point.y-1] == 1)
    {
        //↙
        resp.x=point.x+1;
        resp.y=point.y-1;
        return resp;
    }

    return resp;
}

void DFS(Point S, Point E, int row, int column, int maze[][column], char maze_c[][column], stack STA, FILE *fpout, char a) 
{
    fprintf(fpout, "Start(%d, %d) End(%d, %d)\n", S.x, S.y, E.x, E.y);


    if(maze[S.x][S.y] == FALSE || maze[E.x][E.y] == FALSE) //when both S and E are obstacle, exit fault
        return;


    push(&STA, S);
    maze_c[S.x][S.y] = a;


    maze[S.x][S.y]= 0;

    while(empty(STA) == FALSE && ((top(&STA).x != E.x) || (top(&STA).y != E.y)))//stack is not empty and the top point in the stack isn't the end point
    {

        Point adjacentNotVisitedNode = getAdjacentNotVisitedNode(maze, top(&STA), row, column);


        if(adjacentNotVisitedNode.x == -1)
        { 
            //do not have the adjacent node
            maze_c[top(&STA).x][top(&STA).y] = ' ';
            Pop(&STA); //back the upper point

            continue;
        }

        //push to stack and make is visited
        maze[adjacentNotVisitedNode.x][adjacentNotVisitedNode.y] = 0;
        push(&STA, adjacentNotVisitedNode);
        maze_c[adjacentNotVisitedNode.x][adjacentNotVisitedNode.y] = a;

    }

    stackTraverse(STA, fpout);
}


char buffer[MAX_LENTH];
char buffer1[MAX_LENTH];


int column = 0;
int row = 0;
int temp_c = 0;


int main(int argc, char** argv) 
{
    
	if (argc != 3)
    {
        exit(INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS);//1
        //fprintf(fpout, "INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS");
        
    }

    FILE* fpin = fopen(argv[1], "r");

    if (!fpin)
    {
        exit(INPUT_FILE_FAILED_TO_OPEN);//2
        //fprintf(fpout, "INPUT_FILE_FAILED_TO_OPEN");

        
    }
  
    FILE* fpout = fopen(argv[2], "w");
    
    if (!fpout)
    {
        exit(OUTPUT_FILE_FAILED_TO_OPEN);//5
        //fprintf(fpout, "OUTPUT_FILE_FAILED_TO_OPEN");
    }

    char c = fgetc(fpin);

    if (c==EOF)
    {
    	//fprintf(fpout, "PARSING_ERROR_EMPTY_INPUT_FILE");
        exit(PARSING_ERROR_EMPTY_INPUT_FILE);//4
        

    }
    else
    {
        if(c == ' ' || c == '#' || c == '\n')
        {

        } 
        else
        {
            exit(PARSING_ERROR_INVALID_FORMAT);//7
        }
    }
    ungetc(c, fpin);


    while(fgets(buffer,MAX_LENTH,fpin)!=NULL) //get a buffer array
    {
    	
    	
    	for(int i = 0; i < MAX_LENTH; i++)
    	{
    		if(buffer[i] != '\n')
    		{
    			temp_c++;//make the temporary column add one
    		}
    		else
    		{
    			break; //when found \n, stop record, break to the floop 
    		}

    	}
    	row++; 
    	if(column <= temp_c)
    	{
    		column = temp_c;//if the prior column less than the new column, make the value of column equal to the new line

    		temp_c = 0;
    	}
    	else
    	{
    		temp_c = 0;
    	}
 	}

 	int maze[row][column]; 
    int maze1[row][column];
 	char maze_c[row][column];
 	char maze_c1[row][column];
 	
 	Point S; //start
 	Point E;//end
 	Point F;//first
 	Point L;//last

 	
 	for(int i = 0; i<row; i++) //inital maze, make all value of maze equal to 1
 	{
 		for(int j = 0; j<column; j++)
 		{
 			maze[i][j] = TRUE; //1
 		}
 	}

 	fseek(fpin, 0, SEEK_SET);
	//make the file point back to the file's head

	int count = 0; //use count control row

 	
 	while(fgets(buffer1, column+2, fpin)!=NULL) //Digitize the maze
    {
    	fprintf(fpout, "%s", buffer1);

    	
    	for(int i = 0; i < column; i++) 
    	{
    		if(buffer1[i] == ' ')
    		{
    			maze[count][i] = TRUE;
                maze1[count][i] = TRUE;
    		}
    		else if(buffer1[i] == 'S')
    		{
    			maze[count][i] = TRUE; 
                maze1[count][i] = TRUE;
    			S.x = count;
    			S.y = i;
    		}
    		else if(buffer1[i] == 'E') 
    		{
    			maze[count][i] = TRUE;
                maze1[count][i] = TRUE;
    			E.x = count;
    			E.y = i;
    		}
    		else if(buffer1[i] == 'F') 
    		{
    			maze[count][i] = TRUE;
                maze1[count][i] = TRUE;
    			F.x = count;
    			F.y = i;
    		}
    		else if(buffer1[i] == 'L')
    		{
    			maze[count][i] = TRUE;
                maze1[count][i] = TRUE;
    			L.x = count;
    			L.y = i;
    		}
    		else if(buffer1[i] == '#')
    		{
    			maze[count][i] = FALSE;
                maze1[count][i] = FALSE;
    		}
    		else if(buffer1[i] == '\n')
    		{
    			maze[count][i] = TRUE;
                maze1[count][i] = TRUE;
    			for(int j = i+1; j < column; j++)
    			{
    				maze[count][j] = TRUE;//make all the value after the '\n' equal to true
                    maze1[count][j] = TRUE;
				}
    			break; 
			}
		}

    	count++; 
    	
 	}


 	fprintf(fpout, "------------------------------------------------------------------\n");


 	initStack(&STA);
 	initMaze_c(maze, maze_c, row, column); 

    fprintf(fpout, "S -> E ");
    DFS(S, E, row, column, maze, maze_c, STA, fpout, '*');
    fprintf(fpout, "\n");
    printMaze(fpout, maze_c, row, column);


 	fprintf(fpout, "\n------------------------------------------------------------------\n");

    
	initStack(&STA1);
  	initMaze_c(maze1, maze_c1, row, column);
    fprintf(fpout, "F -> L ");
    DFS(F, L, row, column, maze1, maze_c1, STA1, fpout, '^');
    fprintf(fpout, "\n");
    printMaze(fpout, maze_c1, row, column);


	
	if (fclose(fpin) == EOF)
    {
        exit(INPUT_FILE_FAILED_TO_CLOSE);  
        //fprintf(fpout, "INPUT_FILE_FAILED_TO_CLOSE"); 
    }

    if (fclose(fpout) == EOF)
    {
        exit(OUTPUT_FILE_FAILED_TO_CLOSE);
        //fprintf(fpout, "OUTPUT_FILE_FAILED_TO_CLOSE");
    }

    
    return 0;
    
}




