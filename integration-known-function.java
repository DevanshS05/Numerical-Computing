import java.util.Scanner;

class integration{

    static double relErr(double x1, double x2){
        return Math.abs((x2-x1));
    }

    static double function(double x){
        //return num; //Starting with our linear function here
        return 5*(x*x*x) - 3*(x*x) + 2*x + 1;
    }

    public static void main(String[]args){
        final double e = 0.0001; //Accepted Value of Relative Error

        Scanner myScanner = new Scanner(System.in);
        System.out.println("Please enter the range of integration: ");
        double x1 = myScanner.nextInt();
        double x2 = myScanner.nextInt();
        double h = (x2-x1)/2;
        int k = 3;
        double x = x1; //Variable to temporarily store the initial x
        double integral = 0; //Stores the value of the integral initially calculated
        for(int i=1;i<=k;i++){
            if(i==1 || i==k) integral += (function(x)/2);
            else integral += function(x);
            x = x+h;

        }
        integral *= h;
        System.out.println("The initial value of the integral so calculated is: " + integral);

        double oldIntegral = integral+1.0;

        while(relErr(integral, oldIntegral)>e){
            h = h/2;
            x = x1;
            oldIntegral = integral;
            integral = 0;
            for(;x<=x2;x=x+h){
                if(x==x1 || x==x2) integral += (function(x)/2);
                integral += function(x);
                x = x+h;
            }
            integral *= h;
            System.out.printf("\nThe value of the integral obtained here is: %.4f", integral);
            System.out.printf("\nThe relative error between the two integrals is : %.5f",relErr(integral, oldIntegral));
        }
    }
}