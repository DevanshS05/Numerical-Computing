#include <stdio.h>
#include <stdbool.h>

float function(float x){
    return  (x*x)-25.0;
}

bool sign(float num1, float num2){
    if((num1>=0 && num2>=0) || (num1<0 && num2<0)) return true;
    else return false;
}

float abs(float num){
    return num<0 ? num*-1 : num;
}

float relErr(float num1, float num2){
    return abs((num1-num2)/num1);
}

int main(){
    float x0, x1, e;
    float x2,y2;
    printf("Please enter the initial guess values: ");
    scanf("%f %f",&x0,&x1);
    printf("\nPlease enter the value of accepted error: ");
    scanf("%f", &e);
    float y0 = function(x0);
    float y1 = function(x1);
    int i=0;
    if(sign(y0,y1)){
        printf("\nThe starting values are unsuitable!");
        return 0; //Stopping the program
    }

    while(relErr(x1, x0)>e){
        x2 = (x0+x1)/2;
        y2 = function(x2);
        i++;
        if(sign(y0,y2)) x0=x2;
        else x1=x2;
    }

    printf("\nThe number of iterations is: %d",i);
    printf("\nx and y values are: %f  %f",x2,y2);
}