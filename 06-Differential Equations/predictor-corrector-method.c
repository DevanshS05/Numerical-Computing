#include<stdio.h>

//The function is hard-coded below 
float function(float x,float y){
    return -1*(x*y);
}

int main(){
    float x1, y1, h, xFinal;
    printf("Please enter the value of x1 and y1: ");
    scanf("%f %f",&x1, &y1);
    printf("\nPlease enter the value of h [Step Value]");
    scanf("%f", &h);
    printf("\nPlease enter the final value of x: ");
    scanf("%f",&xFinal);

    printf("\nx==%f && y==%f",x1,y1);
    float s1 = function(x1,y1);
    float x2 = x1+h;
    float y2 = y1 + h*s1;
    float s2 = function(x2,y2);
    y2 = y1 + (h/2)*(s1+s2);

    float y3P,y3C,x3,s3;
    while(x2<=xFinal){
        printf("\nx==%f && y==%f", x2,y2);
        y3P = y1 + 2*h*s2;
        x3 = x2+h;
        s3 = function(x3, y3P);
        y3C = y1 +(h*(s2+s3))/2;
        y1 = y2;
        y2 = y3C;
        x2 = x3;
    }
    return 0;
}