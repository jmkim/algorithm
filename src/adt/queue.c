/**
 *  ADT: Queue
 *  Definition
 *
 *  http://github.com/kdzlvaids/algorithm
 */

#include <stdlib.h>
#include "queue.h"

adt_queue
adt_queue_create(void)
{
    adt_queue queue = (adt_queue)malloc(sizeof(adt_queue));
    queue->size_ = 0;
    queue->front_ = NULL;
    queue->back_ = NULL;
}

void
adt_queue_destroy(adt_queue queue)
{
    adt_queue_pointer n = queue->back_;
    adt_queue_pointer p = NULL;
    while(n != NULL)
    {
        p = n->next;
        free(n);
        n = p;
    }

    free(queue);
}

adt_queue_boolean_type
adt_queue_empty(adt_queue queue)
{ return (adt_queue_boolean_type)(queue->front_ == NULL); }

adt_queue_size_type
adt_queue_size(adt_queue queue)
{ return (adt_queue_size_type)queue->size_; }

adt_queue_value_type
adt_queue_peek(adt_queue queue)
{ return queue->back_->element_; }

void
adt_queue_push(adt_queue queue, adt_queue_value_type element)
{
    adt_queue_pointer node = (adt_queue_pointer)malloc(sizeof(adt_queue_node_type));
    node->element_ = element;

    if(adt_queue_empty(queue))
        queue->front_ = node;
    else
        queue->back_->next = node;
    queue->back_ = node;
    ++queue->size_;
}

void
adt_queue_pop(adt_queue queue)
{
    if(! adt_queue_empty(queue))
    {
        adt_queue_pointer node = queue->front_;
        queue->front_ = node->next_;
        if(adt_queue_empty(queue))
            queue->back_ = NULL;
        --queue->size_;

        free(node);
    }
}

adt_queue_value_type
adt_queue_peek_pop(adt_queue queue)
{
    adt_queue_value_type value = adt_queue_peek(queue);
    adt_queue_pop(queue);
    return value;
}
