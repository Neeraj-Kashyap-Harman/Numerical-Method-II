/*
	Name: 					Composite Simpson's Rule 
	Author: 				Neeraj Kashyap
	Date: 02/05/18 10:16
	Description: 			This program computes the composite simpson's Rule
*/


#include<stdio.h>
#include<math.h>

float passtheinitials(float a,float b,int i_no_of_intervals);


int main ()
{
	float a,b,h;
	int i_no_of_intervals;			// Taken the no_of_intervals,input by user
	
	printf ("\n Solve by Composite Simpson's 1/3rd Rule");
	
	printf ("\n The function is f(x) = 1-e^-x *(sin (4*x))");
	
	
	printf ("\n Enter the starting and the ending point respectively");
	scanf ("%f%f",&a,&b);
	
	printf ("\n Enter the number of intervals:");
	scanf ("%d",&i_no_of_intervals);

			if (i_no_of_intervals>0)
			{
				passtheinitials(a,b,i_no_of_intervals);
			}
					else
					{
						printf ("\n You cannot enter the negativ number");
					}	
}
					/*
						Description: This function gives the result of the composite simpson's rule.
						INPUT: the value of a and b,as well as the no.of intervals.
						OUTPUT: the result is the composite simpson's answer. 

					*/

			float passtheinitials(float a,float b,int i_no_of_intervals)	
				{
						float h,fa,fb,xj[100],fxj,sumfxj=0.0,fxj1,sumfxj1=0.0,composite_simpson_rule;
						int loops;
						
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
			
			
						for (loops=1;loops<((i_no_of_intervals/2)-1);loops++)
						{
							fxj=(1-((exp(xj[2*loops]))*(sin(4*xj[2*loops]))));
							printf ("\nF(x%d)=%f",2*loops,fxj);
							printf ("\nEVEN\n");
							sumfxj=sumfxj+fxj;
						}
						
						
						for (loops=1;loops<(i_no_of_intervals/2);loops++)
						{
							fxj1=(1-((exp(xj[((2*loops)-(1))]))*(sin(4*xj[((2*loops)-(1))]))));
							printf ("\nF(x%d)=%f",((2*loops)-1),fxj1);
							printf ("\nODD\n");
							sumfxj1=sumfxj1+fxj1;
						}
				
						
					composite_simpson_rule=((h/3)*(fa+fb+(2*sumfxj)+(4*sumfxj1)));
					
					printf ("Composite Simpson's Rule =%f",composite_simpson_rule);
									
				}
			

