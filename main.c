#include <stdbool.h>
#include <stdlib.h>
#include "Header.h"
#include <stdio.h>
#include <assert.h>


typedef struct Queue{
	int* memory;
	size_t capacity;
	int i;
	bool used;
	int* rear;
	int* front;
	int queue[1000];
		
}Queue;


Queue queue_pool[10];



Queue* Queue_create(int* memory, size_t capacity) // creates a new queue with a certain capacity and reserved memory
{
	if (capacity <= 1000)                       // works only if the user stays within 1000
	{
		for (int i = 0; i < 10; i++)
		{
			Queue queue = queue_pool[i];		// creates queue out of the queue_pool
			if (queue_pool[i].used == false)	// checks if the queue out of the pool is empty
			{
				queue.memory = memory;			//sets the memory of the queue to the given parameter
				queue.capacity = capacity;		//defines the capacity of queue to given param
				queue.rear = queue.queue[0];	//sets rear to adress 0 of the queue array
				queue.front = queue.queue[0];	//sets front to adress 0 of the queue array
				queue.used = true;				// updates the used status
				return &queue;					// returns a pointer to the created queue
			}
		}
	}

	return NULL;
}

void Queue_destroy(Queue* queue)
{
	
	queue->memory = 0;	//sets memory to =
	queue->capacity = 0; //changes capacity to 0
	queue->rear = -1;	//sets rear and front back 
	queue->front = -1;
	queue->used = false;	//queue is not used anymore
	
}

bool Queue_enqueue(Queue* queue, int element) {		//element is enqueued into the queue that is pointed on
		
		int i = queue->capacity;		//int i gets the value of capacity
		int j = queue->rear + 1;		// j gets the value of rear+1, so it is the variable used to enque
	
		if(Queue_isFull)				// if function Queue_isFull returns true, Queue_enqueue isn´t able to enqueue and returns false
			return false;
	
		if (Queue_isEmpty) {			// if the queue is empty rear and front are set to -1
			queue->rear = queue->front = 0; //to enqueue the element at the beginning rear and front have to be set to 0
			queue->queue[0] = element;		// element is written into the queue array at the place
		}

		else {								//queue is not empty and not full 
			int rear = j % i;				// rear is set to j%i to have a circular buffer
			queue->queue[rear] = element;	// element is written into the place of rear in the queue array
			queue->rear = rear;				// queue-> rear is updated with the new value
			
		}
		
		return true;						// returns true if the enqueue process was sucessful
}

bool Queue_dequeue(Queue* queue, int* element) // dequeues an element out of the queue
{
	int i = queue->front +1;					// i is set to front+1, it is the next higher value of the pointer
	int j = queue->capacity;					// j equals the capacity of the queue
	
	if(Queue_isEmpty)
	{	
		return false;							//you cant`t the queue anything if the queue is empty
	}

	else if (queue->front == queue->rear)		// if front and rear are the same there is a only one value
	{
		queue->front = -1;						//front is set back to a neutral position
		queue->rear = -1;						// rear is set back to a neutral position
		return true;							// success 
	}
	else
	{											// rear and front aren´t equal
		int front = i % j;						// int front equals the result of queue.front+1 modulo queue->rear
		queue->front = front;					// update of queue->front in the struct with the new value
		return true;							// success
		
	}
	
}



bool Queue_isEmpty(Queue* queue)				// checks if the queue is empty= there are no elements
{
	
	int front = queue->front;				
	int rear = queue->rear;
	if (front && rear == -1) {					// the queue is empty when both values are -1 

		return true;
	}
	else
		return false;
}
bool Queue_isFull(Queue* queue)				//checks if the queue is full

{
	int rear = queue->rear++;				//rear is the incremented value
	int capacity = queue->capacity;			//number of eleménts that can be stored
	int front = queue->front;				//value of the front pointer 
	if (rear % capacity == front)			// is full whean rear % capacity the same is as front
	{
		return true;
	}
	else
		return false;
}

size_t Queue_capacity(Queue* queue) {	//returns the maximum storage that could be used
	
	return sizeof(queue->queue);

}

size_t Queue_length(Queue* queue) {		//returns the number of values of the current queue
	int i;
	int front = queue->front;			
	int rear = queue->rear;
	int capacity = queue->capacity;
	if (Queue_isEmpty)					// if the queue is empty the length is 0
	{
		return 0;

	}
	else if (Queue_isFull)				// if the queue is full return the capacity
		return capacity;
		
	else if (queue->rear == queue->front)	//if rear and front are equal there is a length of 1
		return 1;
	else if(queue->rear < queue->front)		// if rear < than front you need to calculate the length
	{
		i = capacity - front;				// max. capacity minus the place of the front pointer
		i = i + 1 + rear;						// add the place of rear plus an additional value for 0
		return i;
	}
	else
	{
		i = rear +1 - front;		//if rear is bigger than front do this calculation
		return i;
	}
}
