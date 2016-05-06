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
    stack->size = 0;
    stack->top = NULL;
}

void
___destroy(___type stack)
{ free(stack); }

___boolean_type
___is_empty(___type stack)
{ return (___boolean_type)(stack->top == NULL); }

___size_type
___get_size(___type stack)
{ return (___size_type)stack->size; }

___value_type
___peek(___type stack)
{ return stack->top->element; }

void
___push(___type stack, ___value_type element)
{
    ___pointer node = (___pointer)malloc(sizeof(___node_type));
    node->element = element;

    node->next = stack->top;
    stack->top = node;
    ++stack->size;
}

void
___pop(___type stack)
{
    if(! ___is_empty(stack))
    {
        ___pointer node = stack->top;
        stack->top = node->next;
        --stack->size;

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
