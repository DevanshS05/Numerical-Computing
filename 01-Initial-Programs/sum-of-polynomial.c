#include<stdio.h>

int main(){
    int n;
    float x;
    printf("Please enter the degree of the polynomial: ");
    scanf("%d", &n);
    printf("\nPlease enter the value for which you want to calculate the val of the poly: ");
    scanf("%f", &x);
    float coeff[n+1];
    //Reading coefficients from a(0) to a(N)
    for(int i=0;i<n+1;i++){
        printf("\nPlease enter the coefficent of X^(%d): ", n-1-i);
        scanf("%f", &coeff[i]);
    }
    float sum = coeff[0];
    for(int i=1;i<n+1;i++){
        sum = coeff[i] + sum*x;
    }
    printf("The sum of the polynomial is: %f", sum);
    printf("\n"); //Console starts from the next line
    return 0;
}