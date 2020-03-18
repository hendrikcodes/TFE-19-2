#include <stdbool.h>
#include <stdlib.h>
#include "Header.h"
#include <stdio.h>
#include <assert.h>
#define N 6

typedef struct Queue{
           int* memory[100];
           size_t capacity;
           int i;
           bool used;
           int* rear;
           int* front;
}Queue;

 ueue queue_pool[10];

Queue* Queue_create(int* memory, size_t capacity)
{
        
           for (int i = 0; i < 10; i++)
           {
                     Queue queue = queue_pool[i];
                     if (queue_pool[i].used == false)
                     {    
                     queue.memory = memory;
                     queue.capacity = capacity;
                     queue.rear = memory;
                     queue.front = memory;
                     queue.used = true;
                     return &queue;
                     }
           }
           return NULL;
}

void Queue_destroy(Queue* queue)
{
           queue->memory = 0;
           queue->capacity = 0;
           queue->used = false;
}

 

bool Queue_enqueue(Queue* queue, int element) {
           if (queue->rear % queue->capacity == queue->front) 
               {
               return false;
               }

           else if (Queue_isEmpty) 
                  {
                  queue->rear = queue->front = 0;
                  return true;
                  }

 

            else 
                  {
                  queue->rear = queue->rear++ % queue->capacity;
                  return true;
                  }
                  queue->memory[queue->rear] = element;

}


bool Queue_isEmpty(Queue* queue)

{

          

           int front = queue->front;
           int rear = queue->rear;
           if (queue->front && queue->rear == -1) {

                     return true;

           }
}

/*

size_t Queue_capacity(Queue* queue) {
           return sizeof(queue->memory);

 

}

 

size_t Queue_length(Queue* queue) {

           int length;
           if (queue->front < queue->rear) {
                     length = queue->rear - queue->front + 1;
                     return length;

           }

           else if (Queue_isEmpty)
                     return length = 0;
           else if (queue->front == queue->rear && queue->rear != -1)
                     return length = 1;

 

 

 

           else if (queue->front > queue->rear) {
                     length = queue->front - queue->rear + 1;
                     return length = queue->front - queue->rear + 1;

           }

}

*/

