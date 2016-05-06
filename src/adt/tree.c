/**
 *  ADT: Tree
 *  Definition
 *
 *  http://github.com/kdzlvaids/algorithm
 */

#include <stdlib.h>
#include "pair.h"
#include "tree.h"

#define  ADT_QUEUE_VALUE_TYPE   adt_pair*
#include "queue.h"

___type
___create(const ___compare_func compare)
{
    ___type tree = (___type)malloc(sizeof(___type));
    tree->size_ = 0;
    tree->root_ = NULL;
    tree->compare_ = compare;
}

void
___destroy(___type tree)
{
}

___boolean_type
___empty(___type tree)
{ return (___boolean_type)(tree->root_ == NULL); }

___size_type
___size(___type tree)
{ return (___size_type)tree->size_; }

___pair_type
___find(___type tree, const ___key_type key)
{
    if(! ___empty(tree))
    {
        ___pointer n = tree->root_;
        while(n != NULL)
        {
            if(compare_(key, n->element_->first) == 0)
                return n->element_;

            if(compare_(key, n->element_->first) < 0)
                n = n->left_;
            else
                n = n->right_;
        }
    }

    return NULL;
}

void
___insert(___type tree, const ___pair_type pair)
{
    ___pointer node = (___pointer)malloc(sizeof(___node_type));
    node->element_ = pair;
    node->left_ = NULL;
    node->right_ = NULL;
    node->parent_ = NULL;


    if(___empty(tree))
        tree->root_ = node;
    else
    {
        ___pointer n = tree->root_;
        ___pointer p = NULL;
        while(n != NULL)
        {
            p = n;

            if(compare_(pair->first, n->element_->first) < 0)
                n = n->left_;
            else
                n = n->right_;
        }

        node->parent_ = p;
        if(compare_(pair->first, p->element_->first) < 0)
            p->left_ = node;
        else
            p->right_ = node;
    }

    ++tree->size_;
}

void
___erase(___type tree, const ___key_type key)
{
    if(! ___empty(tree))
    {
        ___pointer n = tree->root_;
        while(n != NULL)
        {
            if(compare_(key, n->element_->first) == 0)
            {
                if(n->left_ != NULL && n->right_ != NULL)
                {
                    ___pointer p = ___node_successor(tree, n);
                    ___element_swap(n, p);
                    n = p;
                }

                if(n->left_ != NULL)
                {
                    if(n == tree->root_)
                        tree->root_ = n->left_;
                    else if(n->parent_->left_ == n)
                        n->parent_->left_ = n->left_;
                    else
                        n->parent_->right_ = n->left_;
                }
                else if(n->right_ != NULL)
                {
                    if(n == tree->root_)
                        tree->root_ = n->right_;
                    else if(n->parent_->left_ == n)
                        n->parent_->left_ = n->right_;
                    else
                        n->parent_->right_ = n->right_;
                }
                else if(n == tree->root_)
                    tree->root_ = NULL;

                --tree->size_;
                free(n);
            }

            if(compare_(key, n->element_->first) < 0)
                n = n->left_;
            else
                n = n->right_;
        }
    }
}

___pointer
___node_predecessor(___type tree, const ___pointer node)
{
    ___pointer n = node;

    if(n != NULL)
    {
        if(n->left_ != NULL)
        {
            n = n->left_;
            while(n->right_ != NULL)
                n = n->right_;
        }
        else
        {
            while(n->parent_ != NULL)
            {
                if(n == n->parent_->left_)
                {
                    n = n->parent_;
                    break;
                }

                n = n->parent_;
            }
        }
    }

    return n;
}

___pointer
___node_successor(___type tree, const ___pointer node)
{
    ___pointer n = node;

    if(n != NULL)
    {
        if(n->right_ != NULL)
        {
            n = n->right_;
            while(n->left_ != NULL)
                n = n->left_;
        }
        else
        {
            while(n->parent_ != NULL)
            {
                if(n == n->parent_->right_)
                {
                    n = n->parent_;
                    break;
                }

                n = n->parent_;
            }
        }
    }

    return n;
}

void
___element_swap(___pointer first, ___pointer second)
{
    ___pair_type temp = first->element_;
    first->element_ = second->element_;
    second->element_ = temp;
}

void
___traverse_levelorder(___type tree, void (* do_something)(___pair_type))
{
    if(! ___empty(tree))
    {
        ___pointer node = tree->root_;

        adt_queue queue_pair = adt_queue_create();
        adt_queue_push(queue_pair, node->element_);

        while(adt_queue_size(queue_pair) > 0)
        {
            ___pair_type pair = adt_queue_peek_pop(queue_pair);
            do_something(pair);

            if(node->left_ != NULL) adt_queue_push(queue_pair, node->left_->element_);
            if(node->right_ != NULL) adt_queue_push(queue_pair, node->right_->element_);
        }
    }
}

void
___traverse_inorder(___type tree, void (* do_something)(___pair_type))
{
    if(! ___empty(tree))
        ___traverse_inorder_using_node(tree->root_, do_something);
}

void
___traverse_preorder(___type tree, void (* do_something)(___pair_type))
{
    if(! ___empty(tree))
        ___traverse_preorder_using_node(tree->root_, do_something);
}

void
___traverse_postorder(___type tree, void (* do_something)(___pair_type))
{
    if(! ___empty(tree))
        ___traverse_postorder_using_node(tree->root_, do_something);
}

void
___traverse_inorder_using_node(___pointer node, void (* do_something)(___pair_type))
{
    if(node == NULL) return;

    ___traverse_preorder_using_node(node->left_, do_something);
    do_something(node->element_);
    ___traverse_preorder_using_node(node->right_, do_something);
}

void
___traverse_preorder_using_node(___pointer node, void (* do_something)(___pair_type))
{
    if(node == NULL) return;

    do_something(node->element_);
    ___traverse_preorder_using_node(node->left_, do_something);
    ___traverse_preorder_using_node(node->right_, do_something);
}

void
___traverse_postorder_using_node(___pointer node, void (* do_something)(___pair_type))
{
    if(node == NULL) return;

    ___traverse_preorder_using_node(node->left_, do_something);
    ___traverse_preorder_using_node(node->right_, do_something);
    do_something(node->element_);
}
