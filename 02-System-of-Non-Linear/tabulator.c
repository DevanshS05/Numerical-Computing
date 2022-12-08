#include<stdio.h>

float power(float base, float exp){
    float res = 1;
    for(int i=0;i<exp;i++) res*=base;
    return res;
}

float funcVal(int n,float coeff[], float num){
    float sum=0;
    for(int i=0;i<n+1;i++) sum+=(coeff[i]*power(num, n-i));
    return sum;
}

int main(){
    int n;
    printf("\nPlease enter the degree of the function: ");
    scanf("%d",&n);
    printf("\nPlease enter the coefficients: ");
    /*
    The coefficients are to be entered in the following order:
    x^n + x^(n-1) + ... + x^0
    */
    float coeff[n+1];
    for(int i=0;i<n+1;i++){
        printf("\nEnter the coefficient for x^%d: ",n-i);
        scanf("%f", &coeff[i]);
    }
    //Taking values from -100 to +100 with increments of five and printing the
    //corresponding values of the function
    printf("\nInput -----> Function Value");
    for(float z=-10;z<=10;z+=0.1) printf("\n %f -----> %f",z,funcVal(n, coeff, z));
    return 0;
}