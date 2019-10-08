# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define ElemType int
# define ROW 5
# define COL 5
# define MAXSIZE 25
# define MAXRC 25

typedef struct
{
    int i,j;
    ElemType elem;
}triple;

typedef struct
{
    triple data[MAXSIZE];
    int rpos[MAXRC];
    int number;
}RLSMatrix;

RLSMatrix initMatrix(){
    RLSMatrix M;
    M.number = 0;

    srand((int)time(0));
    ElemType matrix[ROW][COL];
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
            if(matrix[i][j] != 0){
                M.data[M.number].elem = matrix [i][j];
                M.data[M.number].i = i;
                M.data[M.number].j = j;
                M.number++;
            }
        }
    }

    M.rpos[0] = 0;
    int nowrow = M.data[0].i;
    int count = 1;
    for (int i = 0; i < M.number; i++)
    {
        if(M.data[i].i != nowrow){
            M.rpos[count] = i;
            nowrow = M.data[i].i;
            count++;
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

    for (int i = 0; i < M.number; i++)
    {
        printf("| %d ",M.data[i].elem);
    }
    printf("|");
    

    printf("\n");

    for (int i = 0; i < count; i++)
    {
        printf("| %d ",M.rpos[i]);
    }
    printf("|");

    printf("\n");

    return M;
    
}

int printMartix(RLSMatrix M){
    int count = 0;
    for (int i = 0; i < M.number; i++)
    {
        if(M.rpos[count+1] == i){
            printf("\n");
            count++;
        }
        printf(" %d ",M.data[i].elem);
    }
    
}

int main(){
    RLSMatrix matrix;
    matrix = initMatrix();
    printMartix(matrix);
}
