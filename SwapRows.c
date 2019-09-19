#include<stdio.h>
#include<stdlib.h>

void swaptwoRows(int row1,int row2,int rs,int cs,double** mat){
    int i;
    for(i=0;i<cs;i++){
        double temp = mat[row1][i];
        mat[row1][i] = mat[row2][i];
        mat[row2][i] = temp;
    }
}