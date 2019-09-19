#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void printMat(int rs,int cs,double** mat);
void backSubstitution(int rs,int cs,double** mat);
int swapRows(int pv1,int pv2,int rs,int cs,double** mat);
void swapCols(int* npi,int np,int rs,int cs,double** mat);
void traceColsExchange(int num_pivots,int** free_ind,int rs,int cs,double** mat);
void convert_rref(int** free_ind,int num_p,int free_var,int rs,int cs,double** mat);
int countRows(int rs,int cs,double** mat);
void findNullspace(int** free_ind,int nmp,int rs,int cs,double** mat);
int zeroMat(int rs,int cs,double** mat);
int compareNumbers(double x,double y);


void gaussianElimination(int rs,int cs,double** mat){
    int num_pivots = 0;
    int** free_ind;
    free_ind = (int**)calloc(cs-1,sizeof(int));
    for(int i=0;i<cs-1;i++){
        free_ind[i] = (int*)calloc(2,sizeof(int));
    }
    if(zeroMat(rs,cs,mat)) printf("\nMatrix is zero Matrix and we can't do any elimination\n");
    else{
    int loop_end = (rs > (cs-1)) ? cs-1 : rs-1;
    int i,j,z,k;
    for(i=0,j=0,z=0;z<loop_end;i++,j++,z++){
        if(mat[i][j]==0){
            int check = swapRows(i,j,rs,cs,mat);
            if (check == -1) {
                --i;
                --z;
                continue;
            }
        }
        for(k=i+1;k<rs;k++){
            double fac = mat[k][j] / mat[i][j];
            for(int a=0;a<cs;a++){
                 mat[k][a] -= fac*mat[i][a];
                 if(compareNumbers(mat[k][a],0)) mat[k][a] = 0.00;
            }
        }
    }
    printf("\nEliminated Matrix :- \n");
    printMat(rs,cs,mat); 
    backSubstitution(rs,cs,mat);
    }
    printf("\n===================================== Null Space & Particular Solution ==========================================\n");
    num_pivots = rs-countRows(rs,cs,mat);
    //printf("Pvs : %d\n",num_pivots);
    if(num_pivots==cs-1){
        convert_rref(free_ind,num_pivots,cs-1-num_pivots,rs,cs,mat);
        printf("\nWe cannot find Nullspace and hence Nullity = 0\n");
    }
    else if(num_pivots==0){
        printf("\nNullspace is any vector in whole R(%d)",rs);
    }
    else{
        traceColsExchange(num_pivots,free_ind,rs,cs,mat);
    }
    free(free_ind);
}