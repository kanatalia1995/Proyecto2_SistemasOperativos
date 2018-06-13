#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct queue {
	double entry_p; 
	double exit_p;
   int inQueue;
} Queue; 



Queue createQueue(double pEntry , double pExit){
	Queue queue; 
	queue.entry_p = pEntry;
	queue.exit_p = pExit;
	queue.inQueue = 0; 
	return queue;
}


int isEmpty(int queueElements){
	if (queueElements <= 0)return 1;
	return 0;
}
//https://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
int randint(int n) {
	int last = rand() % n;
    return last;
}

double getProbability(){
	int random =  randint(1000);
	return random / 1000.0;	
}

int allowAction(double probability){
	double random = getProbability();
	// printf("rand %lf\n",random );
	if (random < probability) return 1; 
	else return 0;
}


int addElement(Queue* queue){
	if (allowAction(queue->entry_p)){
		queue->inQueue++;
		return 1;
	}else {
		return 0;
	}
}
int removeElement(Queue* queue){
	if (allowAction(queue->exit_p)){
		if (!isEmpty(queue->inQueue)) queue->inQueue--;
		return 1;
	}else {
		return 0;
	}
}



