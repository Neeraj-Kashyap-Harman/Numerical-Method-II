/*
	Name:								Newton-Raphson Method 
	Author: 							Neeraj Kashyap
	Date: 30/04/18 22:52
	Description: 							This is a C program in which the equation x^3-3*x+2 is solved by newton raphson method.  solve by entering 2.2
*/


#include<stdio.h>
#include<math.h>

int main ()
{
	int  no_of_iterations,i_iter;			//i_iter is used for for loop and no_of_iterations is used for how many iterations does a user needs
	float p[10],x[10],x1[10]; 				// p[] is the point ,x is the equation and x1 is the differential equation
	
	printf ("\n Newton-Raphson Program \n Equation: x^3-3*x+2 \n");

		//3*x^2-3;
	
	printf ("\n Enter the number of iterations you want to do:");
	scanf ("%d",&no_of_iterations);	
	
	
	printf ("\n Enter the number from where you have to start:");
	scanf ("%f",&p[0]);
	
			
		printf ("\n In this equation we take p0=%f \n",p[0]);
								
								printf ("\n The Solution is :\n");
																	
			for (i_iter=0;i_iter<no_of_iterations;i_iter++)
				{	
								x[i_iter]=(pow(p[i_iter],3)-(3*p[i_iter])+2);
								x1[i_iter]=(3*(pow(p[i_iter],2))-3);
								p[i_iter+1]=(p[i_iter]-(x[i_iter]/x1[i_iter]));		
				
					printf ("P%d=%f\n",i_iter,p[i_iter]);
				}	
				
}
