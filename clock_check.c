#include <stdio.h>
#include <time.h>
#define NUMBER_OF_EXECUTION 100000000

int main(int argc, char* argv[])
{
	double time_diff = 0;
	clock_t begin, end = 0;
	int test_array[NUMBER_OF_EXECUTION];
	int i = 0;

	begin = clock();
	for(i = 0; i < NUMBER_OF_EXECUTION; i++)
		test_array[i] = 1;

	end = clock();

	time_diff =(double) (end - begin)/CLOCKS_PER_SEC;
	printf("The Time for execution is %f\n", time_diff);
	return 0;
}
