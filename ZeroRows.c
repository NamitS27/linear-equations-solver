#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compareNumbers(double x,double y);

int countRows(int rs,int cs,double** mat){
    int zero_rows = 0;
    int i,j;
    for(i=0;i<rs;i++){
        int counter = 0;
        double temp;
        for(j=0;j<cs-1;j++){
            if(compareNumbers(mat[i][j],0)){
                ++counter;
            }
        }
        if(counter==cs-1) zero_rows++;
    }
    return zero_rows;
}