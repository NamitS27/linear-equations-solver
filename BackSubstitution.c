#include<stdio.h>
#include<stdlib.h>

int checkRows(int rs,int cs,double** mat);
int checkMatType(int check,int rs,int cs,double** mat);
void swap_zero(int rs,int cs,double** mat);
int compareNumbers(double x,double y);

void backSubstitution(int rs,int cs,double** mat){    
    int check = checkRows(rs,cs,mat);
    if(cs-1>rs){
        if(check == -1) {
            printf("\nThe given system is inconsistent and hence we won't find any solution\n");
        }
        else {
            printf("\nAs there are free variables we will get infinite solutions\n");
        }
        return;
    }
    double sol[cs-1];
    if(check == 0){
        int i,j;
        for(i=rs-1;i>=0;i--){
            sol[i] = mat[i][cs-1];
            for(j=i+1;j<cs-1;j++){
                sol[i] -= mat[i][j] * sol[j];
            }
            sol[i] /= mat[i][i];
            if(compareNumbers(sol[i],0)) sol[i] = 0; 
        }
        printf("\nUnique Solution to System of Linear Equation :- \n\n");
        char ans = 'x';
        int count = 0;
        for(i=0;i<cs-1;i++){
       	    printf("%c%d = %.2lf\n",ans,++count,sol[i]);
        }
        return;
    }
    else if(check == -1){
        printf("\nThe given system is inconsistence so we won't find any solution\n");
    }
    else{
        int checkMat = checkMatType(check,rs,cs,mat);
        if(checkMat!=0) printf("\nAs there are free variables we will get infinite solutions\n");
    }
}