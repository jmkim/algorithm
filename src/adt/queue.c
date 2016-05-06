/**
 *  ADT: Queue
 *  Definition
 *
 *  http://github.com/kdzlvaids/algorithm
 */

#include <stdlib.h>
#include "queue.h"

___type
___create(void)
{
    ___type queue = (___type)malloc(sizeof(___type));
    queue->size_ = 0;
    queue->front_ = NULL;
    queue->back_ = NULL;
}

void
___destroy(___type queue)
{
    ___pointer n = queue->back_;
    ___pointer p = NULL;
    while(n != NULL)
    {
        p = n->next;
        free(n);
        n = p;
    }

    free(queue);
}

___boolean_type
___empty(___type queue)
{ return (___boolean_type)(queue->front_ == NULL); }

___size_type
___size(___type queue)
{ return (___size_type)queue->size_; }

___value_type
___peek(___type queue)
{ return queue->back_->element_; }

void
___push(___type queue, ___value_type element)
{
    ___pointer node = (___pointer)malloc(sizeof(___node_type));
    node->element_ = element;

    if(___empty(queue))
        queue->front_ = node;
    else
        queue->back_->next = node;
    queue->back_ = node;
    ++queue->size_;
}

void
___pop(___type queue)
{
    if(! ___empty(queue))
    {
        ___pointer node = queue->front_;
        queue->front_ = node->next_;
        if(___empty(queue))
            queue->back_ = NULL;
        --queue->size_;

        free(node);
    }
}

___value_type
___peek_pop(___type queue)
{
    ___value_type value = ___peek(queue);
    ___pop(queue);
    return value;
}
