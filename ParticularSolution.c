#include<stdio.h>
#include<stdlib.h>

void swaptwoRows(int row1,int row2,int rs,int cs,double** mat);

void findParticular(int** free_ind,int free_var,int num_p,int rs,int cs,double** mat){
    int i,j;
    double* particular;
    particular = (double*)calloc(cs-1,sizeof(double));
    for(i=0;i<num_p;i++){
        particular[i] = mat[i][cs-1]/mat[i][i];
    }
    for(i=free_var;i>=0;i--){
        double temp = particular[free_ind[i][0]];
        particular[free_ind[i][0]] = particular[free_ind[i][1]];
        particular[free_ind[i][1]] = temp;
    }
    printf("\nParticular Solution of the given system is : \n\n");
    for(int i=0;i<cs-1;i++){
        printf("%12.2lf\n",particular[i]);
    }
    free(particular);
}