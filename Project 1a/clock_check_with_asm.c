/************************************************************************************
 *
 * Name: clock_check.c
 * Author: Vignesh kannan (1207687217)
 * Purpose: This file is for project 1a. This provides the time to access the elements of array
            of various sizes provided by command line argument
 * Date: 01/26/2015
 *
 * *********************************************************************************/


#include <stdio.h>
#include <stdlib.h>


/*********************************************************************************************
 *
 * Name: rdtsc
 * Argument: void
 * Purpose: This is the function which runs asm instruction to read the contents of 
 * 64 bit counter which measures the clock cycle. THis works only on pentium.
 *
 * ********************************************************************************************/

static __inline__ unsigned long long rdtsc(void)
{
	  unsigned long long int x;
	       __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
	            return x;
}

/*********************************************************************************************
 *
 * Name: main
 * Argument: argv[0], argv[1]
 * Purpose: This is the main program which receives the size of the array as an argument from
            command line and allocates memory accordingly to check the access time.
 *
 * ********************************************************************************************/



int main(int argc, char* argv[])
{
	register int *test_array = NULL, i = 0;
	long long int  start_t, end_t, time_diff = 0;
	int sum = 0;
	if( argc  < 2 )
	{
		printf("Size of the array not given for checking. Please give values \n");
		printf("10, 100, 1000, 10000, 100000, 1000000, 10000000\n");
		exit(1);
	}

	long number_of_execution = *argv[1];
	test_array = (int *) malloc(number_of_execution * 4);
	if(NULL == test_array)
	{
		printf("Malloc Failure \n");
		exit(1);
	}	

	start_t = rdtsc(); //Start of the execution

	for(i = 0; i < number_of_execution; i++)
		sum += test_array[i];

	end_t = rdtsc(); //End of execution

	time_diff = end_t - start_t;

	printf("Start of the loop Start_t = %lld\n", start_t);
	printf("End of the loop End_t = %lld\n", end_t);
	printf("The Number of clock cycles for execution is %lld\n and the Number of clock cycles for one element is %f\n",            time_diff, (float)time_diff / number_of_execution);

	free(test_array);
	return 1;
}
