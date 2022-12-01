#include<stdio.h>

//Function for power calculation
float power(float num, int exp){
    float res=1;
    for(int i=0;i<exp;i++) res*=num;
    return res;
}

int main(){
    int x,n,r;
    printf("Please enter the degree of the polynomial: ");
    scanf("%d",&n);
    printf("\nPlease enter the values of x-r (divisor) seperately: ");
    scanf("%d %d",&x,&r);
    int coeff[n+1];
    printf("\nPlease enter the coefficient of: ");
    for(int i=0;i<n+1;i++){
        printf("\n x^%d: ", n-i);
        scanf("%d", &coeff[i]);
    }

    long ans[n-1], term=coeff[0];
    for(int i=1;i<n+1;i++){
        ans[i-1] = term;
        term = coeff[i]+r*term;
    }
    
    printf("\nPrinting out the coefficients of divisors: \n");
    long quotient = 0;
    for(int i=0;i<=n-1;i++){
        printf("%ld.x^%d ", ans[i], n-1-i);
        quotient = quotient + ans[i]*power(x, n-1-i);
    }
    printf("\nPutting in x=%d, we get quotient=%ld", x, quotient);
    printf("\n");
    return 0;
}