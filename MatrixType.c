#include<stdio.h>
#include<stdlib.h>

int checkMatType(int matcheck,int rs,int cs,double** mat){
    if(rs>cs-1){
        int i,j;
        if(rs-matcheck < cs-1) return -2;
        else{
       double sol[cs-1];
       for(i=rs-matcheck;i>=0;i--){
           sol[i] = mat[i][cs-1];
            for(j=i+1;j<cs-1;j++){
                sol[i] -= mat[i][j] * sol[j];
            }
            sol[i] /= mat[i][i]; 
       }
        printf("\n\nSolution to Linear Equation :- \n\n");
        char ans = 'x';
        int count = 0;
        for(int i=0;i<cs-1;i++){
       	    printf("%c%d = %.2lf\n",ans,++count,sol[i]);
        }
        return 0;
        }
    }
    else return -1;
}