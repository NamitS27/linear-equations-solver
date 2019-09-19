#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void printMat(int rs,int cs,double** mat);
void swaptwoRows(int row1,int row2,int rs,int cs,double** mat);
int compareNumbers(double x,double y);

void findNullspace(int** free_ind,int free_var,int nmp,int rs,int cs,double** mat){
    int i,j;
    int newr = nmp;
    int newc = cs-1-nmp;
    newr += newc;
    double** nullspace;
    nullspace = (double**)calloc(newr,sizeof(double));
    for(i=0;i<newr;i++){
        nullspace[i] = (double*)calloc(newc,sizeof(double));
    }
    
    for(i=0;i<nmp;i++){
        for(int j=nmp;j<cs;j++){
            if(compareNumbers(mat[i][j],0)) nullspace[i][j-nmp] = mat[i][j]; 
            nullspace[i][j-nmp] = -mat[i][j];   
        }
    }
    
    int x = nmp;
    for(i=0;i<newc;i++){
        for(j=0;j<newc;j++){
            if(i==j){
                nullspace[x][j] = 1;
            } 
            else{
                nullspace[x][j] = 0;
            }
        }
        x++;
    }
    //convertM(newr,newc,nullspace);
    
    for(i=free_var;i>=0;i--){
        if(free_ind[i][0] != free_ind[i][1]){
            swaptwoRows(free_ind[i][0],free_ind[i][1],newr,newc,nullspace);
        }
    }
    for(i=0;i<newr;i++){
        for(j=0;j<newc;j++){
            if(compareNumbers(nullspace[i][j],0)) nullspace[i][j] = 0;
        }
    }
    printf("\n\nBasis of Null Space are :\n");
    printMat(newr,newc,nullspace);
}   