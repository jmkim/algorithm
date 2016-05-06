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

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef ADT_STACK_VALUE_TYPE
#define ADT_STACK_VALUE_TYPE   void*
#endif

typedef ADT_STACK_VALUE_TYPE    adt_stack_value_type;

typedef size_t                  adt_stack_size_type;
typedef int                     adt_stack_boolean_type;
#ifndef FALSE
#   define FALSE    0
#endif
#ifndef TRUE
#   define TRUE     1
#endif

struct adt_stack_node
{
            adt_stack_value_type        element_;
    struct  adt_stack_node*             next_;
};

typedef struct  adt_stack_node          adt_stack_node_type;
typedef         adt_stack_node_type*    adt_stack_pointer;
typedef const   adt_stack_node_type*    adt_stack_const_pointer;

struct adt_stack_adt_stack
{
    adt_stack_size_type     size_;
    adt_stack_pointer       top_;
};

typedef struct  adt_stack_adt_stack*  adt_stack;

adt_stack
adt_stack_create(void);

void
adt_stack_destroy(adt_stack stack);

adt_stack_boolean_type
adt_stack_empty(adt_stack stack);

adt_stack_size_type
adt_stack_size(adt_stack stack);

adt_stack_value_type
adt_stack_peek(adt_stack stack);

void
adt_stack_push(adt_stack stack, adt_stack_value_type element);

void
adt_stack_pop(adt_stack stack);

adt_stack_value_type
adt_stack_peek_pop(adt_stack stack);

#ifdef __cplusplus
}
#endif

#endif /* ! ALGORITHM_ADT_STACK_H_ */
