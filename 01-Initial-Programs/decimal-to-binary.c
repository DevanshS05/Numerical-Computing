#include <stdio.h>
#include <math.h>
int main() {
    //Read the number as a float
    float num;
    printf("Please enter the decimal number you want to convert: ");
    scanf("%f",&num);
    long whole = (long)floor(num);
    float dec = num-whole;
    
    //Converting the whole number to binary
    long binWhole=0;
    int i = 1;
    while(whole>0){
        long rem = whole%2;
        whole = whole/2;
        binWhole += rem*i;
        i*=10;
    }
    printf("\nThe converted number is: %ld.", binWhole);
    //Converting the float part to binary
    //Limiting the conversion to a maximum of 6 decimal places
    if(dec==0) printf("0"); //Edge Case
    i=0;
    while(dec!=0 && i<6){
        dec*=2;
        if(dec>=1){
            dec-=1;
            printf("1");  
        }
        else printf("0");
        i++;
    }
    //printf("The converted whole number part is: %ld", binWhole);
    return 0;
}