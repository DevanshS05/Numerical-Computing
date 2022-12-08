#include<stdio.h>


float function(float x){
    return (2*(x*x*x)-3*(x*x)+4*x-5);
}

int main(){
    int n = 2; //No of points in the gauss-legendre-function

    float a,b;
    printf("Please enter the value of a and b: ");
    scanf("%f %f",&a, &b);
    float R[n];
    float x[n];

    for(int i=0;i<n;i++){
        printf("\nPlease enter R%d x%d: ",i+1,i+1);
        scanf("%f %f",&R[i], &x[i]);
    }
    float p = (a+b)/2;
    float q = (b-a)/2;
    float integral = 0;
    for(int i=0;i<n;i++){
        float f = function((p+q*x[i]));
        integral += R[i]*f;
    }
    integral = q*integral;
    printf("The value of the integral so obtained is: %f", integral);
}