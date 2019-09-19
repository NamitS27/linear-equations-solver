#include<stdio.h>
#include<stdlib.h>

void swapCols(int col1,int col2,int rs,double** mat){
    int j;
    for(j=0;j<rs;j++){
        double temp = mat[j][col1];
        mat[j][col1] = mat[j][col2];
        mat[j][col2] = temp;
    }
}