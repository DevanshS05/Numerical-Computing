/*
Program for Polygon-Method for solving a differential equation
where in the y(i+1) is calculated as follows: 
y(i+1) = y(i) + h.f( x(i)+h/2 , y(i)+(h/2)*f( x(i), y(i)) )
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

    printf("   x    ||    y  ");

    while(x1<=xFinal){
      printf("\n%6.5f || %6.5f",x1,y1);
      y1 = y1 + (h*function(x1+(h/2), y1 + (h/2)*function(x1,y1)));
      x1+=h; 
    }

    printf("\n"); //Pushes the console output to start from the next line
    return 0;
}