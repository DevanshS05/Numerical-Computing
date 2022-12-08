#include<stdio.h>

float abs(float num){
    return num<0? num*-1 :num;
}

int main(){
    const float e = 0.001;
	int n;
	printf("Please enter the number of variable you want to solve for: ");
	scanf("%d", &n);
	float coeff[n][n+1]; //Array to store our coefficients of equations
	float x[n]; //Array to store our solutions of x;

	int i,j,k;
	//Loop to read the coefficients
	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++)
		{
			printf("Please enter the coeff. a%d%d : ",(i+1),(j+1));
			scanf("%f",&coeff[i][j]);
		}
	}
	
	//Algorithm for triangularization
	for(k=1;k<=n-1;k++){
		for(i=k+1;i<=n;i++){
			float u = coeff[i-1][k-1]/coeff[k-1][k-1];

            //Improvisation for pivotal condesation

            float max = abs(coeff[k-1][k-1]);
            int p = k;
            for(int m=k+1;k<=n;k++){
                if(abs(coeff[m-1][k-1]>max)){
                    max = abs(coeff[k-1][k-1]);
                    p = m;
                }
            }
            if(max<e){
                printf("\nIll-Conditioned Equations");
                return 0;
            }
            else if(p==k) goto normal;
            for(int q=k;q<=n+1;q++){
                float temp = coeff[k-1][q-1];
                coeff[k-1][q-1] = coeff[p-1][q-1];
                coeff[p-1][q-1] = temp;
            }
            
            normal :
			//printf("\n %f",u);
			for(j=k;j<=n+1;j++){
				coeff[i-1][j-1] = coeff[i-1][j-1]-u*coeff[k-1][j-1];
			}
		}
	}

	//Algorithm for backward substitution
	x[n-1] = coeff[n-1][n]/coeff[n-1][n-1];
	for(i=n-1;i>=1;i--){
		float sum = 0;
		for(j=i+1;j<=n;j++){
			sum = sum + coeff[i-1][j-1]*x[j-1];
		}
		x[i-1] = (coeff[i-1][n]-sum)/coeff[i-1][i-1];
	}
	
	//Printing the solutions of the variables so obtained
	printf("\nThe solutions obtained are as follows:\n");
	for(i=0;i<n;i++){
		printf("  x%d = %.3f  ",i+1,x[i]);
	}

	return 0;
}
