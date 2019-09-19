#include<stdio.h>

void swaptwoRows(int row1,int row2,int rs,int cs,double** mat);
int compareNumbers(double x,double y);

void swap_zero(int num_rows,int rs,int cs,double** mat){
    int rtemp = rs-1;
    int i,k;
    for(i=0;i<rs-num_rows;i++){
        int counter = 0;
        for(k=0;k<cs-1;k++){
            if(compareNumbers(mat[i][k],0)) counter++;
        }
        if(counter==cs-1){
            swaptwoRows(i,rtemp,rs,cs,mat);
            rtemp--;
        }
    }
}