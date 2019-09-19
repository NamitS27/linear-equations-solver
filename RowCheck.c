#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int compareNumbers(double x,double y);

int checkRows(int rs,int cs,double** mat){
    int row_count = 0;
    int i,j;
    for(i=0;i<rs;i++){
        int counter = 0;
        double temp;
        for(j=0;j<cs-1;j++){
            if(compareNumbers(mat[i][j],0)){
                ++counter;
            }
        }
        if(counter==cs-1){
            if(!compareNumbers(mat[i][cs-1],0)) return -1;
            else row_count++;
        }
    }
    if(row_count > 0) return row_count;
    else return 0;
}