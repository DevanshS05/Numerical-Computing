#include<stdio.h>

float function(float x){
    return 5*(x*x*x) - 3*(x*x) + 2*x + 1;
}

float absVal(float x){
    return x>=0? x : x*-1;
}

float relErr(float x1, float x2){
    return absVal((x1-x2)/x1);
}

int main(){
    const float e = 0.001;
    float x1, x2, h;
    printf("Please enter the value of x1 and x2: ");
    scanf("%f %f", &x1, &x2);
    h = (x2-x1)/2;
    int i =2;
    float s1 = function(x1) + function(x2);
    float s2 = 0;
    s4 = function((x1+h));
    float i0 = 0;
    float in = (s1 + 4*s4)*(h/3);

    do{
        s2 = s2+s4;
        s4=0;
        float x = x1 + (h/2);
        for(int j=1;j<=i;j++){
            s4 = s4 + function(x);
            x = x+h;
        }
        h = h/2;
        i = 2*i;
        i0 = i1;
        in = (s1+2*s2+4*s4)*(h/3);
    }while(relErr(in, i0)>e);

    printf("\n The integral obatined is: %f with h=%f, i=%d",in, h, i);

    return 0;
}