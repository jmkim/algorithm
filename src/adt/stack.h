/**
 *
 *  ADT: Stack
 *  Declaration
 *
 *  Required: list.h
 *
 *  http://github.com/kdzlvaids/algorithm
 *
 */

#ifndef ALGORITHM_ADT_STACK_H_
#define ALGORITHM_ADT_STACK_H_ 1

#include "list.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef adt_list    adt_stack;
typedef int         adt_stack_boolean_type;

#define adt_stack_top(stack)            stack->back_->element_

#define adt_stack_empty(stack)          (adt_stack_boolean_type)(stack->front_ == NULL)
#define adt_stack_size(stack)           stack->size_

#define adt_stack_push(stack, element)  adt_list_push_back(stack, element)
#define adt_stack_pop(stack)            adt_list_pop_back(stack)

#define adt_stack_create(element_size)  adt_list_create(element_size)
#define adt_stack_destroy(stack)        adt_list_destroy(stack)

#define adt_stack_traverse(stack, callback)             adt_list_traverse(stack, callback)
#define adt_stack_traverse_reverse(stack, callback)     adt_list_traverse_reverse(stack, callback)

#ifdef __cplusplus
}
#endif

#endif /* ! ALGORITHM_ADT_STACK_H_ */
