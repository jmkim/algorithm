/**
 *  ADT: Stack
 *  Implementation
 *
 *  http://github.com/kdzlvaids/algorithm
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

typedef ADT_STACK_VALUE_TYPE    ___value_type;

typedef size_t                  ___size_type;
typedef int                     ___boolean_type;
#ifndef FALSE
#   define FALSE    0
#endif
#ifndef TRUE
#   define TRUE     1
#endif

struct ___node
{
            ___value_type        element;
    struct  ___node*             next;
};

typedef struct  ___node          ___node_type;
typedef         ___node_type*    ___pointer;
typedef const   ___node_type*    ___const_pointer;

struct adt_stack
{
    ___size_type     size;
    ___pointer       top;
};

typedef struct  adt_stack*  ___type;

___type
___create(void);

void
___destroy(___type stack);

___boolean_type
___is_empty(___type stack);

___boolean_type
___is_empty(___type stack);

___size_type
___get_size(___type stack);

___value_type
___peek(___type stack);

void
___push(___type stack, ___value_type element);

void
___pop(___type stack);

___value_type
___peek_pop(___type stack);

#ifdef __cplusplus
}
#endif

#endif /* ! ALGORITHM_ADT_STACK_H_ */
