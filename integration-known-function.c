
#include <stdio.h>

float func(float x){
    return 5*(x*x*x) - 3*(x*x) + 2*x + 1;
}

float absVal(float x){
    return x>=0? x : x*-1;
}

float relErr(float x1, float x2){
    return absVal((x1-x2)/x1);
}

int power(int base, int exp){
    int ans = 1;
    for(int i=0;i<exp;i++) ans*=base;
    return ans;
}

int main() {
    float x1, x2, h;
    float e = 0.001;
    int k = 3,p = 1;
    printf("Please enter the range of integral: ");
    printf("\nEnter x1: ");
    scanf("%f", &x1);
    printf("\nEnter x2: ");
    scanf("%f", &x2);
    h = (x2-x1)/2;
    
    float integral = 0;
    float x = x1;
    for(int i=1;i<=k;i++){
        //printf("\nDebugging: x:%f f(x):%f",x,func(x));
        if(i==1 || i==k) integral += (func(x)/2);
        else integral += func(x);
        x = x+h;
    }
    integral *= h;
    printf("\n The integral so obatined is: %f", integral);
    
    float oldIntegral = integral;
    
    do{
        h = h/2;
        k = power(2,++p) +1;
        oldIntegral = integral;
        integral = 0;
        x = x1;
        printf("\n=========================\n");
        printf("Starting calc with p=%d x1=%f",p, x1);
        
        for(int i=1;i<=k;i++){
            printf("\nx=%f h=%f k=%d", h, x, k);
            if(i==1 || i==k){
                integral += (func(x)/2);
            }
            else{
                integral += (func(x));
            }
        }
        integral *= h;
    }while(relErr(integral, oldIntegral)>e);
    
    printf("\nThe value of integral obtained after improvisation is: %f with k=%d and p=%d", integral, k, p);
    return 0;
}