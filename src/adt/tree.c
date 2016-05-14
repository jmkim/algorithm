/**
 *
 *  ADT: Tree
 *  Definition
 *
 *  http://github.com/kdzlvaids/algorithm
 *
 */

#include <stdlib.h>
#include <string.h>
#include "tree.h"

#define  ADT_QUEUE_VALUE_TYPE   adt_tree_pair_type
#include "queue.h"

adt_tree*
adt_tree_create(const adt_tree_size_type key_size, const adt_tree_size_type value_size, const adt_tree_compare_func compare)
{
    adt_tree temp =
    {
        .size_          = 0,
        .root_          = NULL,

        .key_size_      = key_size,
        .value_size_    = value_size,

        .compare_       = compare,
        .allocate_      = malloc,   /**< in stdlib.h */
        .deallocate_    = free,     /**< in stdlib.h */
        .memcopy_       = (adt_tree_memcopy_func)memcpy /**< in string.h */
    };

    adt_tree* tree  = (adt_tree*)temp.allocate_(sizeof(struct adt_tree_adt_tree));
    temp.memcopy_(tree, &temp, sizeof(struct adt_tree_adt_tree));

    return tree;
}

void
adt_tree_destroy(adt_tree* tree)
{
    adt_tree_clear(tree);

    tree->deallocate_(tree);
}

void
adt_tree_clear(adt_tree* tree)
{
    adt_tree_postorder_traverse_for_clear(tree->root_, tree->deallocate_);

    tree->size_     = 0;
    tree->root_     = NULL;
}

void
adt_tree_postorder_traverse_for_clear(adt_tree_node_type* node, const adt_tree_deallocate_func deallocate)
{
    if(node == NULL) return;

    adt_tree_postorder_traverse_for_clear(node->left_, deallocate);
    adt_tree_postorder_traverse_for_clear(node->right_, deallocate);

    deallocate(node->element_.first);
    deallocate(node->element_.second);
    deallocate(node);
}

void
adt_tree_insert(adt_tree* tree, const adt_tree_pair_type pair)
{
    adt_tree_node_type* node = (adt_tree_node_type*)tree->allocate_(sizeof(adt_tree_node_type));

    {
        /** Do deep copy of element */
        adt_tree_pair_type pair = 
        {
            .first  = (adt_tree_key_type*)tree->allocate_(tree->key_size_),
            .second = (adt_tree_value_type*)tree->allocate_(tree->value_size_)
        };

        tree->memcopy_(node->element_.first,    pair.first,     tree->key_size_);
        tree->memcopy_(node->element_.second,   pair.second,    tree->value_size_);
        tree->memcopy_(&node->element_,         &pair,          sizeof(adt_tree_pair_type));
    }

    node->left_     = NULL;
    node->right_    = NULL;
    node->parent_   = NULL;

    if(adt_tree_empty(tree))
        tree->root_ = node;
    else
    {
        adt_tree_node_type* n = tree->root_;
        adt_tree_node_type* p = NULL;
        do
        {
            p = n;

            if(tree->compare_(node->element_.first, n->element_.first) < 0)
                n = n->left_;
            else
                n = n->right_;
        }
        while(n != NULL);

        node->parent_ = p;
        if(tree->compare_(node->element_.first, p->element_.first) < 0)
            p->left_  = node;
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
        adt_tree_node_type* n = tree->root_;
        adt_tree_compare_type comp;
        while(n != NULL)
        {
            comp = tree->compare_(key, n->element_.first);
            if(comp == 0)
            {
                if(n->left_ != NULL && n->right_ != NULL) /* Node n has two children */
                {
                    /* Remove one child */
                    adt_tree_node_type* p = adt_tree_node_successor(tree, n); /* Successor has only one child */
                    adt_tree_element_swap(n, p, tree->memcopy_); /* So swap with successor */
                    n = p; /* Now node has one child */
                }

                if(n->left_ != NULL)
                {
                    if(n == tree->root_)
                        tree->root_         = n->left_;
                    else if(n->parent_->left_ == n)
                        n->parent_->left_   = n->left_;
                    else
                        n->parent_->right_  = n->left_;
                }
                else
                {   /*  Case one: node n has a right child  -- n->right_ is right child node
                        Case two: node n not have any child -- n->right_ is NULL */

                    if(n == tree->root_)
                        tree->root_         = n->right_;
                    else if(n->parent_->left_ == n)
                        n->parent_->left_   = n->right_;
                    else
                        n->parent_->right_  = n->right_;
                }
                --tree->size_;

                tree->deallocate_(n->element_.first);
                tree->deallocate_(n->element_.second);
                tree->deallocate_(n);
                break;
            }

            if(comp < 0)
                n = n->left_;
            else
                n = n->right_;
        }
    }
}

adt_tree_size_type
adt_tree_inorder_traverse_for_count(const adt_tree_node_type* node, const adt_tree_key_type key, const adt_tree_compare_func compare)
{
    if(node == NULL) return 0;

    adt_tree_compare_type comp = compare(node->element_.first, key);
    if(comp > 0) return 0;

    adt_tree_size_type count = 0;

    count += adt_tree_inorder_traverse_for_count(node->left_, key, compare);
    if(comp == 0) count += 1;
    count += adt_tree_inorder_traverse_for_count(node->right_, key, compare);

    return count;
}

adt_tree_pair_type*
adt_tree_find(adt_tree* tree, const adt_tree_key_type key)
{
    if(! adt_tree_empty(tree))
    {
        adt_tree_node_type* n = tree->root_;
        adt_tree_compare_type comp;
        while(n != NULL)
        {
            comp = tree->compare_(key, n->element_.first);

            if(comp == 0)
                return &n->element_;

            if(comp < 0)
                n = n->left_;
            else
                n = n->right_;
        }
    }

    return NULL;
}

void
adt_tree_traverse_levelorder(adt_tree* tree, void (* do_something)(adt_tree_pair_type))
{
    if(! adt_tree_empty(tree))
    {
        adt_tree_node_type* node = tree->root_;

        adt_queue* queue_pair = adt_queue_create(sizeof(adt_tree_pair_type));
        adt_queue_push(queue_pair, &node->element_);

        while(adt_queue_size(queue_pair) > 0)
        {
            adt_tree_pair_type pair = *(adt_tree_pair_type*)adt_queue_front(queue_pair);
            adt_queue_pop(queue_pair);

            do_something(pair);

            if(node->left_ != NULL) adt_queue_push(queue_pair, &node->left_->element_);
            if(node->right_ != NULL) adt_queue_push(queue_pair, &node->right_->element_);
        }
    }
}

void
adt_tree_traverse_inorder_using_node(adt_tree_node_type* node, void (* do_something)(adt_tree_pair_type))
{
    if(node == NULL) return;

    adt_tree_traverse_preorder_using_node(node->left_, do_something);
    do_something(node->element_);
    adt_tree_traverse_preorder_using_node(node->right_, do_something);
}

void
adt_tree_traverse_preorder_using_node(adt_tree_node_type* node, void (* do_something)(adt_tree_pair_type))
{
    if(node == NULL) return;

    do_something(node->element_);
    adt_tree_traverse_preorder_using_node(node->left_, do_something);
    adt_tree_traverse_preorder_using_node(node->right_, do_something);
}

void
adt_tree_traverse_postorder_using_node(adt_tree_node_type* node, void (* do_something)(adt_tree_pair_type))
{
    if(node == NULL) return;

    adt_tree_traverse_preorder_using_node(node->left_, do_something);
    adt_tree_traverse_preorder_using_node(node->right_, do_something);
    do_something(node->element_);
}

void
adt_tree_element_swap(adt_tree_node_type* first, adt_tree_node_type* second, const adt_tree_memcopy_func memcopy)
{
    adt_tree_pair_type temp = first->element_;
    memcopy(&first->element_,   &second->element_,  sizeof(adt_tree_pair_type));
    memcopy(&second->element_,  &temp,              sizeof(adt_tree_pair_type));
}

adt_tree_node_type*
adt_tree_node_successor(adt_tree* tree, adt_tree_node_type* node)
{
    if(node != NULL)
    {
        if(node->right_ != NULL)
        {
            node = node->right_;
            while(node->left_ != NULL)
                node = node->left_;
        }
        else
        {
            while(node->parent_ != NULL)
            {
                if(node == node->parent_->right_)
                {
                    node = node->parent_;
                    break;
                }

                node = node->parent_;
            }
        }
    }

    return node;
}

adt_tree_node_type*
adt_tree_node_predecessor(adt_tree* tree, adt_tree_node_type* node)
{
    if(node != NULL)
    {
        if(node->left_ != NULL)
        {
            node = node->left_;
            while(node->right_ != NULL)
                node = node->right_;
        }
        else
        {
            while(node->parent_ != NULL)
            {
                if(node == node->parent_->left_)
                {
                    node = node->parent_;
                    break;
                }

                node = node->parent_;
            }
        }
    }

    return node;
}

adt_tree_pair_type
adt_tree_make_pair(const adt_tree_key_type first, const adt_tree_value_type second)
{
    adt_tree_pair_type pair = { .first = first, .second = second };
    return pair;
}
