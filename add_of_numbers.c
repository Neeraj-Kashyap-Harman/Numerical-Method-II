#include<stdio.h>
#include<mpi.h>
#include<unistd.h>

int main(int argc,char **argv)
{
	int size,myrank,a=0,sumOfAll=0;
	int chunkSize,noOfElements=100,startSize,i;
	//MPI_Status status_of_first,status_of_second,status_of_third,status_of_fourth,MPI_Status_IGNORE;
		
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&myrank);	
	chunkSize=noOfElements/size;
	//	sleep(myrank); 	
	startSize=chunkSize*myrank;
	printf ("ChunkSize=%d startSize=%d \n",chunkSize,startSize);

		
	if (myrank==0)
		{
					for (i=startSize;i<chunkSize;i++)
					{	a=a+startSize;
						MPI_Send(&a,1,MPI_INT,1,1,MPI_COMM_WORLD);		
					}
				
		}				

	if(myrank==1)
		{	
				
				for (i=startSize;i<chunkSize;i++)
				{		sumOfAll+=a;	
					MPI_Recv(&a,1,MPI_INT,0,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);		
				}
				printf ("Sum:%d",sumOfAll);	
		}	
				
					

	MPI_Finalize();					
/*	if (myrank==0)
		{
			for (i=startSize;i<chunkSize;i++)
				{
					a=a+startSize;
					b=b+startSize;
					c=c+startSize;
					d=d+startSize;	
				}					

			MPI_Send(a,25,MPI_INT,1,1,MPI_COMM_WORLD);
			MPI_Send(b,50,MPI_INT,1,2,MPI_COMM_WORLD);
			MPI_Send(c,75,MPI_INT,1,3,MPI_COMM_WORLD);
			MPI_Send(d,100,MPI_INT,1,4,MPI_COMM_WORLD);						
		
		}
	else if (myrank==1)
		{

			sumOfAll=a+b+c+d;
			MPI_Recv(a,25,MPI_INT,0,1,MPI_COMM_WORLD,status_of_first);
			MPI_Recv(b,50,MPI_INT,0,2,MPI_COMM_WORLD,status_of_second);
			MPI_Recv(c,75,MPI_INT,0,3,MPI_COMM_WORLD,status_of_third);
			MPI_Recv(d,100,MPI_INT,0,4,MPI_COMM_WORLD,status_of_fourth);						
	
		}
*/
}

