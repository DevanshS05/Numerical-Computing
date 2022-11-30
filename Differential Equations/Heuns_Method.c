/*
Program for Heun's-Method for solving a differential equation
*/
#include<stdio.h>

//The function is hard-coded below 
float function(float x,float y){
    return -1*(x*y);
}

int main(){
    float x1,y1,h,xFinal;
    printf("Please enter the initial values of x and y: ");
    scanf("%f %f",&x1,&y1);
    printf("Please enter the final value of x: ");
    scanf("%f", &xFinal);
    printf("\nPlease enter the value of h [Step increment]: ");
    scanf("%f", &h);
    while(x1<=xFinal){
        printf("\nThe values are X=%f and y=%f", x1, y1);
        float s1 = function(x1, y1);
        float x2 = x1+h;
        float y2 = y1 + (h*s1);
        float s2 = function(x2, y2);
        y2 = y1 + h*((s1+s2)/2);
        x1 = x2;
        y1 = y2;
    }

    return 0;
}