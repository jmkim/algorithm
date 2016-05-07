/**
 *
 *  ADT: Queue
 *  Declaration
 *
 *  Required: list.h
 *
 *  http://github.com/kdzlvaids/algorithm
 *
 */

#ifndef ALGORITHM_ADT_QUEUE_H_
#define ALGORITHM_ADT_QUEUE_H_ 1

#include "list.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef adt_list    adt_queue;
typedef int         adt_queue_boolean_type;

#define adt_queue_front(queue)          queue->front_->element_
#define adt_queue_back(queue)           queue->back_->element_

#define adt_queue_empty(queue)          (adt_queue_boolean_type)(queue->front_ == NULL)
#define adt_queue_size(queue)           queue->size_

#define adt_queue_push(queue, element)  adt_list_push_back(queue, element)
#define adt_queue_pop(queue)            adt_list_pop_front(queue)

#define adt_queue_create()              adt_list_create()
#define adt_queue_destroy(queue)        adt_list_destroy(queue)

#define adt_queue_traverse(queue)       adt_list_traverse(queue)
#define adt_queue_traverse_reverse(queue)       adt_list_traverse_reverse(queue)

#ifdef __cplusplus
}
#endif

#endif /* ! ALGORITHM_ADT_QUEUE_H_ */
