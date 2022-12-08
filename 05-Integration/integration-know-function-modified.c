#include<stdio.h>

float function(float x){
    return 2*x;
}

float absVal(float x){
    return x>=0? x : x*-1;
}

float relErr(float x1, float x2){
    return absVal((x1-x2)/x1);
}

int main(){
    const float e = 0.001;
    int i = 2;
    float x1, x2;
    printf("Please enter the value of x1 and x2: ");
    scanf("%f %f",&x1, &x2);
    float h = (x2 -x1)/2;
    float s1 = (function(x1) + function(x2))/2;
    float i1 = h*s1;
    float i0 = i1;

    do{
        i0 = i1;
        float x = x1 + h/2;
        for(int j=1;j<=i;j++){
            s1 = s1 + function(x);
            x = x + h;
        }
        i = 2*i;
        h = h/2;
        i0 = i1;
        i1 = (h*s1);
    }while(relErr(i1, i0)>e);
    printf("The value of the integral obtained is: %f with h=%f, i=%d", i1, h, i);
}
