#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
#include <omp.h>


int stringToInt(const char* pString)
{
    return (int) strtol(pString, (char **)NULL, 10);
}

double stringToDouble(const char* pString)
{
    return (double)strtol(pString, (char **)NULL, 10);
}

int main(int argc, char const *argv[])
{

	clock_t begin = clock();

	int total = stringToInt(argv[1]);
	double entry= stringToDouble(argv[2]);
	double exitP= stringToDouble(argv[3]);
	
    int subTotal = 0;
    Queue queue = createQueue(0.50,0.60);
    time_t t;
	srand((unsigned) time(&t));
	#pragma omp parallel for 
    for(int i= 0;i<total;i++){
    	// addElement(&queue);
    	addElement(&queue);
    	removeElement(&queue);
    	printf(" %d --",queue.inQueue );
    	subTotal += queue.inQueue;
    }
    
    printf("\n Average elements in queue: %lf\n\n",(double)subTotal/total);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Spent time %lf\n", time_spent );
    return 0;
}

