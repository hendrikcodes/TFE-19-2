#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 6

struct Queue
{
    int* memory;
    int front;
    int back;
    size_t capacity;
    size_t length;
    bool used;
};

Queue* Pool[MAX];                          //creating a pool of queue array with MAX places

Queue* Queue_create(int* memory, size_t capacity)
{
                       
    if (memory != NULL)                            //test if memory is not empty and pointing nowhere
    {
        for (int i = 0; i <= MAX; i++)
        {
            if (*memory = NULL)                    //test if queue is availabe for use
            {
                Pool[i]->memory = memory;
                Pool[i]->capacity = capacity;
                Pool[i]->back = Pool[i]->front = -1;
                Pool[i]->length = 0;
                Pool[i]->used = true;
                return &Pool[i];
            }
        };
    }
    else {
        return NULL;
    }
}

void Queue_destroy(Queue* queue)
{
    if (queue != NULL) {
        queue->memory = NULL;
        queue->back = queue->front = -1;
        queue->capacity = 0;
        queue->length = 0;
    }
}

bool Queue_enqueue(Queue* queue, int element)
{
    if (queue != NULL) {
        if (Queue_isEmpty(queue)) {
            queue->back = queue->front = 0;
            queue->memory[queue->back] = element;
            queue->back = (queue->back + 1) % queue->capacity;
            queue->length++;
            return true;
        }
        else if (Queue_isFull(queue)) {
            return false;
        }
        else {
            queue->memory[queue->back] = element;
            queue->back = (queue->back + 1) % queue->capacity;
            queue->length++;
            return true;
        }
    }
    else {
        return false;
    }
}
bool Queue_dequeue(Queue* queue, int* element)
{
    if (queue != NULL) {
        if (Queue_isEmpty(queue)) {
            return false;
        }
        else if (queue->front == queue->back) {
            *element = queue->memory[queue->front];
            queue->back = queue->front = -1;
            queue->length = 0;
            return true;
        }
        else
        {
            *element = queue->memory[queue->front];
            queue->front = (queue->front + 1) % queue->capacity;
            queue->length--;
            return true;
        }

    }
    else {
        return false;
    }
}

void Queue_clear(Queue* queue)
{
    if (queue != NULL) {
        queue->front = queue->back = -1;
        queue->length = 0;
    }
    else {
        return;
    }
}

bool Queue_isFull(Queue* queue)
{
    if (queue != NULL)
    {
        if ((queue->back + 1) % queue->capacity == queue->front) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
bool Queue_isEmpty(Queue* queue)
{
    if (queue != NULL) {
        if (queue->front == -1 && queue->back == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

size_t Queue_capacity(Queue* queue)
{
    if (queue != NULL) {
        return queue->capacity;
    }
    else return NULL;
}

size_t Queue_length(Queue* queue)
{
    if (queue != NULL) {
        if (Queue_isEmpty) {
            return 0;
        }
        else {
            return queue->length;
        }
    }
    else return NULL;
}

bool Queue_peek(Queue* queue, int* element)
{
    if (queue != NULL) {
        if (Queue_isEmpty(queue)) {
            return false;
        }
        else
        {
            *element = queue->memory[queue->front];
            return true;
        }
    }
    else return false;
}

