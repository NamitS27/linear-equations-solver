#include<stdio.h>
#include<stdlib.h>

void gaussianElimination(int rs,int cs,double** mat);

int main(){
    double** mat;
    int rows,columns;
    printf("\nEnter rows and columns of the matrix A (B vector not included): ");
    scanf("%d%d",&rows,&columns);
    printf("\nEnter %dx%d augmented matrix (B vector included) (row wise) : \n",rows,columns+1);
    mat = (double**)calloc(rows,sizeof(double));
    int i,j;
    for(i=0;i<rows;i++){
        mat[i]= (double*)calloc(columns+1,sizeof(double));
    }
    for(i=0;i<rows;i++){
        for(j=0;j<columns+1;j++){
            scanf("%lf",&mat[i][j]);
        }
    }
    printf("\n=========================================== Gaussian Elimination  ===============================================\n");
    gaussianElimination(rows,columns+1,mat);
    free(mat);
    return 0;
}