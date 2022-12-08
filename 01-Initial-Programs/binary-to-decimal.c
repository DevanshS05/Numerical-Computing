//Program to convert a binary number to its decimal equivalent
#include <stdio.h>

int power(int base, int exp){
    int ans=1;
    for(int i=0;i<exp;i++) ans*=base;
    return ans;
}

int main() {
    char arr[20];
    printf("Please enter the binary number: ");
    scanf("%s", arr);
    
    //Calculating the position of the point
    int i=0;
    for(;i<strlen(arr);i++){
        if(arr[i]=='.') break;
    }

    float num=0;
    //Converting whole no part to decimal
    for(int j=i-1;j>=0;j--) num+=(power(2,i-1-j)*((int)arr[j]-48));
    
    //Converting the fractional part to decimal
    for(int j=i+1;j<strlen(arr);j++) num+=(1.0/power(2,j-i))*((int)arr[j]-48);
    
    printf("\nThe equivalent decimal number is: %f", num);
    return 0;
}