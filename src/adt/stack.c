/**
 *  ADT: Stack
 *  Definition
 *
 *  http://github.com/kdzlvaids/algorithm
 */

#include <stdlib.h>
#include "stack.h"

adt_stack
adt_stack_create(void)
{
    adt_stack stack = (adt_stack)malloc(sizeof(adt_stack));
    stack->size_ = 0;
    stack->top_ = NULL;
}

void
adt_stack_destroy(adt_stack stack)
{
    adt_stack_pointer n = stack->top_;
    adt_stack_pointer p = NULL;
    while(n != NULL)
    {
        p = n->next_;
        free(n);
        n = p;
    }

    free(stack);
}

adt_stack_boolean_type
adt_stack_empty(adt_stack stack)
{ return (adt_stack_boolean_type)(stack->top_ == NULL); }

adt_stack_size_type
adt_stack_size(adt_stack stack)
{ return (adt_stack_size_type)stack->size_; }

adt_stack_value_type
adt_stack_peek(adt_stack stack)
{ return stack->top_->element_; }

void
adt_stack_push(adt_stack stack, adt_stack_value_type element)
{
    adt_stack_pointer node = (adt_stack_pointer)malloc(sizeof(adt_stack_node_type));
    node->element_ = element;

    node->next_ = stack->top_;
    stack->top_ = node;
    ++stack->size_;
}

void
adt_stack_pop(adt_stack stack)
{
    if(! adt_stack_empty(stack))
    {
        adt_stack_pointer node = stack->top_;
        stack->top_ = node->next_;
        --stack->size_;

        free(node);
    }
}

adt_stack_value_type
adt_stack_peek_pop(adt_stack stack)
{
    adt_stack_value_type value = adt_stack_peek(stack);
    adt_stack_pop(stack);
    return value;
}
