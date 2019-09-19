#include<stdio.h>
#include<math.h>

int compareNumbers(double x,double y){
    double epsilon = 1e-8;
    if(fabs(x-y)<epsilon) return 1;
    else return 0;
}