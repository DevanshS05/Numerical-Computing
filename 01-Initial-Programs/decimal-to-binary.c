/*Program to convert a given decimal number to binary*/
#include<stdio.h>

int main(){
    long w;
    float d;
    printf("The decimal number is represented in the following format 1234.6534");
    printf("\nKindly enter the whole no. and fractional part independently as asked: ");
    printf("\nPlease enter the whole no. part: ");
    scanf("%ld", &w);
    printf("\nPlease enter the fractional part: ");
    printf("%f",&d);

    printf("\n");//Printing the converted number from the next line
    //Converting the whole number part to binary
    while(w>1){
        printf("%ld",w%2);
        w=w/2;
        if(w==1){
            printf("1");
            break;
        }
    }
    //Printing the decimal point
    printf(".");
    //Converting the decimal point to binary
    for(int i=0;i<5;i++){
        d*=2.0;
        if(d>=1){
            printf("1");
            if(d==1.0){
                break;
            }
            d-=1;
        }
        else{
            printf("0");
        }
    }
    return 0;
}