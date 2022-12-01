#include<stdio.h>

int main(){
    int n;
    float x;
    printf("Please enter the value of x and n: ");
    scanf("%f %d",&x,&n);
    float term=x, sum=x;
    for(int i=1;i<=n;i++){
        term= (-1*(x*x))*term / ((2*i+1)*(2*i));
        sum +=term;

    }
    printf("\nThe value of sin(%f) is : %f",x, sum);
    printf("\n"); //Console output from next line
    return 0;
}