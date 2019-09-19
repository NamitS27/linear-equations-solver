#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compareNumbers(double x,double y);

int zeroMat(int rs,int cs,double** mat){
    int cnt = 0;
    int i,j;
    for(i=0;i<rs;i++){
        for(j=0;j<cs;j++){
            if(compareNumbers(mat[i][j],0)) cnt++;
        }
    }
    if(cnt == rs*cs) return 1;
    else return 0;
}