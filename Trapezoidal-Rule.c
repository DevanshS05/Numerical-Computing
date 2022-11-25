//Implementation of Trapezoidal Rule of Integration
/*
According to the Trapezoidal Rule:
Integral f(x) = h*(f(1)/2 + f(2) + f(3) + ... + f(n+1)/2)
*/
#include <stdio.h>

int main() {
    float h;
    printf("Please enter the value of h (consecutive difference): ");
    scanf("%f", &h);
    
    int n;
    printf("\nPlease enter the value of n (1 Less than no of values of function) : ");
    scanf("%d", &n);
    
    float funcVal[n+1];
    for(int i=0;i<n+1;i++){
        printf("\n Value of f(x%d):\t", i+1);
        scanf("%f", &funcVal[i]);
    }
    
    float sum = (funcVal[0]+funcVal[n])/2;
    for(int j=2;j<=n;j++){
        sum = sum + funcVal[j-1];
    }
    sum = h*sum;
    printf("\n The value of the integral is: %f",sum);
    return 0;
}