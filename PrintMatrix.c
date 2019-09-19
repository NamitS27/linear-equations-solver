#include<stdio.h>
#include<stdlib.h>

void printMat(int rs,int cs,double** mat){
	int i,j;
    printf("\n");
	for(i=0;i<rs;i++){
       	for(j=0;j<cs;j++){
       		printf("%12.2lf ",mat[i][j]);
       	}
       	printf("\n");
    }
}