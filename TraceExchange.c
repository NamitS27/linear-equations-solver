#include<stdio.h>
#include<stdlib.h>

void swapCols(int col1,int col2,int rs,double** mat);
void printMat(int rs,int cs,double** mat);
int countRows(int rs,int cs,double** mat);
void swap_zero(int nr,int rs,int cs,double** mat);
void convert_rref(int** free_ind,int num_p,int free_var,int rs,int cs,double** mat);
int compareNumbers(double x,double y);


void traceColsExchange(int nmp,int** free_ind,int rs,int cs,double** mat){
    
    int ind=0;
    int zero_rows = countRows(rs,cs,mat);
    
    swap_zero(zero_rows,rs,cs,mat);
    int i,j,k;
    int loop_end = (rs > (cs-1)) ? cs-1 : rs;
    for(i=0,j=0;j<loop_end;i++,j++){
        if(compareNumbers(mat[i][j],0)){
            for(k=j+1;k<cs-1;k++){
                if(!compareNumbers(mat[i][k],0)){
                    swapCols(j,k,rs,mat);
                    free_ind[ind][0] = j;
                    free_ind[ind][1] = k;
                    ++ind;
                    break;
                } 
            }
        }
    }
    convert_rref(free_ind,nmp,ind,rs,cs,mat);
}