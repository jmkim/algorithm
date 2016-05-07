/**
 *
 *  ADT: Tree
 *  Definition
 *
 *  http://github.com/kdzlvaids/algorithm
 *
 */

#include <stdlib.h>
#include "pair.h"
#include "tree.h"

#define  ADT_QUEUE_VALUE_TYPE   adt_pair*
#include "queue.h"

adt_tree*
adt_tree_create(const adt_tree_compare_func compare)
{
    adt_tree tree = (adt_tree)malloc(sizeof(struct adt_tree_adt_tree));
    tree->size_ = 0;
    tree->root_ = NULL;
    tree->compare_ = compare;
}

void
adt_tree_destroy(adt_tree* tree)
{
    if(! adt_tree_empty(tree))
        adt_tree_postorder_traverse_for_destroy(tree->root_);

    free(tree);
}

void
adt_tree_postorder_traverse_for_destroy(adt_tree_pointer node)
{
    if(node == NULL) return;

    adt_tree_postorder_traverse_for_destroy(node->left_);
    adt_tree_postorder_traverse_for_destroy(node->right_);
    free(node);
}

adt_tree_boolean_type
adt_tree_empty(adt_tree* tree)
{ return (adt_tree_boolean_type)(tree->root_ == NULL); }

adt_tree_size_type
adt_tree_size(adt_tree* tree)
{ return (adt_tree_size_type)tree->size_; }

adt_tree_pair_type
adt_tree_find(adt_tree* tree, const adt_tree_key_type key)
{
    if(! adt_tree_empty(tree))
    {
        adt_tree_pointer n = tree->root_;
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
adt_tree_insert(adt_tree* tree, const adt_tree_pair_type pair)
{
    adt_tree_pointer node = (adt_tree_pointer)malloc(sizeof(adt_tree_node_type));
    node->element_ = pair;
    node->left_ = NULL;
    node->right_ = NULL;
    node->parent_ = NULL;


    if(adt_tree_empty(tree))
        tree->root_ = node;
    else
    {
        adt_tree_pointer n = tree->root_;
        adt_tree_pointer p = NULL;
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
adt_tree_erase(adt_tree* tree, const adt_tree_key_type key)
{
    if(! adt_tree_empty(tree))
    {
        adt_tree_pointer n = tree->root_;
        while(n != NULL)
        {
            if(compare_(key, n->element_->first) == 0)
            {
                if(n->left_ != NULL && n->right_ != NULL)
                {
                    adt_tree_pointer p = adt_tree_node_successor(tree, n);
                    adt_tree_element_swap(n, p);
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

adt_tree_pointer
adt_tree_node_predecessor(adt_tree* tree, const adt_tree_pointer node)
{
    adt_tree_pointer n = node;

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

adt_tree_pointer
adt_tree_node_successor(adt_tree* tree, const adt_tree_pointer node)
{
    adt_tree_pointer n = node;

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
adt_tree_element_swap(adt_tree_pointer first, adt_tree_pointer second)
{
    adt_tree_pair_type temp = first->element_;
    first->element_ = second->element_;
    second->element_ = temp;
}

void
adt_tree_traverse_levelorder(adt_tree* tree, void (* do_something)(adt_tree_pair_type))
{
    if(! adt_tree_empty(tree))
    {
        adt_tree_pointer node = tree->root_;

        adt_queue queue_pair = adt_queue_create();
        adt_queue_push(queue_pair, node->element_);

        while(adt_queue_size(queue_pair) > 0)
        {
            adt_tree_pair_type pair = adt_queue_peek_pop(queue_pair);
            do_something(pair);

            if(node->left_ != NULL) adt_queue_push(queue_pair, node->left_->element_);
            if(node->right_ != NULL) adt_queue_push(queue_pair, node->right_->element_);
        }
    }
}

void
adt_tree_traverse_inorder(adt_tree* tree, void (* do_something)(adt_tree_pair_type))
{
    if(! adt_tree_empty(tree))
        adt_tree_traverse_inorder_using_node(tree->root_, do_something);
}

void
adt_tree_traverse_preorder(adt_tree* tree, void (* do_something)(adt_tree_pair_type))
{
    if(! adt_tree_empty(tree))
        adt_tree_traverse_preorder_using_node(tree->root_, do_something);
}

void
adt_tree_traverse_postorder(adt_tree* tree, void (* do_something)(adt_tree_pair_type))
{
    if(! adt_tree_empty(tree))
        adt_tree_traverse_postorder_using_node(tree->root_, do_something);
}

void
adt_tree_traverse_inorder_using_node(adt_tree_pointer node, void (* do_something)(adt_tree_pair_type))
{
    if(node == NULL) return;

    adt_tree_traverse_preorder_using_node(node->left_, do_something);
    do_something(node->element_);
    adt_tree_traverse_preorder_using_node(node->right_, do_something);
}

void
adt_tree_traverse_preorder_using_node(adt_tree_pointer node, void (* do_something)(adt_tree_pair_type))
{
    if(node == NULL) return;

    do_something(node->element_);
    adt_tree_traverse_preorder_using_node(node->left_, do_something);
    adt_tree_traverse_preorder_using_node(node->right_, do_something);
}

void
adt_tree_traverse_postorder_using_node(adt_tree_pointer node, void (* do_something)(adt_tree_pair_type))
{
    if(node == NULL) return;

    adt_tree_traverse_preorder_using_node(node->left_, do_something);
    adt_tree_traverse_preorder_using_node(node->right_, do_something);
    do_something(node->element_);
}
