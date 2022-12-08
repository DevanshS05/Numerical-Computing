#include <stdio.h>

float function(float x){
    //return 5*(x*x*x) - 3*(x*x) + 2*x + 1;
    //return (2*x);
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
    const float e = 0.001;
    float x, h, x1;
    int k;
    printf("Please enter the value of x: ");
    scanf("%f", &x);
    printf("\nPlease enter the value of h: ");
    scanf("%f", &h);
    printf("\nPlease enter the value of k: ");
    scanf("%d", &k);
    x1 = x;
    
    float func[k];
    for(int i=1;i<=k;i++){
        func[i-1] = function(x);
        x = x+h;
    }
    
    float s1 = (func[0]+func[k-1])/2;
    for(int j=2;j<=k-1;j++){
        s1 += func[j-1];
    }
    float i1 = h*s1, i0;
    int i = k-1;
    do{
        i0 = i1;
        x = x1 + (h/2);
        for(int j=1;j<=i;j++){
            s1 += function(x);
            x=x+h;
        }
        i = 2*i;
        h = (h/2);
    }while(relErr(i1,i0));
    printf("\nThe integral so obtained is: %f, h=%f, i=%d",i1, h, i);
}