/*
	Name: 						Composite Trapezoidal rule program
	Author: 					Neeraj Kashyap
	Date: 02/05/18 09:35
	Description: 				This is a program of Composite Trapezoidal Rule written in C language.
*/


#include<stdio.h>
#include<math.h>

int main ()
{
	float a,b,h,xj[100],fa,fb,fxj,sumfxj=0.0,trapezoidal_ans;
	int loops,i_no_of_intervals;
	
	printf ("\n By Composite Trapezoidal rule");
	
	
	printf ("\n The function is f(x) = 1-((e^-x)*(sin (4*x)))");
	
	
	printf ("\n Enter the starting and the ending point respectively");
	scanf ("%f%f",&a,&b);
	
	printf ("\n Enter the number of intervals:");
	scanf ("%d",&i_no_of_intervals);

			if (i_no_of_intervals>0)
			{
			h=(b-a)/i_no_of_intervals;
						
						printf ("H=%f\n\n",h);
						
						xj[0]=a;
						printf ("X0(X0 and a are same)=%f\n",loops,xj[0]);
					
					for (loops=0;loops<i_no_of_intervals;loops++)
					{
							xj[loops]=xj[loops-1]+h;					
							printf ("X%d=%f\n",loops+1,xj[loops]);
					}
				
				fa=(1-((exp(a))*(sin(4*a))));		
				printf ("F(a)=%f\n",fa);
					
				fb=(1-((exp(b))*(sin(4*b))));		
				printf ("F(b)=%f",fb);
				
					
					for (loops=1;loops<i_no_of_intervals-1;loops++)
					{
							fxj=(1-((exp(xj[loops]))*(sin(4*xj[loops]))));
							printf ("\nF(x%d)=%f",loops,fxj);
							sumfxj=sumfxj+fxj;
							
					}
					
					printf ("\nSUM=%f",sumfxj);
					
					
					trapezoidal_ans= ((h/2)*(fa+(2*sumfxj)+fb));
					
					printf ("\nComposite Trapezoidal Rule=%f",trapezoidal_ans);
			
			}
	
	else
	{
				printf ("\n Enter the Correct number\n It shoudl be greater than 0");
	}		
}
