/**
 *
 *  ADT: Doubly linked list
 *  Definition
 *
 *  http://github.com/kdzlvaids/algorithm
 *
 */

#include <stdlib.h>
#include <string.h>
#include "list.h"

adt_list*
adt_list_create(const adt_list_size_type value_size)
{
    adt_list temp =
    {
        .size_          = 0,
        .front_         = NULL,
        .back_          = NULL,

        .value_size_    = value_size,

        .allocate_      = malloc,   /**< in stdlib.h */
        .deallocate_    = free,     /**< in stdlib.h */
        .memcopy_       = (adt_list_memcopy_func)memcpy /**< in string.h */
    };

    adt_list* list  = (adt_list*)temp.allocate_(sizeof(struct adt_list_adt_list));
    temp.memcopy_(list, &temp, sizeof(struct adt_list_adt_list));

    return list;
}

void
adt_list_destroy(adt_list* list)
{
    adt_list_clear(list);
    list->deallocate_(list);
}

void
adt_list_clear(adt_list* list)
{
    adt_list_node_type* n = list->back_;
    adt_list_node_type* p = NULL;

    while(n != NULL)
    {
        p = n->next_;

        list->deallocate_(n->element_);
        list->deallocate_(n);

        n = p;
    }

    list->size_     = 0;
    list->front_    = NULL;
    list->back_     = NULL;
}

void
adt_list_insert(adt_list* list, const adt_list_pos_type pos, const adt_list_value_type element)
{
    adt_list_node_type* posnode = list->front_;

    adt_list_pos_type p;
    for(p = 0; p < pos; ++p)
        posnode = posnode->prev_; /* Throw segfault if pos is greater than the size of list */

    adt_list_node_type* newnode = (adt_list_node_type*)list->allocate_(sizeof(adt_list_node_type));

    {
        /** Do deep copy of element */

        newnode->element_ = (adt_list_value_type*)list->allocate_(list->value_size_);
        list->memcopy_(newnode->element_, element, list->value_size_);
    }

    if(adt_list_empty(list))
    {
        list->front_    = newnode;
        list->back_     = newnode;
        newnode->prev_  = NULL;
        newnode->next_  = NULL;
    }
    else if(posnode == NULL) /* pos == size of list */
    {
        /* Insert newnode after the list->back_ (insert_after) */

        newnode->prev_      = list->back_->prev_; /* NULL */
        list->back_->prev_  = newnode;

        newnode->next_      = list->back_;
        list->back_         = newnode;
    }
    else
    {
        /* Insert newnode before posnode */

        if(posnode == list->front_)
            list->front_            = newnode;
        else
            posnode->next_->prev_   = newnode;

        newnode->next_      = posnode->next_;
        posnode->next_      = newnode;
        newnode->prev_      = posnode;
    }

    ++list->size_;
}

void
adt_list_erase(adt_list* list, const adt_list_pos_type pos)
{
    adt_list_node_type* posnode = list->front_;

    adt_list_pos_type p;
    for(p = 0; p < pos; ++p)
        posnode = posnode->prev_; /* Throw segfault if pos is greater than the size of list */

    {
        /* Throw segfault if pos is greater than (size of list - 1) */

        if(posnode == list->front_)
            list->front_            = posnode->prev_;
        else
            posnode->next_->prev_   = posnode->prev_;

        if(posnode == list->back_)
            list->back_             = posnode->next_;
        else
            posnode->prev_->next_   = posnode->next_;

        --list->size_;
    }

    list->deallocate_(posnode->element_);
    list->deallocate_(posnode);
}

void
adt_list_traverse(adt_list* list, void (* do_something)(adt_list_value_type))
{
    adt_list_node_type* n = list->front_;
    while(n != NULL)
    {
        do_something(n->element_);
        n = n->prev_;
    }
}

void
adt_list_traverse_reverse(adt_list* list, void (* do_something)(adt_list_value_type))
{
    adt_list_node_type* n = list->back_;
    while(n != NULL)
    {
        do_something(n->element_);
        n = n->next_;
    }
}
