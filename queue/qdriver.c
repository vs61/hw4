
#include <stdio.h>
#include "queue.h"


int main(int argc, char **argv) {
	queue *q;
	int i;

	/* creating a userdefined queue data structure */
	q = queue_initialize(10);


	for (i = 0; i < 5; i++) {
	    queue_insert_(q, 100+i);
	    queue_display(q);
	}

	for (i = 0; i < 5; i++) {
	    queue_delete(q); 
	    queue_display(q);
	}
	/* insert 11 items to the queue */
	for (i = 0; i < 11; i++) {
	    if (queue_insert_(q, 200+i) != -1)
	        queue_display(q);
	    else
		printf("queue full, insertion failed!\n");
	}
	
	for (i = 0; i < 11; i++) {
	    if (queue_delete(q) != -1) 
	        queue_display(q);
	    else
		printf("queue empty, deletion failed!\n");
	}
	
	queue_destroy(q);

	return 0;
}

