#include<stdio.h>
#include<stdbool.h>
int func(float num){
	return (num*num-25.0);
}

float absoluteValue(float num){
	if(num<0) return num*-1.0;
	else return num;
}

bool sameSign(float num1, float num2){
	return false;
}

int main(){
	int n;
	float x0, x1,x2, f0, f1, f2, e;
	printf("Please enter the values of initial guess along with no of iterations: ");
	scanf("%f %f %d",&x0, &x1, &n);
	printf("\nPlease enter the value of accepted error: ");
	scanf("%f",&e);
	
	
	//Calculating the values of f0 and f1
	f0=func(x0), f1=func(x1);
	int i=1;
	for(;i<=n;i++){
		x2 = (x0*f1-x1*f0)/(f1-f0);
		f2 = func(x2);
		if(absoluteValue(f2)<=e){
			printf("\nConvergent Solution x2:%f f2:%f",x2, f2);
			return 0;
		}
		if(!sameSign(f2, f0)){
			x1 = x2;
			f1 = f2;
		}
		else{
			x0 = x2;
			f0 = f2;
		}
	}
	printf("\nDoes not converge in n iterations: x2:%f f2:%f");
	return 0;		
}
