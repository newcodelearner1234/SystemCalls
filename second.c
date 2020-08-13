#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t ret_id;

	ret_id=fork();

	if(ret_id<0)
		printf("\n Fork Failed\n");      //fork has failed
	else if(ret_id==0)
	{
		printf("\n Inside Child process \n");   //child process
		printf("The process id is %d\n",getpid());

		int num,index;
		int factorial=1;

		printf("\n Enter an Integer to find its factorial :");
		scanf("%d",&num);


		if(num<0)
			printf("\n Invalid number entered,Enter a positive integer ");
		else
		{
			for(index=1;index<=num;index+=1)
			{
				factorial*=index;
			}
		printf("\n\n Factorial of %d is %d ",num,factorial);
		}
	}
	else
	{
		//parent
		wait();

		printf("\n\n Inside Parent Process... ");
		printf("\n The process id is %d\n",getpid());

		int start,end;
		printf("\n Enter start and end of a range: ");
		scanf("\n%d%d",&start,&end);

		while(start<=end)
		{
			int i=1;
			printf("Multiplication table of %d :\n",start);
			printf("\n--------------------------------------\n");
			while(i<=10)
			{
				printf("%d X %d = %d \n",start,i,start*i);
				i+=1;
			}
			start+=1;
		}
	}
	return 0;
}
