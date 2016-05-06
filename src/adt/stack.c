/**
 *  ADT: Stack
 *  Definition
 *
 *  http://github.com/kdzlvaids/algorithm
 */

#include <stdlib.h>
#include "stack.h"

___type
___create(void)
{
    ___type stack = (___type)malloc(sizeof(___type));
    stack->size_ = 0;
    stack->top_ = NULL;
}

void
___destroy(___type stack)
{
    ___pointer n = stack->top_;
    ___pointer p = NULL;
    while(n != NULL)
    {
        p = n->next;
        free(n);
        n = p;
    }

    free(stack);
}

___boolean_type
___empty(___type stack)
{ return (___boolean_type)(stack->top_ == NULL); }

___size_type
___size(___type stack)
{ return (___size_type)stack->size_; }

___value_type
___peek(___type stack)
{ return stack->top_->element_; }

void
___push(___type stack, ___value_type element)
{
    ___pointer node = (___pointer)malloc(sizeof(___node_type));
    node->element_ = element;

    node->next_ = stack->top_;
    stack->top_ = node;
    ++stack->size_;
}

void
___pop(___type stack)
{
    if(! ___empty(stack))
    {
        ___pointer node = stack->top_;
        stack->top_ = node->next_;
        --stack->size_;

        free(node);
    }
}

___value_type
___peek_pop(___type stack)
{
    ___value_type value = ___peek(stack);
    ___pop(stack);
    return value;
}
