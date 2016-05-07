/**
 *
 *  ADT: Stack
 *  Declaration
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

typedef adt_list                        adt_stack;

#define adt_stack_top(stack)            stack->back_->element_

#define adt_stack_empty(stack)          (adt_stack_boolean_type)(stack->front_ == NULL)
#define adt_stack_size(stack)           stack->size_

#define adt_stack_push(stack, element)  adt_list_push_back(stack, element)
#define adt_stack_pop(stack)            adt_list_pop_back(stack)

#define adt_stack_create()              adt_list_create()
#define adt_stack_destroy(stack)        adt_list_destroy(stack)

#ifdef __cplusplus
}
#endif

#endif /* ! ALGORITHM_ADT_STACK_H_ */
