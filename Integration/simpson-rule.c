/*
Program to find the integral of function using Simpsons Rule which gives the integral as 
Integral f(x) = h/3*[f(x1) + 4*f(x2) + 2*f(x3) + 4*f(x4) + ... + f(x(n+1))]
However one thing to note here is that the number of funcational values should be odd i.e. n+1 shoudld be an odd number
*/
#include <stdio.h>

int main() {
    float h;
    printf("Please enter the value of h (consecutive difference): ");
    scanf("%f", &h);
    
    int n;
    printf("\nPlease enter the value of n (1 less than the number of functional values): ");
    scanf("%d", &n);
    
    float funcVal[n+1];
    for(int i=0;i<n+1;i++){
        printf("\n f(x%d):\t", i+1);
        scanf("%f", &funcVal[i]);
    }
    float sum = funcVal[0] + funcVal[n];
    for(int j=2;j<=n;j=j+2){
        sum = sum + 4*funcVal[j-1];
    }
    for(int j=3;j<=n-1;j=j+3){
        sum = sum + 2*funcVal[j-1];
    }
    sum = (h*sum)/3;
    printf("\nThe integral obtained is: %f", sum);
    return 0;
}