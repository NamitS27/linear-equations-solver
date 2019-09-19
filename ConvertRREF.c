#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void printMat(int rs,int cs,double** mat);
void findNullspace(int** free_ind,int free_var,int nmp,int rs,int cs,double** mat);
int compareNumbers(double x,double y);
void findParticular(int** free_ind,int free_var,int num_p,int rs,int cs,double** mat);
int checkRows(int rs,int cs,double** mat);

void convert_rref(int** free_ind,int num_p,int free_var,int rs,int cs,double** mat){
    int i,y,k;
    for(int i=num_p-1;i>=0;i--){
        double div = mat[i][i]; 
        for(int y=0;y<cs;++y){
            mat[i][y] /= div;
            if(compareNumbers(mat[i][y],0)) mat[i][y] = 0;
        }
        for(int k=i-1;k>=0;k--){
            double fac = mat[k][i] / mat[i][i];
            for(int x=0;x<cs;x++){
                mat[k][x] -= fac*mat[i][x];
                if(compareNumbers(mat[k][x],0)) mat[k][x] = 0;
            }
        }
    }
    printf("\nRREF Form of Matrix A :\n");
    printMat(rs,cs-1,mat);
    if(num_p != cs-1) {
        if(checkRows(rs,cs,mat)==-1){
            findNullspace(free_ind,free_var,num_p,rs,cs,mat);
        }
        else{
            findParticular(free_ind,free_var,num_p,rs,cs,mat);
            findNullspace(free_ind,free_var,num_p,rs,cs,mat);
        }
    }
    
}