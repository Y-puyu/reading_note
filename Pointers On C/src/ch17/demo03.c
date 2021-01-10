/*
** A queue implemented with a dynamically allocated array. The array size is
** given when create is called, which must happen before any other queue
** operations are attempted.
*/
#include "../supporting_src/ch17/queue.h"
#include <stdio.h>
#include <assert.h>
/*
** 
The array that holds the values on the queue, its size, and pointers to
** 
the front and rear of the queue.
*/
static QUEUE_TYPE
    *queue;
static size_t
    queue_size;
static size_t
    front = 1;
static size_t
    rear = 0;
/*
** 
create_queue
*/
void create_queue(size_t size)
{
    assert(queue_size == 0);
    queue_size = size;
    queue = (QUEUE_TYPE *)malloc(queue_size * sizeof(QUEUE_TYPE));
    assert(queue != NULL);
}
/*
** 
destroy_queue
*/
void destroy_queue(void)
{
    assert(queue_size > 0);
    queue_size = 0;
    free(queue);
    queue = NULL;
}
/*
** 
resize_queue
*/
void resize_queue(size_t new_size)
{
    QUEUE_TYPE
    *old_queue;
    int
        i;
    int
        rear_plus_one;
    /*
** Make sure the new size is large enough to hold the data already on
** the queue. Then save the pointer to the old array and create a new
** one of the right size.
*/
    if (front <= rear)
        i = rear - front + 1;
    else
        i = queue_size - front + rear + 1;
    i %= queue_size;
    assert(new_size >= i);
    old_queue = queue;
    queue = (QUEUE_TYPE *)malloc(new_size * sizeof(QUEUE_TYPE));
    assert(queue != NULL);
    queue_size = new_size;
    /*
** Copy values from the old array to the new one and then free the old
** memory.
*/
    i = 0;
    rear_plus_one = (rear + 1) % queue_size;
    while (front != rear_plus_one)
    {
        queue[i] = old_queue[front];
        front = (front + 1) % queue_size;
        i += 1;
    }
    front = 0;
    rear = (i + queue_size - 1) % queue_size;
    free(old_queue);
}
/*
** 
insert
*/
void insert(QUEUE_TYPE value)
{
    assert(!is_full());
    rear = (rear + 1) % queue_size;
    queue[rear] = value;
}
/*
** 
delete
*/
void delete (void)
{
    assert(!is_empty());
    front = (front + 1) % queue_size;
}
/*
** 
first
*/
QUEUE_TYPE first(void)
{
    assert(!is_empty());
    return queue[front];
}
/*
** 
is_empty
*/
int is_empty(void)
{
    assert(queue_size > 0);
    return (rear + 1) % queue_size == front;
}
/*
** 
is_full
*/
int is_full(void)
{
    assert(queue_size > 0);
    return (rear + 2) % queue_size == front;
}