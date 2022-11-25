//Algorithm for Lagrange Interpolation
#include <stdio.h>

int main() {
    int n;
    float x;
    printf("Please enter the value of x and n: ");
    scanf("%f %d",&x, &n);
    float xVal[n];
    float funcVal[n];
    
    //Reading the tabulated values
    printf("\nPlease enter the tabulated values as: x f(x)\n");
    for(int i=0;i<n;i++){
        printf("\nx%d && f(x%d) \t",i+1,i+1);
        scanf("%f %f", &xVal[i], &funcVal[i]);
    }
    
    float sum = 0;
    for(int i=0;i<n;i++){
        float prodFunc = 1;
        for(int j=0;j<n;j++){
            if(i!=j){
                prodFunc = prodFunc*((x-xVal[j])/(xVal[i]-xVal[j]));
            }
        }
        sum = sum + (funcVal[i]*prodFunc);
    }
    printf("\nThe value of the function is :%f at x=%f",sum, x);
    return 0;
}