#include<stdio.h>
#include<stdlib.h>
int compareNumbers(double x,double y);

int swapRows(int pv1,int pv2,int rs,int cs,double** mat){
    int swap_ind = -1;
    int i;
    for(i=pv1+1;i<rs;i++){
        if(!compareNumbers(mat[i][pv2],0)){
            swap_ind = i;
            break;
        }
    }
    if(swap_ind==-1) return -1;
    else{
        for(i=0;i<cs;i++){
            double temp = mat[pv1][i];
            mat[pv1][i] = mat[swap_ind][i];
            mat[swap_ind][i] = temp;
        }
        return 0;
    }
}