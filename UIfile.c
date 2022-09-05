// Project Maze solver using stack


// library declaration
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>

#define N 5

// global variable
int check_count=0;
int r;
int c;
int arr_in[5][5];
int arr_out[5][5];
int check_maze_in=0;
int maze_in_f=0;
int sol[N][N] = { { 0, 0, 0, 0,0 },
					{ 0, 0, 0, 0,0 },
					{ 0, 0, 0, 0,0 },
					{ 0, 0, 0, 0 ,0},
					{ 0, 0, 0, 0 ,0}};

// function declaration
void image_writer_in();
void image_writer_out();
void firstscreen();
 


bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);





void image_writer_in()
{
    int i, j, temp = 0;
    int width = c, height =r ;
    int arr_in_t[r][r];
    for ( i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if(arr_in[i][j]==0)
            {
                arr_in_t[i][j]=15;
            }
            else
            {
                arr_in_t[i][j]=207;
            }

        }
        
    }
    

    FILE* pgmimg;
    pgmimg = fopen("pgmimg.pgm", "wb");
  
    // Writing Magic Number to the File
    fprintf(pgmimg, "P2\n"); 
  
    // Writing Width and Height
    fprintf(pgmimg, "%d %d\n", width, height); 
  
    // Writing the maximum gray value
    fprintf(pgmimg, "255\n"); 
    int count = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {

            temp = arr_in_t[i][j];
  
            // Writing the gray values in the 2D array to the file
            fprintf(pgmimg, "%d ", temp);
        }
        fprintf(pgmimg, "\n");
    }
    fclose(pgmimg);
}

void image_writer_out()
{
    int i, j, temp = 0;
    int width = c, height =r ;
    int arr_out_t[r][r];
    for ( i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if(arr_out[i][j]==0)
            {
                arr_out_t[i][j]=15;
            }
            else
            {
                arr_out_t[i][j]=207;
            }

        }
        
    }
    FILE* pgmimg_1;
    pgmimg_1 = fopen("pgmimg_1.pgm", "wb");
  
    // Writing Magic Number to the File
    fprintf(pgmimg_1, "P2\n"); 
  
    // Writing Width and Height
    fprintf(pgmimg_1, "%d %d\n", width, height); 
  
    // Writing the maximum gray value
    fprintf(pgmimg_1, "255\n"); 
    int count = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            temp = arr_out_t[i][j];
  
            // Writing the gray values in the 2D array to the file
            fprintf(pgmimg_1, "%d ", temp);
        }
        fprintf(pgmimg_1, "\n");
    }
    fclose(pgmimg_1);
}























void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}


// To check allowing conditions
bool isSafe(int maze[N][N], int x, int y)
{

	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
		return true;

	return false;
}


bool solveMaze(int maze[N][N])
{
	

	if (solveMazeUtil(maze, 0, 0, sol) == false) {
		printf("Solution doesn't exist");
		return false;
	}
 
    

	printSolution(sol);
     for(int i=0;i<r;i++)
    {
        for(int j=0;j<r;j++)
        {
           if(sol[i][j]==0)
           {arr_out[i][j]=0;}
           else{arr_out[i][j]=1;}
        }

    }
   
	return true;
}

// Function solving the maze
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
// 	Finding the start and end points of the maze




// 	If reaching endpoint
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;

    
        return true;
    }

	// Next step movable?
	if (isSafe(maze, x, y) == true) {

		sol[x][y] = 1;

		if (solveMazeUtil(maze, x + 1, y, sol) == true)
			return true;

		if (solveMazeUtil(maze, x, y + 1, sol) == true)
			return true;

		sol[x][y] = 0;
		return false;
	}

   

	return false;
}






























































// main menu
void firstscreen()
{
    int fs_cntrl=0;
    do
    {
        system("cls");
        system("color 72");
        printf("\n\n\n\n");
        printf("\n              ||||||||||||||||||||||||||||||||||||||||||||||||||||              ");
        printf("\n                                                                                ");
        printf("\n                           Welcome to maze solver!                              ");
        printf("\n                                                                                ");
        printf("\n              ||||||||||||||||||||||||||||||||||||||||||||||||||||              ");
        printf("\n");
        
        if(fs_cntrl!=1 &&fs_cntrl!=2&&fs_cntrl!=0)
        {
            printf("\n");
            printf("\n                          [INVALID INPUT TRY AGAIN]                             ");
            printf("\n");

        }
        printf("\n");
        printf("\n********************************************************************************");
        printf("\n");
        printf("\n                   To input the maze in array format     -> 1                   ");
        printf("\n");
        printf("\n                   To Get the result of input maze       -> 2                   ");
        printf("\n");
        printf("\n                          to exit  MAZE Solver           -> 0                   ");
        printf("\n");
        printf("\n********************************************************************************");
        printf("\n                               Enter here     -> ");
        scanf("%d",&fs_cntrl);
        


    }while(fs_cntrl!=1 &&fs_cntrl!=2&&fs_cntrl!=0);

    if(fs_cntrl==1)
    {
        system("cls");
        system("color 70");
        printf("\n                       How big is your maze?                                  \n");
        printf("\n          consider every wall and path segment as a saparate block            \n");
        printf("\n    According to that enter the value of rows and column of 2D matrix         \n");
        printf("\n");
        printf("                 enter number of rows you want in array -> ");
        scanf("%d",&r);
        printf("\n");printf("\n");
        printf("                 enter number of column you want in array -> ");
        scanf("%d",&c);

        if (r!=c)
        {
            printf("\n\n                 You have not entered correct maze dimentions                          ");
            printf("                          press any key to try again                                       ");
            getch();
            return;
        }
        

        printf("\n     first you need to understand how to give your maze as an input to the program   ");
        printf("\n                         Be careful in entering the input");

        printf("\n\n             If your maze looks like following maze on the left then\n");
        printf("                 you need to enter array values in below format on right\n");
        printf("\n");
        printf("\nHere  ## represents a wall block and [] represents a path block");
        printf("\nwhen giving input represent wall block as 0 and path block as 1 like shown below");
        printf("\n");
        printf("\n            ##[]########                            0,1,0,0,0,0   ");
        printf("\n            ##[][]##[]##                            0,1,1,0,1,0   ");
        printf("\n            ####[][][]##             ->             0,0,1,1,1,0   ");
        printf("\n            ##[][]##[]##                            0,1,1,0,1,0   ");
        printf("\n            ####[]######                            0,0,1,0,0,0   ");
        printf("\n     Read and understand carefully, If understood press any key for starting input ");
        getch();

        //for maze input

        system("cls");
        system("color 70");


        for (int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
            {
            arr_in[i][j]=8;
                
            }
            

        }

        int majorbrek=0;
       
        for(int m=0;m<r;m++)
        {  
            if(majorbrek==1)
            {break;}
            for(int n=0;n<c;n++)
            {
                system("cls");
                printf("\n                       Here $ signs show your current x and y coordinate ");
                printf("\n             and both of those $ signs' intersection point is your current input state ");
                printf("\n                           all the current 8 you see are empty spaces\n\n");
                printf("\n    Enter only one or zero according to maze or the code will break!! and you'll have to try again \n\n");


                printf(" *");for(int j=0;j<n;j++){printf("  ");}printf(" $");
    printf("\n");
                for(int k=0;k<r;k++)
                {
                    if(k==m){printf(" $");}
                    else{printf("  ");}
                    for (int l = 0; l < c ; l++)
                    {
                    printf(" %d", arr_in[k][l]);
                    }
                    printf("\n");
                }
                printf("\n\n Enter your input here -");
                scanf("%d",&arr_in[m][n]);
                if(arr_in[m][n]!=0&&arr_in[m][n]!=1)
                {
                
                    majorbrek=1;
                    break;
                }
                else
                {continue;}
            }
        }
        

        // printing the input maze array
        printf("\n\n        You've successfully entred the maze array!!          ");
        printf("\n\n          The maze array that you have entred:           \n\n");

        for (int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
            {
            printf(" %d ",arr_in[i][j]);
                
            }
            
            printf("\n");
        }

        printf("\n\n              You've successfully entred the maze array!! press any key to exit       ");
        maze_in_f=1;
        printf("\n\nEntered maze's pgm image is saved in program directory now you can convert it jpeg and check it out!!");
        image_writer_in();
        getch();

    }





    else if(fs_cntrl==2)
    {
        system("cls");
        system("color 72");

        if(maze_in_f==0)
        {
            printf("\n\n\n                no maze haze been entered!! please enter a maze first                     ");
            getch();
        }
        else
        {
            solveMaze(arr_in);
            printf("\n\nEntered maze's solution pgm image is saved in program directory now you can convert it jpeg and check it out!!");
            image_writer_out();
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<r;j++)
                {
                   printf(" %d ",arr_out[i][j]);
                }
                printf("\n");

            }
            getch();
        }

    
    }
    else
    {
        return;
    }
    
    firstscreen();

}
















// entry console
void main()
{    
    
    int m_cntrl=0;
    do
    {
        system("cls");
        system("color 78");
        printf("\n\n\n\n");
        printf("\n              ||||||||||||||||||||||||||||||||||||||||||||||||||||              ");
        printf("\n                                                                                ");
        printf("\n                           Welcome to maze solver!                              ");
        printf("\n                                                                                ");
        printf("\n              ||||||||||||||||||||||||||||||||||||||||||||||||||||              ");
        printf("\n");
        
        if(m_cntrl!=1 && m_cntrl!=2&& m_cntrl!=0)
        {
            printf("\n");
            printf("\n                          [INVALID INPUT TRY AGAIN]                             ");
            printf("\n");

        }
        printf("\n");
        printf("\n********************************************************************************");
        printf("\n");
        printf("\n                          To enter MAZE Solver     -> 1                         ");
        printf("\n");
        printf("\n                          read description of app. -> 2                         ");
        printf("\n");
        printf("\n                          to exit  MAZE Solver     -> 0                         ");
        printf("\n");
        printf("\n********************************************************************************");
        printf("\n                               Enter here     -> ");
        scanf("%d",&m_cntrl);
        


    }while(m_cntrl!=1 && m_cntrl!=2&& m_cntrl!=0);

    if(m_cntrl==1)
    {
     firstscreen();
    }

    else if (m_cntrl==2)
    {
        system("cls");
        system("color 72");
        printf("\n\n\n\n");
        printf("\n              ||||||||||||||||||||||||||||||||||||||||||||||||||||              ");
        printf("\n                                                                                ");
        printf("\n                   -Maze solver is an application that takes                    ");                                                                       
        printf("\n                  Input of a MAZE as an array, solves the MAZE                  ");
        printf("\n                 Gives you the shortest path to solve the given                 ");
        printf("\n                 Maze, transforms the given maze to solved maze                 ");
        printf("\n                    creats pgm image file out of it and then                    ");
        printf("\n                     You can convert it to jpeg//jpg format!                    ");
        printf("\n                                                                                ");
        printf("\n              ||||||||||||||||||||||||||||||||||||||||||||||||||||              ");
        printf("\n                                      ");
        getch();
        main();
    }
    else
    {
        
        system("exit");
    }
    
}
