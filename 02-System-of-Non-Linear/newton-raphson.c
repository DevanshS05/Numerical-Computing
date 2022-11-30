#include<stdio.h>

float func(float x){
	return ((x*x*x)-(4*x)+1);
}

float derivative(float x){
	return (3*(x*x)-4);
}

float absoluteValue(float num){
	if(num<0) return num*-1.0;
	else return num;
}

float relError(float num1, float num0){
	return absoluteValue((num1-num0)/num1);
}

int main(){
	int n,i;
	float x0, x1, epsilon, delta, f0, fdash;
	printf("\nPlease enter the guess value followed by epsilon and delta: ");
	scanf("%f %f %f",&x0, &epsilon, &delta);
	printf("\nPlease enter the number of iterations: ");
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		f0 = func(x0);
		fdash = derivative(x0);
		if(absoluteValue(fdash)<=delta){
			printf("\nSlope too small. Exiting with the following values");
			printf("\nx0:%f f0:%f fdash:%f i:%d",x0, f0, fdash, i);
			return 0;
		}
		x1 = x0 - (f0/fdash);
		if(relError(x1, x0)<epsilon){
			printf("\nConverges to root!");
			printf("\nx1:%f f0:%f i:%d",x1, f0, i);
			return 0;
		}
		x0 = x1;
	}
	printf("\nDoes not converge in n iterations");
	getch();
	return 0;
}
