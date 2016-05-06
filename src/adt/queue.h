/**
 *  ADT: Queue
 *  Implementation
 *
 *  http://github.com/kdzlvaids/algorithm
 */

#ifndef ALGORITHM_ADT_QUEUE_H_
#define ALGORITHM_ADT_QUEUE_H_ 1

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef ADT_QUEUE_VALUE_TYPE
#define ADT_QUEUE_VALUE_TYPE   void*
#endif

typedef ADT_QUEUE_VALUE_TYPE    ___value_type;

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
            ___value_type        element_;
    struct  ___node*             next_;
};

typedef struct  ___node          ___node_type;
typedef         ___node_type*    ___pointer;
typedef const   ___node_type*    ___const_pointer;

struct adt_queue
{
    ___size_type     size_;
    ___pointer       front_;
    ___pointer       back_;
};

typedef struct  adt_queue*  ___type;

___type
___create(void);

void
___destroy(___type queue);

___boolean_type
___empty(___type queue);

___size_type
___size(___type queue);

___value_type
___peek(___type queue);

void
___push(___type queue, ___value_type element);

void
___pop(___type queue);

___value_type
___peek_pop(___type queue);

#ifdef __cplusplus
}
#endif

#endif /* ! ALGORITHM_ADT_QUEUE_H_ */
