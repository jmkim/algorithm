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

typedef ADT_QUEUE_VALUE_TYPE    adt_queue_value_type;

typedef size_t                  adt_queue_size_type;
typedef int                     adt_queue_boolean_type;
#ifndef FALSE
#   define FALSE    0
#endif
#ifndef TRUE
#   define TRUE     1
#endif

struct adt_queue_node
{
            adt_queue_value_type        element_;
    struct  adt_queue_node*             next_;
};

typedef struct  adt_queue_node          adt_queue_node_type;
typedef         adt_queue_node_type*    adt_queue_pointer;
typedef const   adt_queue_node_type*    adt_queue_const_pointer;

struct adt_queue_adt_queue
{
    adt_queue_size_type     size_;
    adt_queue_pointer       front_;
    adt_queue_pointer       back_;
};

typedef struct  adt_queue_adt_queue*  adt_queue;

adt_queue
adt_queue_create(void);

void
adt_queue_destroy(adt_queue queue);

adt_queue_boolean_type
adt_queue_empty(adt_queue queue);

adt_queue_size_type
adt_queue_size(adt_queue queue);

adt_queue_value_type
adt_queue_peek(adt_queue queue);

void
adt_queue_push(adt_queue queue, adt_queue_value_type element);

void
adt_queue_pop(adt_queue queue);

adt_queue_value_type
adt_queue_peek_pop(adt_queue queue);

#ifdef __cplusplus
}
#endif

#endif /* ! ALGORITHM_ADT_QUEUE_H_ */
