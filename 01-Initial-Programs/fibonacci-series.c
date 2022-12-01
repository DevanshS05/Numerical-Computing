#include<stdio.h>

int main(){
    int a=0,b=1,c,n;
    printf("Please enter the range upto where you want to print the series: ");
    scanf("%d", &n);
    printf("\n%d %d",a,b);
    for(int i=2;i<n;i++){
        c = a+b;
        printf(" %d",c);
        a=b;
        b=c;
    }
    printf("\n"); //So that console prints from next line
    return 0;
}