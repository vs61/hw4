
#ifndef __QUEUE_H__
#define __QUEUE_H__


// creating userdefine queue using structures 
typedef struct _queue_ {
	int size_queue;    /* this integer variable will hold the maximum size of the queue */
	int *buffer; /* queue buffer */
	int start_of_queue;   /* starting index of the element in the queue*/
	int end_of_queue;     /* emding index of element in the queue*/
	int count;   /* number of elements presents in the queue */
} queue;

queue *queue_initialize(int n);
int queue_insert_(queue *q, int item);
int queue_delete_(queue *q);
void queue_display(queue *q);
void queue_destroy(queue *q);

#endif
