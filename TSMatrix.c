# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define SIZE 25
# define ROW 5
# define COL 5

typedef struct
{
    int i,j;
    int data;
}triple;

typedef struct
{
    triple data[SIZE];
    int number;
}TSMatrix;

TSMatrix initMatrix(){
    TSMatrix M;
    M.number = 0;

    int matrix[ROW][COL];
    srand((int)time(0));
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            matrix[i][j] = rand()%10;
        }    
    }

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if(matrix[i][j]!=0){
                M.data[M.number].i = i;
                M.data[M.number].j = j;
                M.data[M.number].data = matrix[i][j];
                M.number++;
            }
        }    
    }

    
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf(" %d ",matrix[i][j]);
        }    
        printf("\n");
    }

        printf("\n");
        printf("\n");

    
    return M;
}

int printMatrix(TSMatrix M){
    int count = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if(j != M.data[count].j){
                printf(" 0 ");
            }else
            {
                printf(" %d ",M.data[count].data);
                count++;
            }
            
        }
        printf("\n");
    }

}

int main(){
    TSMatrix matrix = initMatrix();
    printMatrix(matrix);

}
