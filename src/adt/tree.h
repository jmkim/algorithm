/**
 *
 *  ADT: Tree
 *  Declaration
 *
 *  http://github.com/kdzlvaids/algorithm
 *
 */

#ifndef ALGORITHM_ADT_TREE_H_
#define ALGORITHM_ADT_TREE_H_ 1

#ifdef __cplusplus
extern "C"
{
#endif

typedef void*                   adt_tree_key_type;
typedef void*                   adt_tree_value_type;

struct adt_tree_pair
{
    adt_tree_key_type           first; /** Should not modified */
    adt_tree_value_type         second;
};

typedef struct  adt_tree_pair   adt_tree_pair_type;

typedef size_t                  adt_tree_size_type;
typedef int                     adt_tree_boolean_type;
#ifndef FALSE
#   define FALSE    0
#endif
#ifndef TRUE
#   define TRUE     1
#endif

struct adt_tree_node
{
            adt_tree_pair_type*         element_;
    struct  adt_tree_node*              left_;
    struct  adt_tree_node*              right_;
    struct  adt_tree_node*              parent_;
};

typedef struct  adt_tree_node           adt_tree_node_type;

typedef         int                     adt_tree_compare_type;
typedef         adt_tree_compare_type   (* adt_tree_compare_func)(adt_tree_key_type, adt_tree_key_type);

typedef         void*                   adt_tree_generic_ptr;
typedef         adt_tree_generic_ptr    (* adt_tree_allocate_func)(adt_tree_size_type);
typedef         void                    (* adt_tree_deallocate_func)(adt_tree_generic_ptr);
typedef         adt_tree_generic_ptr    (* adt_tree_memcopy_func)(adt_tree_generic_ptr, const adt_tree_generic_ptr, adt_tree_size_type);

struct adt_tree_adt_tree
{
            adt_tree_size_type          size_;
            adt_tree_node_type*         root_;

    const   adt_tree_size_type          key_size_;
    const   adt_tree_size_type          value_size_;

    const   adt_tree_compare_func       compare_;
    const   adt_tree_allocate_func      allocate_;
    const   adt_tree_deallocate_func    deallocate_;
    const   adt_tree_memcopy_func       memcopy_;
};

typedef struct  adt_tree_adt_tree       adt_tree;

#define adt_tree_empty(tree)                            (adt_tree_boolean_type)(tree->root_ == NULL)
#define adt_tree_size(tree)                             tree->size_

#define adt_tree_count(tree, key)                       adt_tree_inorder_traverse_for_count(tree->root_, key, tree->compare_)

#define adt_tree_traverse_inorder(tree, callback)       adt_tree_traverse_inorder_using_node(tree->root_, callback)
#define adt_tree_traverse_preorder(tree, callback)      adt_tree_traverse_preorder_using_node(tree->root_, callback)
#define adt_tree_traverse_postorder(tree, callback)     adt_tree_traverse_postorder_using_node(tree->root_, callback)

adt_tree*
adt_tree_create(const adt_tree_size_type key_size, const adt_tree_size_type value_size, const adt_tree_compare_func compare);

void
adt_tree_destroy(adt_tree* tree);

void
adt_tree_clear(adt_tree* tree);

void
adt_tree_postorder_traverse_for_clear(adt_tree_node_type* node, const adt_tree_deallocate_func deallocate);

void
adt_tree_insert(adt_tree* tree, const adt_tree_pair_type pair);

void
adt_tree_erase(adt_tree* tree, const adt_tree_key_type key);

adt_tree_size_type
adt_tree_inorder_traverse_for_count(const adt_tree_node_type* node, const adt_tree_key_type key, const adt_tree_compare_func compare);

adt_tree_pair_type*
adt_tree_find(adt_tree* tree, const adt_tree_key_type key);

void
adt_tree_traverse_levelorder(adt_tree* tree, void (* do_something)(adt_tree_pair_type*));

void
adt_tree_traverse_inorder_using_node(adt_tree_node_type* node, void (* do_something)(adt_tree_pair_type*));

void
adt_tree_traverse_preorder_using_node(adt_tree_node_type* node, void (* do_something)(adt_tree_pair_type*));

void
adt_tree_traverse_postorder_using_node(adt_tree_node_type* node, void (* do_something)(adt_tree_pair_type*));

void
adt_tree_element_swap(adt_tree_node_type* first, adt_tree_node_type* second);

adt_tree_node_type*
adt_tree_node_successor(adt_tree* tree, adt_tree_node_type* node);

adt_tree_node_type*
adt_tree_node_predecessor(adt_tree* tree, adt_tree_node_type* node);

adt_tree_pair_type
adt_tree_make_pair(const adt_tree_key_type first, const adt_tree_value_type second);

#ifdef __cplusplus
}
#endif

#endif /* ! ALGORITHM_ADT_TREE_H_ */
