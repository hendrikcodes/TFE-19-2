#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue Queue;

Queue* Queue_create(int* memory, size_t capacity); 
void Queue_destroy(Queue* queue);

bool Queue_enqueue(Queue* queue, int element); 
bool Queue_dequeue(Queue* queue, int* element);

void Queue_clear(Queue* queue);

bool Queue_isFull(Queue* queue);
bool Queue_isEmpty(Queue* queue);

size_t Queue_capacity(Queue* queue);
size_t Queue_length(Queue* queue);

#endif /* QUEUE_H */
