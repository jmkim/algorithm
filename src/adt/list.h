/**
 *
 *  ADT: Doubly linked list
 *  Declaration
 *
 *  http://github.com/kdzlvaids/algorithm
 *
 */

#ifndef ALGORITHM_ADT_LIST_H_
#define ALGORITHM_ADT_LIST_H_ 1

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef ADT_LIST_VALUE_TYPE
#define ADT_LIST_VALUE_TYPE     void*
#endif

typedef ADT_LIST_VALUE_TYPE     adt_list_value_type;

typedef size_t                  adt_list_size_type;
typedef int                     adt_list_boolean_type;
#ifndef FALSE
#   define FALSE    0
#endif
#ifndef TRUE
#   define TRUE     1
#endif

struct adt_list_node
{
            adt_list_value_type         element_;
    struct  adt_list_node*              prev_;
    struct  adt_list_node*              next_;
};

typedef struct  adt_list_node           adt_list_node_type;
typedef         adt_list_node_type*     adt_list_pointer;
typedef const   adt_list_node_type*     adt_list_const_pointer;
typedef int     adt_list_pos_type;

struct adt_list_adt_list
{
    adt_list_size_type      size_;
    adt_list_pointer        front_;
    adt_list_pointer        back_;
};

typedef struct  adt_list_adt_list       adt_list;

#define adt_list_front(list)            list->front_->element_
#define adt_list_back(list)             list->back_->element_

#define adt_list_empty(list)            (adt_list_boolean_type)(list->front_ == NULL)
#define adt_list_size(list)             list->size_

#define adt_list_push_front(list, element)  adt_list_insert(list, 0, element)
#define adt_list_pop_front(list)            adt_list_erase(list, 0)
#define adt_list_push_back(list, element)   adt_list_insert(list, list->size_, element)
#define adt_list_pop_back(list)             adt_list_erase(list, list->size_ - 1)

adt_list*
adt_list_create(void);

void
adt_list_destroy(adt_list* list);

void
adt_list_clear(adt_list* list);

void
adt_list_insert(adt_list* list, const adt_list_pos_type pos, const adt_list_value_type element);

void
adt_list_erase(adt_list* list, const adt_list_pos_type pos);

void
adt_list_traverse(adt_list* list, void (* do_something)(adt_list_value_type));

void
adt_list_traverse_reverse(adt_list* list, void (* do_something)(adt_list_value_type));

#ifdef __cplusplus
}
#endif

#endif /* ! ALGORITHM_ADT_LIST_H_ */
