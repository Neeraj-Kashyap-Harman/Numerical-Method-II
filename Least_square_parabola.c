/*
	Name: 					Least Square parabola fit
	Author: 				Neeraj Kashyap
	Date:					01/05/18 10:58
	Description:            This program describes about curve fit. In this program,I have used Least Square Parabola fit.
*/




#include<stdio.h>
#include<math.h>

float squaring(float x[100],float y[100],int i_no_of_points);
float cubing(float x[100],int i_no_of_points);
float tesseracts(float x[100],int i_no_of_points);
float squar(float x[100],float y[100],int i_no_of_points);
int main ()
	{
		
		int i_no_of_points,loops;
		float x[100],y[100],square,cube,tesseract,sum_x_y=0.0,mult_x_y,sum_x_2,sum_xsqaure;
		
		float  xsum=0.0,ysum=0.0,d,dx,dy,dz;
		printf ("\n Least Square Parabola Method");
		
		printf ("\n Enter the number of points \n");
		scanf("%d",&i_no_of_points);
	
		printf ("X  and   Y\n");
		
		/*
			loops is used for the for loop
			x[loops] is the point of x.The number is accepted by user.
			y[loops] is the point of y.The number is accepted by user.
		*/
		
		
		for (loops=0;loops<i_no_of_points;loops++)
		{
			scanf ("%f",&x[loops]);
			scanf ("%f",&y[loops]);
		}
		printf ("\nX\t\tY\n");
		for (loops=0;loops<i_no_of_points;loops++)
		{
			printf ("%f\t",x[loops]);
			xsum=xsum+x[loops];						// This gives the summation of the x[loops]
			printf ("%f\n",y[loops]);
			ysum=ysum+y[loops];						// This gives the summation of the y[loops]
			printf ("\n");
		    
			
			square=squaring(x,y,i_no_of_points);
			sum_xsqaure=squar(x,y,i_no_of_points);
			cube=cubing(x,i_no_of_points);
			tesseract=tesseracts(x,i_no_of_points);
			
			mult_x_y=x[loops]*y[loops];				// This term multiplies the x and y	
		//	printf ("%f",mult_x_y);
			sum_x_y=sum_x_y+mult_x_y;				// This gives the summation of the multiplication of x*y
		}			

	
		printf ("\n SUM OF X=%f",xsum);				/*The SUM IS DISPLAYED HERE*/
		printf ("\n SUM OF Y=%f",ysum);
	
		printf ("\n SUM OF X^2=%f",sum_xsqaure);		
		printf ("\n SUM OF X^3=%f",cube);
		printf ("\n SUM OF X^4=%f",tesseract);
		printf ("\n SUM OF X^2 and Y=%f",square);		
		printf ("\n SUM OF X*Y=%f",sum_x_y);
		
		
		
		printf ("\n FOR SOLVING THE EQUATIONS:\n");
		printf (" \n The form should be \n A*x^4+B*x^3+C*x^2=x^2*y \n A*x^3+B*x^2+C*x=x*y \n A*x^2+B*x+N*C=y");
	
		printf ("\n");
			
						printf(" \n %f*A + %f*B + %f*C = %f",tesseract,cube,sum_xsqaure,square);
						printf(" \n %f*A + %f*B + %f*C = %f",cube,sum_xsqaure,xsum,sum_x_y);
						printf(" \n %f*A + %f*B + %f*C = %f",sum_xsqaure,xsum,i_no_of_points,ysum);


printf ("\n x,y,z has been found by Crammer's rule :");

d=(((tesseract)*((sum_xsqaure*i_no_of_points)-(xsum*xsum)))-((cube)*((cube*i_no_of_points)-(xsum*sum_xsqaure)))+((sum_xsqaure)*((cube*xsum)-(sum_xsqaure*sum_xsqaure))));
dx=((((square)*((sum_xsqaure*i_no_of_points)-(xsum*xsum)))-((cube)*((sum_x_y*i_no_of_points)-(xsum*ysum)))+((sum_xsqaure)*((sum_x_y*xsum)-(sum_xsqaure*ysum))))/d);
dy=((((tesseract)*((sum_x_y*i_no_of_points)-(xsum*ysum)))-((square)*((cube*i_no_of_points)-(xsum*sum_xsqaure)))+((sum_xsqaure)*((cube*ysum)-(sum_x_y*sum_xsqaure))))/d);
dz=((((tesseract)*((sum_xsqaure*ysum)-(sum_x_y*xsum)))-((cube)*((cube*ysum)-(sum_x_y*sum_xsqaure)))+((square)*((cube*xsum)-(sum_xsqaure*sum_xsqaure))))/d);



printf ("\n The FORM of Equation is A*x^2+B*x+C:\n");


printf ("Y=%f x^2 + (%f) x +%f ",dx,dy,dz);
	
	}
	
		/*
				Description: This function is used to find the x*x
				INPUT:  points of x, number of points considered by user
				OUTPUT: returns the summation of the x*x
		*/ 


	
						float squar(float x[100],float y[100],int i_no_of_points)
						{
								float sum_xsqaure=0.0,term;//,term1,sum_x_2=0.0;
								int loops;
								
								for (loops=0;loops<i_no_of_points;loops++)
								{
										term=(x[loops]*x[loops]);
										sum_xsqaure=sum_xsqaure+term;
//										term1=term*y[loops];
//										square=square+term1;
								}
								//return square;
								return sum_xsqaure;
								
						}

							
				
		/*
				Description: This function is used to find the x^2*y and x*y
				INPUT:  points of x,points of y,number of points considered by user
				OUTPUT: returns the summation of the x*y,x^2*y
		*/ 

	
	
				float squaring(float x[100],float y[100],int i_no_of_points)
						{
								float square=0.0,term,term1,sum_x_2=0.0;
								int loops;
								
								for (loops=0;loops<i_no_of_points;loops++)
								{
										term=(x[loops]*x[loops]);
										sum_x_2=sum_x_2+term;
										term1=term*y[loops];
										square=square+term1;
								}
								return square;
								return sum_x_2;
								
						}
						
						
		/*
				Description: This function is used to find the x^3
				INPUT:  points of x,number of points considered by user
				OUTPUT: returns the summation of the x^3
		*/ 


									float cubing(float x[100],int i_no_of_points)
									{
											float cube=0.0,term;
											int loops;
										
												for (loops=0;loops<i_no_of_points;loops++)
													{
														term=pow(x[loops],3);
														cube=cube+term;
																			
													}
													 return cube;
									}
							


					/*
							Description: This function is used to find the x^4
							INPUT:  points of x,number of points considered by user
							OUTPUT: returns the summation of the x^4
					*/ 
					
														float tesseracts(float x[100],int i_no_of_points)
														{
																float tesseract=0.0,term;
																int loops;
										
															for (loops=0;loops<i_no_of_points;loops++)
																{
																	term=pow(x[loops],4);
																	tesseract=tesseract+term;
																						
																}
																	return tesseract;
														}

