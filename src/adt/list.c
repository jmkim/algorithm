/**
 *
 *  ADT: Doubly linked list
 *  Definition
 *
 *  http://github.com/kdzlvaids/algorithm
 *
 */

#include <stdlib.h>
#include "list.h"

adt_list
adt_list_create(void)
{
    adt_list list   = (adt_list)malloc(sizeof(struct adt_list_adt_list));
    list->size_     = 0;
    list->front_    = NULL;
    list->back_     = NULL;

    return list;
}

void
adt_list_destroy(adt_list list)
{
    adt_list_clear(list);
    free(list);
}

void
adt_list_clear(adt_list list)
{
    adt_list_pointer n = list->back_;
    adt_list_pointer p = NULL;
    while(n != NULL)
    {
        p = n->next_;
        free(n);
        n = p;
    }

    list->size_ = 0;
    list->front_ = NULL;
    list->back_ = NULL;
}

void
adt_list_insert(adt_list list, const adt_list_pos_type pos, const adt_list_value_type element)
{
    adt_list_pointer posnode = list->front_;

    adt_list_pos_type p;
    for(p = 0; p < pos; ++p)
        posnode = posnode->prev_; /* Throw segfault if pos is greater than the size of list */

    adt_list_pointer newnode = (adt_list_pointer)malloc(sizeof(adt_list_node_type));
    newnode->element_ = element;

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
adt_list_erase(adt_list list, const adt_list_pos_type pos)
{
    adt_list_pointer posnode = list->front_;

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

    free(posnode);
}
