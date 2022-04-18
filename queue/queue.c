
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


queue *queue_initialize(int n) {
	queue *q = (queue *)malloc(sizeof(queue));
	q->size_queue = n;
	q->buffer = malloc(sizeof(int)*n);
	q->start_of_queue = 0;
	q->end_of_queue = 0;
	q->count = 0;

	return q;
}

int queue_insert_(queue *q, int item) {
	if ((q == NULL) || (q->count == q->size_queue))
	   return -1;

	q->buffer[q->end_of_queue % q->size_queue] = item;	
	q->end_of_queue = (q->end_of_queue + 1) % q->size_queue;
	q->count++;

	return q->count;
}

/* this queue delete function is to delete a item from the queue) */
int queue_delete(queue *q) {
	if ((q == NULL) || (q->count == 0))
	   return -1;

	int x = q->buffer[q->start_of_queue];
	q->start_of_queue = (q->start_of_queue + 1) % q->size_queue;
	q->count--;

	return x;
}


void queue_display(queue *q) {
	int i;
	if (q != NULL && q->count != 0) {
		printf("queue has %d elements, start = %d, end = %d\n", 
			q->count, q->start_of_queue, q->end_of_queue);
		printf("queue contents: ");
		for (i = 0; i < q->count; i++)
	    		printf("%d ", q->buffer[(q->start_of_queue + i) % q->size_queue]);
		printf("\n");
	} else
		printf("queue empty, nothing to display\n");
}


void queue_destroy(queue *q) {
	free(q->buffer);
	free(q);
}

